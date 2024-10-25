// matmult.c
#include <stdio.h>

void matmult(int n, int p, int q, double A[n][p], double B[p][q], double C[n][q]) 
{
    // initialise C to be zero, and than compute C
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < q; j++) 
        {
            C[i][j] = 0;
            for (int k = 0; k < p; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }
}
