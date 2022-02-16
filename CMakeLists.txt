cmake_minimum_required(VERSION 3.19)
project(gemm_optimizer)

set(CMAKE_CXX_STANDARD 14)

# Enable Language which in use
enable_language(C CXX)
# Enable Support for ASM
enable_language(ASM)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_C_FLAGS "-O2 -msse3")

option(ARCH_X86_AVX     "Build AVX2 for x86"        ON)

# Do check list
include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/check.cmake")

add_subdirectory(tools)
add_subdirectory(gallery)
add_subdirectory(utils)

add_library(sse INTERFACE IMPORTED)

include_directories(${PROJECT_SOURCE_DIR}/gallery)

include_directories(${PROJECT_SOURCE_DIR}/utils)

add_executable(gemm_optimizer benchmark.c)

target_link_libraries(gemm_optimizer gallery_utils gallary_major)