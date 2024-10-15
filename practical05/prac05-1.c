#include <stdio.h>

// compute Fibonacci series
// input: F_n-2, F_n-1
// output: F_n-1, F_n
void fibonacci(int fn_2, int fn_1, int *p_fn_1, int *p_fn)  
{
    *p_fn = fn_2 + fn_1; 
    *p_fn_1 = fn_1;  
}

int main(void)
{
    int n; 
    int a = 0, b = 1;               // initialize a = F_0 = 0, b = F_1 = 1

    scanf("%d", &n);                // enter the value n

    printf("%d %d ", a, b);         
    for (int i=2; i<=n; i++)
    {
        fibonacci(a, b, &a, &b);    // update the values of a and b,
                                    // which is equivalent to shifting one position to the right in the Fibonacci series
        printf("%d ", b); 
    }
    printf("\n"); 

    return 0; 
}
