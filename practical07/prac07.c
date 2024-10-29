#include <stdio.h>
#include <stdlib.h>         // include malloc function

double* allocatearray(int size)                 // dynamically allocates an array of doubles
{
    return (double*)malloc(size * sizeof(double)); 
}

void fillwithones(double* array, int size)      // fill with taylor series
{
    array[0] = 1.0; 
    for (int i=1; i<size; i++)
        array[i] = array[i-1] * 1.0 / (double)i;  // 1 + x + x^2/2! + x^3/3! + ... where x = 1
}

void printarray(double* array, int size)        // print the array
{
    for (int i=0; i<size; i++)
        printf("%lf ", array[i]);
    printf("\n"); 
}

void freearray(double* array)                   // frees the allocated memory                   
{
    free(array); 
}


int main() 
{
    int n = 10;              
    scanf("%d", &n);         // input the order needed

    double* arr = allocatearray(n); // allocate memory for n elements
    fillwithones(arr, n);           // fill the array
    printarray(arr, n);             // print the array

    double e = 0; 
    for (int i=0; i<n; i++)         // compute the sum of the array
    {
        e += arr[i]; 
    }
    printf("e = %.10lf\n\n", e); 

    freearray(arr);                 // free the allocated memory


    printf("-----------------------------------------------------------\n\n"); 


    for (int n=1; n<=15; n++)       // repeat the above steps with n ranging from 1 to 15
    {
        printf("n = %d: \n", n); 

        double* arr = allocatearray(n); 
        fillwithones(arr, n); 
        printarray(arr, n); 

        double e = 0; 
        for (int i=0; i<n; i++)
        {
            e += arr[i]; 
        }
        printf("e = %.10lf\n\n", e); 

        freearray(arr); 
    }

    return 0; 
}