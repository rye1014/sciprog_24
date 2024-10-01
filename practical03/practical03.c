#include <stdio.h>
#include <math.h>
#define pi acos(-1)  // define the constant pi as the result of arccosine of -1

double f(double x)  // define the function f(x) as tan(x)
{
    return tan(x); 
}

int main()
{
    double a = 0.0;         // upper bound
    double b = pi/3;        // lower bound
    int n = 12;             // 11 equidistant point, so n = 12
    double area = 0.0; 
    double h = (b - a) / n; // the width of each subinterval

    // area = (b-a)(f(x0)+2f(x1)+...+2f(xn-1)+f(n)) / 2n
    area += f(a);               // f(x0)
    for (int i=1; i<n; i++)
    {
        double xi = a + i * h;  // 2 * f(xi)
        area += 2 * f(xi); 
    }
    area += f(b);               // f(xn)
    area = (area * h) / 2;      

    printf("By Trapezodial rule:  %.4f\n", area);       // result calculating using the Trapezodial rule
    printf("Actual result log(2): %.4f\n", log(2));     // actual result of the question

    return 0; 
}