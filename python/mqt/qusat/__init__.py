# Copyright (c) 2023 - 2026 Chair for Design Automation, TUM
# Copyright (c) 2025 - 2026 Munich Quantum Software Company GmbH
# All rights reserved.
#
# SPDX-License-Identifier: MIT
#
# Licensed under the MIT License

"""MQT QuSAT library."""

from __future__ import annotations

import sys

if sys.platform == "win32":  # ruff: ignore[non-empty-init-module]
    import os
    import sysconfig
    from pathlib import Path

    def _dll_patch() -> None:
        """Add the DLL directory to the PATH."""
        site_packages = Path(sysconfig.get_paths()["purelib"])
        bin_dir = site_packages / "mqt" / "core" / "bin"
        os.add_dll_directory(str(bin_dir))

    _dll_patch()
    del _dll_patch

    if "Z3_ROOT" in os.environ:
        lib_path = Path(os.environ["Z3_ROOT"]) / "lib"
        if lib_path.exists():
            os.add_dll_directory(str(lib_path))
        bin_path = Path(os.environ["Z3_ROOT"]) / "bin"
        if bin_path.exists():
            os.add_dll_directory(str(bin_path))

from ._version import version as __version__
from .pyqusat import check_equivalence, generate_dimacs

__all__ = ["__version__", "check_equivalence", "generate_dimacs"]
