cmake_minimum_required(VERSION 3.19)
project(gemm_optimizer)

set(CMAKE_CXX_STANDARD 14)

# Enable Language which in use
enable_language(C CXX)
# Enable Support for ASM
enable_language(ASM)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

OPTION(ARCH_X86_AVX     "Build AVX2 for x86"        ON)

# Do check list
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/check.cmake")

add_subdirectory(tools)

add_executable(gemm_optimizer main.cpp)