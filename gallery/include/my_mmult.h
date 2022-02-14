#ifndef GEMM_OPTIMIZER_MY_MMULT_H
#define GEMM_OPTIMIZER_MY_MMULT_H

void MY_MMult( int m, int n, int k, double *a, int lda,
               double *b, int ldb,
               double *c, int ldc );

#endif//GEMM_OPTIMIZER_MY_MMULT_H
