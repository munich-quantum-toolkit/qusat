# Copyright (c) 2023 - 2026 Chair for Design Automation, TUM
# Copyright (c) 2025 - 2026 Munich Quantum Software Company GmbH
# All rights reserved.
#
# SPDX-License-Identifier: MIT
#
# Licensed under the MIT License

"""Python interface for the MQT QuSAT quantum circuit satisfiability tool."""

from collections.abc import Sequence
from typing import Any

import mqt.core.ir

def check_equivalence(
    circ1: mqt.core.ir.QuantumComputation, circ2: mqt.core.ir.QuantumComputation, inputs: Sequence[str] | None = None
) -> dict[str, Any]:
    """Check the equivalence of two clifford circuits for the given inputs. If no inputs are given, the all zero state is used as input."""

def generate_dimacs(circ: mqt.core.ir.QuantumComputation) -> str:
    """Output the DIMACS CNF representation from Z3 of the given circuit."""
