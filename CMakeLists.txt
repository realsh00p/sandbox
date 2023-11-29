cmake_minimum_required(VERSION "3.18.4")

project(sandbox)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_CXX_COMPILER_LAUNCHER "ccache")
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

find_package(benchmark REQUIRED)
add_subdirectory(src/visitor_vs_virtual)
