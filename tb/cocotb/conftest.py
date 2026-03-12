from __future__ import annotations

import sys
from pathlib import Path


TB_DIR = Path(__file__).resolve().parent

if str(TB_DIR) not in sys.path:
    sys.path.insert(0, str(TB_DIR))
