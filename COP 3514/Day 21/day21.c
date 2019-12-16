#include <stdio.h>
#include <math.h>
#define PI 3.1415

/* * * * * * * * * * * * 
* Function Pointers

qsort       array       elements #    Element size  function pointer   ( )
void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *))
*
*/
double integrate( double (*f)(double), double a, double b);
int main(){
    double result = integrate(sin, 0.0, PI/2);
    printf("%lf",result);

    return 0;
}

double integrate( double (*f)(double), double a, double b){
    double stepsize = 0.01;
    double integral = 0;
    double x;
    for(x = a + stepsize; x <= b;x += stepsize){
        integral +=(*f)(a)*stepsize;
    }
    return integral;
}