#include <stdio.h>
#include <math.h>
#define pi acos(-1)     // define the constant pi as the result of arccosine of -1
double tan_x[13];       // define an global array to store tan(x)

double f(double x)  // define the function f(x) as tan(x)
{
    return tan(x); 
}

float degtorad(float arg)   // define the function to convert degrees to radians
{
    return (pi * arg) / 180.0; 
}

int main()
{
    double a = 0.0;                     // upper bound
    double b_deg = 60;        
    double b_rad = degtorad(b_deg);     // lower bound 
    int n = 12;                         // 11 equidistant point, so n = 12
    double area = 0.0; 
    double h = (b_rad - a) / n;         // the width of each subinterval
    int index = 0;                      // index for global array tan_x

    // area = (b-a)(f(x0)+2f(x1)+...+2f(xn-1)+f(n)) / 2n
    area += f(a);               // f(x0)
    tan_x[index] = f(a); 
    index++; 

    for (int i=1; i<n; i++)
    {
        double xi = a + i * h;  // 2 * f(xi)
        area += 2 * f(xi); 
        tan_x[index] = f(xi); 
        index++; 
    }

    area += f(b_rad);               // f(xn)
    tan_x[index] = f(b_rad); 

    area = (area * h) / 2;          // compute the area

    printf("By Trapezodial rule:  %.4f\n", area);       // result calculating using the Trapezodial rule
    printf("Actual result log(2): %.4f\n", log(2));     // actual result of the question

    for (int i=0; i<sizeof(tan_x)/sizeof(double); i++)  // print out the tan(x)
    {
        printf("%.4f ", tan_x[i]); 
    }
    printf("\n"); 


    return 0; 
}