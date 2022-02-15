#ifndef GEMM_OPTIMIZER_REF_MMULT_H
#define GEMM_OPTIMIZER_REF_MMULT_H

void REF_MMult( int m, int n, int k, double *a, int lda,
                double *b, int ldb,
                double *c, int ldc );

#endif//GEMM_OPTIMIZER_REF_MMULT_H
