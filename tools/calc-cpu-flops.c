#include "cpufp_kernel_x86.h"
#include "smtl.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>

#define _AVX512F_
#define _AVX_
#define _FMA_
#define _SSE_

#ifdef _AVX512F_
#define AVX512F_FP32_COMP (0x20000000L * 320)
#define AVX512F_FP64_COMP (0x20000000L * 160)

static void thread_func_avx512_fp32(void *params)
{
	cpufp_kernel_x86_avx512f_fp32();
}

static void thread_func_avx512_fp64(void *params)
{
	cpufp_kernel_x86_avx512f_fp64();
}

#ifdef _AVX512_VNNI_
#define AVX512_VNNI_INT8_COMP (0x20000000L * 1280)
static void thread_func_avx512_8b(void *params)
{
	cpufp_kernel_x86_avx512_vnni_8b();
}
#endif

void cpufp_x86_avx512(int num_threads)
{
	int i;
    clock_t startTime,endTime;
	double time_used, perf;

	smtl_handle sh;
	smtl_init(&sh, num_threads);

#ifdef _AVX512_VNNI_
	// warm up
	for (i = 0; i < num_threads; i++)
	{
		smtl_add_task(sh, thread_func_avx512_8b, NULL);
	}
	smtl_begin_tasks(sh);
	smtl_wait_tasks_finished(sh);

	startTime = clock();
	for (i = 0; i < num_threads; i++)
	{
		smtl_add_task(sh, thread_func_avx512_8b, NULL);
	}
	smtl_begin_tasks(sh);
	smtl_wait_tasks_finished(sh);
	endTime = clock();

	time_used = (double)(endTime - startTime) / CLOCKS_PER_SEC;
	perf = AVX512_VNNI_INT8_COMP * num_threads / time_used * 1e-9;
	printf("avx512_vnni int8 perf: %.4lf gops.\n", perf);
#endif

	// warm up
	for (i = 0; i < num_threads; i++)
	{
		smtl_add_task(sh, thread_func_avx512_fp32, NULL);
	}
	smtl_begin_tasks(sh);
	smtl_wait_tasks_finished(sh);

	startTime = clock();
	for (i = 0; i < num_threads; i++)
	{
		smtl_add_task(sh, thread_func_avx512_fp32, NULL);
	}
	smtl_begin_tasks(sh);
	smtl_wait_tasks_finished(sh);
    endTime = clock();
	time_used = (double)(endTime - startTime) / CLOCKS_PER_SEC;
	perf = AVX512F_FP32_COMP * num_threads / time_used * 1e-9;
	printf("avx512f fp32 perf: %.4lf gflops.\n", perf);

	// warm up
	for (i = 0; i < num_threads; i++)
	{
		smtl_add_task(sh, thread_func_avx512_fp64, NULL);
	}
	smtl_begin_tasks(sh);
	smtl_wait_tasks_finished(sh);

    startTime = clock();
	for (i = 0; i < num_threads; i++)
	{
		smtl_add_task(sh, thread_func_avx512_fp64, NULL);
	}
	smtl_begin_tasks(sh);
	smtl_wait_tasks_finished(sh);
	endTime = clock();

	time_used = (double)(endTime - startTime) / CLOCKS_PER_SEC;
	perf = AVX512F_FP64_COMP * num_threads / time_used * 1e-9;
	printf("avx512f fp64 perf: %.4lf gflops.\n", perf);

	smtl_fini(sh);
}
#endif

#ifdef _FMA_
#define FMA_FP32_COMP (0x40000000L * 160)
#define FMA_FP64_COMP (0x40000000L * 80)

static void thread_func_fma_fp32(void *params)
{
	cpufp_kernel_x86_fma_fp32();
}

static void thread_func_fma_fp64(void *params)
{
	cpufp_kernel_x86_fma_fp64();
}

void cpufp_x86_fma(int num_threads)
{
	int i;
	clock_t startTime,endTime;
	double time_used, perf;

	smtl_handle sh;
	smtl_init(&sh, num_threads);

	// warm up
	for (i = 0; i < num_threads; i++)
	{
		smtl_add_task(sh, thread_func_fma_fp32, NULL);
	}
	smtl_begin_tasks(sh);
	smtl_wait_tasks_finished(sh);

	startTime = clock();
	for (i = 0; i < num_threads; i++)
	{
		smtl_add_task(sh, thread_func_fma_fp32, NULL);
	}
	smtl_begin_tasks(sh);
	smtl_wait_tasks_finished(sh);
	endTime = clock();

	time_used = (double)(endTime - startTime) / CLOCKS_PER_SEC;
	perf = FMA_FP32_COMP * num_threads / time_used * 1e-9;
	printf("fma fp32 perf: %.4lf gflops.\n", perf);

	// warm up
	for (i = 0; i < num_threads; i++)
	{
		smtl_add_task(sh, thread_func_fma_fp64, NULL);
	}
	smtl_begin_tasks(sh);
	smtl_wait_tasks_finished(sh);

	startTime = clock();
	for (i = 0; i < num_threads; i++)
	{
		smtl_add_task(sh, thread_func_fma_fp64, NULL);
	}
	smtl_begin_tasks(sh);
	smtl_wait_tasks_finished(sh);
	endTime = clock();

	time_used = (double)(endTime - startTime) / CLOCKS_PER_SEC;
	perf = FMA_FP64_COMP * num_threads / time_used * 1e-9;
	printf("fma fp64 perf: %.4lf gflops.\n", perf);

	smtl_fini(sh);
}
#endif

#ifdef _AVX_
#define AVX_FP32_COMP (0x40000000L * 96)
#define AVX_FP64_COMP (0x40000000L * 48)

static void thread_func_avx_fp32(void *params)
{
	cpufp_kernel_x86_avx_fp32();
}

static void thread_func_avx_fp64(void *params)
{
	cpufp_kernel_x86_avx_fp64();
}

void cpufp_x86_avx(int num_threads)
{
	int i;
	clock_t startTime,endTime;
	double time_used, perf;

    smtl_handle sh;
	smtl_init(&sh, num_threads);

	// warm up
	for (i = 0; i < num_threads; i++)
	{
		smtl_add_task(sh, thread_func_avx_fp32, NULL);
	}
	smtl_begin_tasks(sh);
	smtl_wait_tasks_finished(sh);

	startTime = clock();
	for (i = 0; i < num_threads; i++)
	{
		smtl_add_task(sh, thread_func_avx_fp32, NULL);
	}
	smtl_begin_tasks(sh);
	smtl_wait_tasks_finished(sh);
	endTime = clock();

	time_used = (double)(endTime - startTime) / CLOCKS_PER_SEC;
	perf = AVX_FP32_COMP * num_threads / time_used * 1e-9;
	printf("avx fp32 perf: %.4lf gflops.\n", perf);

	// warm up
	for (i = 0; i < num_threads; i++)
	{
		smtl_add_task(sh, thread_func_avx_fp64, NULL);
	}
	smtl_begin_tasks(sh);
	smtl_wait_tasks_finished(sh);

	startTime = clock();
	for (i = 0; i < num_threads; i++)
	{
		smtl_add_task(sh, thread_func_avx_fp64, NULL);
	}
	smtl_begin_tasks(sh);
	smtl_wait_tasks_finished(sh);
	endTime = clock();

	time_used = (double)(endTime - startTime) / CLOCKS_PER_SEC;
	perf = AVX_FP64_COMP * num_threads / time_used * 1e-9;
	printf("avx fp64 perf: %.4lf gflops.\n", perf);

	smtl_fini(sh);
}
#endif

#ifdef _SSE_
#define SSE_FP32_COMP (0x30000000L * 64)
#define SSE_FP64_COMP (0x30000000L * 32)

static void thread_func_sse_fp32(void *params)
{
	cpufp_kernel_x86_sse_fp32();
}

static void thread_func_sse_fp64(void *params)
{
	cpufp_kernel_x86_sse_fp64();
}

void cpufp_x86_sse(int num_threads)
{
	int i;
	clock_t startTime,endTime;
	double time_used, perf;

    smtl_handle sh;
	smtl_init(&sh, num_threads);

	// warm up
	for (i = 0; i < num_threads; i++)
	{
		smtl_add_task(sh, thread_func_sse_fp32, NULL);
	}
	smtl_begin_tasks(sh);
	smtl_wait_tasks_finished(sh);

	startTime = clock();
	for (i = 0; i < num_threads; i++)
	{
		smtl_add_task(sh, thread_func_sse_fp32, NULL);
	}
	smtl_begin_tasks(sh);
	smtl_wait_tasks_finished(sh);
	endTime = clock();

	time_used = (double)(endTime - startTime) / CLOCKS_PER_SEC;
	perf = SSE_FP32_COMP * num_threads / time_used * 1e-9;
	printf("sse fp32 perf: %.4lf gflops.\n", perf);

	// warm up
	for (i = 0; i < num_threads; i++)
	{
		smtl_add_task(sh, thread_func_sse_fp64, NULL);
	}
	smtl_begin_tasks(sh);
	smtl_wait_tasks_finished(sh);

	startTime = clock();
	for (i = 0; i < num_threads; i++)
	{
		smtl_add_task(sh, thread_func_sse_fp64, NULL);
	}
	smtl_begin_tasks(sh);
	smtl_wait_tasks_finished(sh);
	endTime = clock();

	time_used = (double)(endTime - startTime) / CLOCKS_PER_SEC;
	perf = SSE_FP64_COMP * num_threads / time_used * 1e-9;
	printf("sse fp64 perf: %.4lf gflops.\n", perf);

	smtl_fini(sh);
}
#endif


#define BIT_TEST(bit_map, pos) (((bit_map) & (0x1 << (pos))) ? 1 : 0)
#define SET_FEAT(feat_mask) { feat |= (feat_mask); }

typedef enum
{
    _CPUID_X86_SSE_         = 0x1,
    _CPUID_X86_AVX_         = 0x2,
    _CPUID_X86_FMA_         = 0x4,
    _CPUID_X86_AVX512F_     = 0x8,
    _CPUID_X86_AVX512_VNNI_ = 0x10,
} cpuid_x86_feature_t;

struct cpuid_t
{
    unsigned int ieax;
    unsigned int iecx;
    unsigned int eax;
    unsigned int ebx;
    unsigned int ecx;
    unsigned int edx;
};

static unsigned int feat;

static void cpuid_x86_exec(struct cpuid_t *cpuid)
{
    asm volatile("pushq %%rbx\n"
                 "cpuid\n"
                 "movl %%ebx, %1\n"
                 "popq %%rbx\n"
    : "=a"(cpuid->eax), "=r"(cpuid->ebx), "=c"(cpuid->ecx), "=d"(cpuid->edx)
    : "a"(cpuid->ieax), "c"(cpuid->iecx)
    : "cc");
}

static void cpuid_x86_init()
{
    struct cpuid_t cpuid;

    feat = 0;

    cpuid.ieax = 0x1;
    cpuid.iecx = 0x0;
    cpuid_x86_exec(&cpuid);

    if (BIT_TEST(cpuid.edx, 25))
    {
        SET_FEAT(_CPUID_X86_SSE_);
    }
    if (BIT_TEST(cpuid.ecx, 28))
    {
        SET_FEAT(_CPUID_X86_AVX_);
    }
    if (BIT_TEST(cpuid.ecx, 12))
    {
        SET_FEAT(_CPUID_X86_FMA_);
    }

    cpuid.ieax = 0x7;
    cpuid.iecx = 0x0;
    cpuid_x86_exec(&cpuid);

    if (BIT_TEST(cpuid.ebx, 16))
    {
        SET_FEAT(_CPUID_X86_AVX512F_);
    }
    if (BIT_TEST(cpuid.ecx, 11))
    {
        SET_FEAT(_CPUID_X86_AVX512_VNNI_);
    }
}

unsigned int cpuid_x86_support(cpuid_x86_feature_t feature)
{
    return feat & feature;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s num_threads.\n", argv[0]);
        exit(0);
    }
    int num_threads = 2;
    // Determine if it is all numbers
    if (strspn(argv[1], "0123456789") == strlen(argv[1]))
        num_threads = atoi(argv[1]);
    printf("Thread(s): %d\n", num_threads);

    cpuid_x86_init();


    if (cpuid_x86_support(_CPUID_X86_AVX512F_))
    {
        cpufp_x86_avx512(num_threads);
    }
    if (cpuid_x86_support(_CPUID_X86_AVX512_VNNI_))
    {
        ;
    }
    if (cpuid_x86_support(_CPUID_X86_FMA_))
    {
        cpufp_x86_fma(num_threads);
    }
    if (cpuid_x86_support(_CPUID_X86_AVX_))
    {
        cpufp_x86_avx(num_threads);
    }
    if (cpuid_x86_support(_CPUID_X86_SSE_))
    {
        cpufp_x86_sse(num_threads);
    }

    return 0;
}

