#ifndef GEMM_OPTIMIZER_ARRAYPACK_H
#define GEMM_OPTIMIZER_ARRAYPACK_H
void mMultArrayPack4x4(int m, int n, int k, double *a, int lda,
                         double *b, int ldb,
                         double *c, int ldc);
#endif//GEMM_OPTIMIZER_ARRAYPACK_H
