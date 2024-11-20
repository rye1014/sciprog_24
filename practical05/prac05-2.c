#include <stdio.h>
#include <math.h> 
#include <float.h>

double maclaurin(double x, int n)       // compute the single element in Maclaurin series: (x^(2n+1)) / (2n+1)
{
    return (pow(x, 2.0 * n + 1.0)) / (2.0 * n + 1.0); 
}

double arctanh1(double x, double delta) // compute the arctanh by Maclaurin series
{
    int n = 0;
    double mac = DBL_MAX; 
    double sum = 0.0;  

    while (fabs(mac) >= delta)                // stop when the absolute value of element is smaller than delta
    {
        mac = maclaurin(x, n);          // update the element 
        sum += mac;                     // sum the Maclaurin series up
        n++; 
    }

    return sum; 
}


double arctanh2(double x)               // compute the arctanh by natural logarithms
{
    return (log(1.0 + x) - log(1.0 - x)) / 2.0;     
}


int main(void)
{
    double delta;               // declare a user-defined delta
    printf("Input a real positive number delta: \n"); 
    scanf("%lf", &delta); 

    double upper = 0.9, lower = -0.9, interval = 0.01;      // x in [-0.9, 0.9], sampled every 0.01
    int size = (upper - lower) / interval + 1;              // the total number of samples: 181

    double result1[size], result2[size];                    // declare two array to store the results for both methods

    for (int i=0; i<size; i++)                              // store them into arrays
    {
        result1[i] = arctanh1(lower + interval * i, delta); 
        result2[i] = arctanh2(lower + interval * i); 
    }

    printf(" x\t  result[1]\t  result[2]\t  diff\n"); 
    double diff; 
    for (int i=0; i<size; i++)                              // compare their differences
    {
        diff = fabs(result1[i] - result2[i]); 
        printf("%.2f    %.10f   %.10f   %.10f\n", lower + interval * i, result1[i], result2[i], diff); 
    }

    return 0; 
}