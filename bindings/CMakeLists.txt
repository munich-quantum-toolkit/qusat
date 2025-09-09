# Copyright (c) 2023 - 2025 Chair for Design Automation, TUM
# Copyright (c) 2025 Munich Quantum Software Company GmbH
# All rights reserved.
#
# SPDX-License-Identifier: MIT
#
# Licensed under the MIT License

if(APPLE)
  set(BASEPOINT @loader_path)
else()
  set(BASEPOINT $ORIGIN)
endif()
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
list(
  APPEND
  CMAKE_INSTALL_RPATH
  ${BASEPOINT}
  ${BASEPOINT}/${CMAKE_INSTALL_LIBDIR}
  ${BASEPOINT}/../core/${CMAKE_INSTALL_LIBDIR}
  ${BASEPOINT}/../core/lib
  ${BASEPOINT}/../core/lib64
  ${BASEPOINT}/../../core/${CMAKE_INSTALL_LIBDIR}
  ${BASEPOINT}/../../core/lib
  ${BASEPOINT}/../../core/lib64)

add_mqt_python_binding(
  QUSAT
  ${MQT_QUSAT_TARGET_NAME}-bindings
  bindings.cpp
  MODULE_NAME
  pyqusat
  INSTALL_DIR
  .
  LINK_LIBS
  MQT::QuSAT
  pybind11_json)
target_compile_definitions(${MQT_QUSAT_TARGET_NAME}-bindings PRIVATE Z3_FOUND)

# Install directive for scikit-build-core
install(
  TARGETS ${MQT_QUSAT_TARGET_NAME}-bindings
  DESTINATION .
  COMPONENT ${MQT_QUSAT_TARGET_NAME}_Python)
