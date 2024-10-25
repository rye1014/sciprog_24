#include <stdio.h>

int main()
{
    // define n, p, q
    int n = 5, p = 3, q = 4; 

    // declare three arrays of type double
    double A[n][p], B[p][q], C[n][q]; 
    
    // initialise C to zero
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<q; j++)
            C[i][j] = 0; 
    }

    // initialise A_ij = i + j
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<p; j++)
            A[i][j] = i + j; 
    }

    // initialise B_ij = i - j
    for (int i=0; i<p; i++)
    {
        for (int j=0; j<q; j++)
            B[i][j] = i - j; 
    }
    
    // compute C
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<q; j++)
        {
            for (int k=0; k<p; k++)
                C[i][j] += A[i][k] * B[k][j]; 
        }
    }

    // print out three arrays
    printf("Matrix A: \n"); 
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<p; j++)
            printf("%.2lf ", A[i][j]); 
        printf("\n"); 
    }
    printf("\n\n"); 

    printf("Matrix B: \n"); 
    for (int i=0; i<p; i++)
    {
        for (int j=0; j<q; j++)
            printf("%.2lf ", B[i][j]); 
        printf("\n"); 
    }
    printf("\n\n"); 

    printf("Matrix C: \n"); 
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<q; j++)
            printf("%.2lf ", C[i][j]); 
        printf("\n"); 
    }
    printf("\n\n"); 




    return 0; 
}