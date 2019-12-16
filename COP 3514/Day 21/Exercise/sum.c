#include <stdio.h>

int sum (int (*f) (int), int start, int end);
int fact(int n);
int square(int n);
int cube(int n);

int main()
{
	int start, end;
	printf("Enter start value: ");	
	scanf("%d", &start);
	printf("Enter end value: ");
	scanf("%d", &end);
	
	int result = sum(cube,start,end);
	printf("\n\nSum of cube = %d\n\n",result);

	result = sum(fact,start,end);
	printf("Sum of fact = %d\n\n",result);

	result = sum(square,start,end);
	printf("Sum of square = %d\n\n",result);
	//display the sum of factorials, the sum of squares, 
	//and the sum of cubes from start to end





	return 0;
}

int sum (int (*f) (int), int start, int end)
{
	int sum = 0;
	int x;
	for(x = start; x <= end; x++){
		sum += (*f)(x);
	}
	return sum;
}

int fact(int n)
{
  if (n <= 1) 
    return 1;
  else
    return n * fact(n - 1);
}

int square(int n)
{
  return n*n;
}

int cube(int n)
{
  return n*n*n;
}
