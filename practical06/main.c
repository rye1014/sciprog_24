// main.c
#include <stdio.h>

void matmult(int n, int p, int q, double A[n][p], double B[p][q], double C[n][q]);

int main() 
{
    //declare the variables
    int n = 5, p = 3, q = 4;
    double A[n][p], B[p][q], C[n][q];

    // initialise A_ij as i + j
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < p; j++)
            A[i][j] = i + j;
    }

    // initialise B_ij as i - j
    for (int i = 0; i < p; i++) 
    {
        for (int j = 0; j < q; j++) 
            B[i][j] = i - j;
    }

    // compute C
    matmult(n, p, q, A, B, C);

    // print three matrices
    printf("Matrix A: \n");
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < p; j++) 
            printf("%.2lf ", A[i][j]);
        printf("\n");
    }
    printf("\n");

    printf("Matrix B: \n");
    for (int i = 0; i < p; i++) 
    {
        for (int j = 0; j < q; j++) 
            printf("%.2lf ", B[i][j]);
        printf("\n");
    }
    printf("\n");

    printf("Matrix C: \n");
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < q; j++) 
            printf("%.2lf ", C[i][j]);
        printf("\n");
    }

    return 0;
}
