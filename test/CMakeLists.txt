# Copyright (c) 2023 - 2025 Chair for Design Automation, TUM
# Copyright (c) 2025 Munich Quantum Software Company GmbH
# All rights reserved.
#
# SPDX-License-Identifier: MIT
#
# Licensed under the MIT License

package_add_test(${MQT_QUSAT_TARGET_NAME}_test ${MQT_QUSAT_TARGET_NAME} test_satencoder.cpp)
target_link_libraries(${MQT_QUSAT_TARGET_NAME}_test PRIVATE MQT::CoreAlgorithms)
