//
// Created by 王磊 on 2022/2/14.
//

#include "random_matrix.h"

#include <stdlib.h>

#define A(i, j) a[(j) *lda + (i)]

void random_matrix(int m, int n, double *a, int lda) {
    int i, j;
    for (j = 0; j < n; j++)
        for (i = 0; i < m; i++)
            /* drand48 - return a random double number in the range between [0.0, 1.0) */
            A(i, j) = 2.0 * drand48() - 1.0;
}