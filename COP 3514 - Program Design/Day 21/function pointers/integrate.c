#include <stdio.h>
#include <math.h>

#define PI 3.1415926

double integrate(double (*f)(double), double a, double b);

int main()
{
	double result;
	result = integrate(sin, 0.0, PI/2);
	printf("integrating sin function from 0.0 to PI/2, result is %.3lg\n", result);
	
	result = integrate(exp,  0.0, PI/2);
        printf("integrating exp function from 0.0 to PI/2, result is %.3lg\n", result);

	 result = integrate(sqrt,  0.0, PI/2);
        printf("integrating sqrt function from 0.0 to PI/2, result is %.3lg\n", result);



	return 0;

}

double integrate(double (*f)(double), double a, double b)
{
	double stepsize = 0.01;
	double integral = 0.0;
	double x;
	for(x = a + stepsize; x <=b; x += stepsize)
		integral += f(x)*stepsize;
	
	return integral;
}
