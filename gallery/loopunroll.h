#ifndef GEMM_OPTIMIZER_LOOPUNROLL_H
#define GEMM_OPTIMIZER_LOOPUNROLL_H

void mMultLoopUnroll1x4( int m, int n, int k, double *a, int lda,
                         double *b, int ldb,
                         double *c, int ldc );

void mMultLoopUnroll4x4(int m, int n, int k, double *a, int lda,
                        double *b, int ldb,
                        double *c, int ldc);

#endif//GEMM_OPTIMIZER_LOOPUNROLL_H
