#include <stdio.h>

void max_min(int *a, int n, int *max, int *min);

int main(void)
{

	int a[8];

	int max_a;
  int min_a;

	int i;
	printf("please enter 8 numbers:\n");
	for(i=0;i<8;i++)
	   scanf("%d", &a[i]);

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

		





