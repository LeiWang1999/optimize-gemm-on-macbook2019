#ifndef GEMM_OPTIMIZER_REGISTER_H
#define GEMM_OPTIMIZER_REGISTER_H

void mMultRegister1x4( int m, int n, int k, double *a, int lda,
                       double *b, int ldb,
                       double *c, int ldc );

#endif//GEMM_OPTIMIZER_REGISTER_H
