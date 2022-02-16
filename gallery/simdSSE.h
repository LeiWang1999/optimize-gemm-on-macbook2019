#ifndef GEMM_OPTIMIZER_SIMDSSE_H
#define GEMM_OPTIMIZER_SIMDSSE_H
void mMultSIMDSSE4x4(int m, int n, int k, double *a, int lda,
                     double *b, int ldb,
                     double *c, int ldc);
#endif//GEMM_OPTIMIZER_SIMDSSE_H
