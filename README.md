# 工程构建流程:

xdma到pc驱动链路打通 -> 上位机程序设计
        |__CSI到DDR链路调通
        |__awr2243雷达配置调通

## 关键节点:
        1、xdma到pc驱动链路打通
        2、CSI到ddr数据链路调通
        3、awr2243雷达配置调通，雷达正常出流
        4、雷达数据csi到axi-stream，由于数据不是正常的视频流，不能直接套用视频格式。数据拆包组包写到ddr
        5、xdma读取到雷达数据（重要节点）
        6、ddr环形缓冲区设计
        7、上位机设计及优化
        8、测试及验证

# 工程具体实现:

## 系统框图

```bash
                           +----------------------+
                           |   AWR2243 Config     |
FPGA SPI Master ->         |   SPI Driver/State   |
                           +----------+-----------+
                                      |
                                      v
+----------------------------------------------------------------------------------+
|                                       FPGA                                       |
|                                                                                  |
|  AWR2243 CSI2 TX                                                                 |
|        |                                                                         |
|        v                                                                         |
|  +-------------+   +-------------------+   +-------------------+                 |
|  | MIPI D-PHY  |-> | CSI2 RX Subsystem |-> | CSI Packet Decoder|                 |
|  +-------------+   +-------------------+   +---------+---------+                 |
|                                                      |                           |
|                                                      v                           |
|                                           +----------------------+               |
|                                           | AXI Radar Payload    |               |
|                                           | Chirp/Sample/IQ      |               |
|                                           +----------+-----------+               |
|                                                      |                           |
|                                                      v                           |
|                                           +----------------------+               |
|                                           | DDR Ring Buffer Mgr  |               |
|                                           | 写指针/读指针/描述符    |               |
|                                           +----------+-----------+               |
|                                                      |                           |
|                                                      v                           |
|                                                 +---------+                      |
|                                                 |  XDMA   |---- PCIe ---- TB ----> Host
|                                                 +---------+                      |
+----------------------------------------------------------------------------------+
```

# 数据格式分析
## AWR2243: MIPI 数据格式:  RAW12 (不确定，也有可能是undefine，但是每一个sample是12bit)

数据结构:

```bash
Payload
│ 
├─ RX0 header  NULL(bit 11-5) CH Chirp Profile(bit 5-1) Channel Number(bit 1-0)   Chirp Num (bit 11-0)
├─ RX1 header  NULL(bit 11-5) CH Chirp Profile(bit 5-1) Channel Number(bit 1-0)   Chirp Num (bit 11-0)
├─ RX2 header  NULL(bit 11-5) CH Chirp Profile(bit 5-1) Channel Number(bit 1-0)   Chirp Num (bit 11-0)
├─ RX3 header  NULL(bit 11-5) CH Chirp Profile(bit 5-1) Channel Number(bit 1-0)   Chirp Num (bit 11-0)
│
├─ sample0
│    ├─ RX0_I(12bit)
│    ├─ RX0_Q
│    ├─ RX1_I
│    ├─ RX1_Q
│    ├─ RX2_I
│    ├─ RX2_Q
│    ├─ RX3_I
│    └─ RX3_Q
│
├─ sample1
│
├─ ...
│
├─ sampleN
│
└─ CQ data（64bit）
```

每一个payload大小: header + sample + CQ = 4x2x12bit + 4x2x12bit x Ns + 6x12bit = 96bit + 96x1024bit + 72bit = 12309 B

> 其中Ns最大为1024，储存的时候应该按照1024的来算，空的sample应该填零

对齐到64B 
paload 大小应该为: 12352B = 193 x 64B
应该padding的字节: 43B
传输效率：12309 / 12352 x 100% = 99.65%

## DDR内存布局：

```bash
DDR
│
├─slot0  addr = base + 0*12352
│        payload
│        padding
│
├─slot1  addr = base + 1*12352
│
├─slot2  addr = base + 2*12352
│
└─slot3
```

# 传输速率分析：
CSI2:           awr2243最大传输速率：4 x 22.5Msps x (12x2)bit = 2160 Mbps (2.1Gbps)
AXI:            256 bit @ 250 MHz = 64Gbps
DDR4:           2400MT/s x 32bit = 76.8 Gbps
PCIe Gen3 x 8:  8GT/s x 128b/130b x 8lane = 63Gbps
雷电4:           理论40Gbps 实际是22Gbps(另外的是给视频的，暂时用不了)

# 分析结果: 抛去awr2243本身的瓶颈，这套系统理论上的速率会受到雷电4接口的影响
# 采集系统理论最大速度: 22Gbps
