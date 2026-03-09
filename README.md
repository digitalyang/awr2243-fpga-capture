工程构建流程:xdma到pc驱动链路打通 -> 上位机程序设计
                  |__CSI到DDR链路调通
                  |__awr2243雷达配置调通

关键节点：1、xdma到pc驱动链路打通
        2、CSI到ddr数据链路调通
        3、awr2243雷达配置调通，雷达正常出流
        4、雷达数据csi到axi-stream，由于数据不是正常的视频流，不能直接套用视频格式。数据拆包组包写到ddr
        5、xdma读取到雷达数据（重要节点）
        6、ddr环形缓冲区设计
        7、上位机设计及优化
        8、测试及验证

工程具体实现：
系统框图
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
|                                           | Radar Payload Parser |               |
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

AWR2243: MIPI 数据格式:  RAW12 (不确定，也有可能是undefine，但是每一个sample是12bit)
数据结构:
Payload
│ 
├─ RX0 header  NULL(bit 11-5) CH Chirp Profile(bit 5-1) Channel Number(bit 1-0)   Chirp Num (bit 11-0)
├─ RX1 header  NULL(bit 11-5) CH Chirp Profile(bit 5-1) Channel Number(bit 1-0)   Chirp Num (bit 11-0)
├─ RX2 header  NULL(bit 11-5) CH Chirp Profile(bit 5-1) Channel Number(bit 1-0)   Chirp Num (bit 11-0)
├─ RX3 header  NULL(bit 11-5) CH Chirp Profile(bit 5-1) Channel Number(bit 1-0)   Chirp Num (bit 11-0)
│
├─ sample0
│    ├─ RX0_I
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
└─ CQ data