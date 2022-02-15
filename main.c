#include <stdio.h>
#include <stdlib.h>

#include "compare_matrices.h"
#include "copy_matrix.h"
#include "dclock.h"
#include "parameters.h"
#include "random_matrix.h"
#include "ref_mmult.h"

#include "baseline.h"
#include "loopunroll.h"

int main(int argc, char *argv[]) {
    int
            p,
            m, n, k,
            lda, ldb, ldc,
            rep;

    double
            dtime,
            dtime_best,
            gflops,
            diff;

    double
            *a,
            *b, *c, *cref, *cold;
    int methodId = 0;
    if (argc >= 2) methodId = atoi(argv[1]);
    // Determine if it is all numbers
    printf("MethodId: %d\n", methodId);

    printf("\n");

    for (p = PFIRST; p <= PLAST; p += PINC) {
        m = (M == -1 ? p : M);
        n = (N == -1 ? p : N);
        k = (K == -1 ? p : K);

        gflops = 2.0 * m * n * k * 1.0e-09;

        lda = (LDA == -1 ? m : LDA);
        ldb = (LDB == -1 ? k : LDB);
        ldc = (LDC == -1 ? m : LDC);

        /* Allocate space for the matrices */
        /* Note: I create an extra column in A to make sure that
           prefetching beyond the matrix does not cause a segfault */
        a = (double *) malloc(lda * (k + 1) * sizeof(double));
        b = (double *) malloc(ldb * n * sizeof(double));
        c = (double *) malloc(ldc * n * sizeof(double));
        cold = (double *) malloc(ldc * n * sizeof(double));
        cref = (double *) malloc(ldc * n * sizeof(double));

        /* Generate random matrices A, B, Cold */
        random_matrix(m, k, a, lda);
        random_matrix(k, n, b, ldb);
        random_matrix(m, n, cold, ldc);

        copy_matrix(m, n, cold, ldc, cref, ldc);

        /* Run the reference implementation so the answers can be compared */

        REF_MMult(m, n, k, a, lda, b, ldb, cref, ldc);

        /* Time the "optimized" implementation */
        for (rep = 0; rep < NREPEATS; rep++) {
            copy_matrix(m, n, cold, ldc, c, ldc);

            /* Time your implementation */
            dtime = dclock();
            switch (methodId) {
                case 0:
                    mMultBaseLine(m, n, k, a, lda, b, ldb, c, ldc);
                    break;
                case 1:
                    mMultLoopUnroll1x4(m, n, k, a, lda, b, ldb, c, ldc);
                    break;
                default:
                    break;
            }
            dtime = dclock() - dtime;

            if (rep == 0)
                dtime_best = dtime;
            else
                dtime_best = (dtime < dtime_best ? dtime : dtime_best);
        }

        diff = compare_matrices(m, n, c, ldc, cref, ldc);

        printf("%d %le %le \n", p, gflops / dtime_best, diff);
        fflush(stdout);

        free(a);
        free(b);
        free(c);
        free(cold);
        free(cref);
    }

    printf("\n");

    exit(0);
}