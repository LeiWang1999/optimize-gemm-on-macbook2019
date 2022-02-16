#ifndef GEMM_OPTIMIZER_INNERKERNEL_H
#define GEMM_OPTIMIZER_INNERKERNEL_H
void mMultInnerKernel(int m, int n, int k, double *a, int lda,
                       double *b, int ldb,
                       double *c, int ldc);
#endif//GEMM_OPTIMIZER_INNERKERNEL_H
