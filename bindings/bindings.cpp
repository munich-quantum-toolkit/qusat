/*
 * Copyright (c) 2023 - 2026 Chair for Design Automation, TUM
 * Copyright (c) 2025 - 2026 Munich Quantum Software Company GmbH
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 *
 * Licensed under the MIT License
 */

#include "SatEncoder.hpp"
#include "ir/QuantumComputation.hpp"

#include <nanobind/nanobind.h>
#include <nanobind/stl/string.h> // NOLINT(misc-include-cleaner)
#include <nanobind/stl/vector.h> // NOLINT(misc-include-cleaner)

namespace nl = nlohmann;
namespace nb = nanobind;
using namespace nb::literals;

nl::basic_json<> checkEquivalence(qc::QuantumComputation&         qc1,
                                  qc::QuantumComputation&         qc2,
                                  const std::vector<std::string>& inputs = {}) {
  nl::basic_json results{};
  SatEncoder     encoder{};
  try {
    results["equivalent"] = encoder.testEqual(qc1, qc2, inputs);
  } catch (std::exception const& e) {
    nb::print(
        ("Could not check equivalence: " + std::string(e.what())).c_str());
    return {};
  }
  results["statistics"] = encoder.getStats().to_json();
  return results;
}

std::string printDIMACS(qc::QuantumComputation& qc) {
  SatEncoder encoder{};
  return encoder.generateDIMACS(qc);
}

NB_MODULE(MQT_QUSAT_MODULE_NAME, m) {
  nb::module_::import_("mqt.core.ir");

  m.doc() =
      "Python interface for the MQT QuSAT quantum circuit satisfiability tool";

  m.def(
      "check_equivalence",
      [](qc::QuantumComputation& circ1, qc::QuantumComputation& circ2,
         const std::vector<std::string>& inputs) {
        const nb::module_ json  = nb::module_::import_("json");
        const nb::object  loads = json.attr("loads");
        return loads(checkEquivalence(circ1, circ2, inputs).dump());
      },
      "Check the equivalence of two clifford circuits for the given inputs. "
      "If no inputs are given, the all zero state is used as input.",
      "circ1"_a, "circ2"_a, "inputs"_a = std::vector<std::string>());

  m.def("generate_dimacs", &printDIMACS,
        "Output the DIMACS CNF representation from Z3 of the given circuit.",
        "circ"_a);
}
