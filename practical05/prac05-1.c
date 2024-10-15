#include <stdio.h>

void fibonacci(int fn_2, int fn_1, int *p_fn_1, int *p_fn)
{
    *p_fn = fn_2 + fn_1; 
    *p_fn_1 = fn_1;  
}


int main(void)
{
    int n; 
    int a = 0, b = 1; 

    scanf("%d", &n); 

    printf("%d %d ", a, b); 
    for (int i=2; i<=n; i++)
    {
        fibonacci(a, b, &a, &b); 
        printf("%d ", b); 

    }

    return 0; 
}
