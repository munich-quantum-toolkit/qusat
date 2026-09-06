/*
 * Copyright (c) 2023 - 2026 Chair for Design Automation, TUM
 * Copyright (c) 2025 - 2026 Munich Quantum Software Company GmbH
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 *
 * Licensed under the MIT License
 */

#pragma once

#include "ir/Definitions.hpp"

#include <cstddef>

namespace qc {
class QuantumComputation;
} // namespace qc

namespace qusat::detail {
/**
 * @brief Create a random Clifford circuit for the SAT encoder tests.
 * @param nq Number of qubits.
 * @param depth Circuit depth.
 * @param seed Seed for the random-number generator.
 * @return The generated circuit.
 */
[[nodiscard]] auto createRandomCliffordCircuit(qc::Qubit nq, std::size_t depth,
                                               std::size_t seed)
    -> qc::QuantumComputation;
} // namespace qusat::detail
