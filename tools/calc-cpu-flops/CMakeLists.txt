if (${TARGET_PROCESSOR} MATCHES "X86" AND ${ARCH_X86_AVX})
    list (APPEND _CPU_COMPILER_OPTIONS "-mfma")
    list (APPEND _CPU_COMPILER_OPTIONS "-mf16c")
endif()

file(GLOB LIB_SOURCE "${CMAKE_CURRENT_LIST_DIR}/cpufp_kernel_*.s")

add_library(fpkernel ${LIB_SOURCE})
find_package(Threads)
add_executable(calc-cpu-flops calc-cpu-flops.c smtl.c)
target_link_libraries(calc-cpu-flops fpkernel ${CMAKE_THREAD_LIBS_INIT})