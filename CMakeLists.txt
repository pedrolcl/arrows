# Copyright (c) 2023-2024, Pedro López-Cabanillas
# SPDX-License-Identifier: BSD-3-Clause

cmake_minimum_required(VERSION 3.14)

project(Arrows
    VERSION 0.1
    LANGUAGES CXX
)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Gui Widgets)

add_library(ArrowsLib OBJECT
    arrowitem.h
    arrowitem.cpp
)

add_executable(ArrowsGalore
  arrowsgalore.cpp
  $<TARGET_OBJECTS:ArrowsLib>
)

add_executable(TwoArrows
  twoarrows.cpp
  $<TARGET_OBJECTS:ArrowsLib>
)

target_link_libraries(ArrowsLib
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Gui
    Qt${QT_VERSION_MAJOR}::Widgets
)

target_link_libraries(ArrowsGalore
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Gui
    Qt${QT_VERSION_MAJOR}::Widgets
)

target_link_libraries(TwoArrows
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Gui
    Qt${QT_VERSION_MAJOR}::Widgets
)

include(GNUInstallDirs)
install(TARGETS ArrowsGalore TwoArrows
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
