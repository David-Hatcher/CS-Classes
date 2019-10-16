#include <stdio.h>

void max_min(int *a, int n, int *max, int *min);

int main(void)
{

	int a[]={6, 8, 14, 5, 9, 23, 45, 65};
	

	int max_a;
        int min_a;

	max_min(a, 8, &max_a, &min_a);
	printf("max is %d and min is %d\n", max_a, min_a);

	return 0;
	
}
void max_min(int *a, int n, int *max, int *min)
{
  int *p;
  *max = *min = *a;
  for (p = a; p < a + n; p++) {
    if (*p > *max)
      *max = *p;
    else if (*p < *min)
      *min = *p;
  }
}

		





