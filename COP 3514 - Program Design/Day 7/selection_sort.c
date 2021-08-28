
#include <stdio.h>
#define N 10

void selection_sort(int a[], int n);
int find_largest(int a[], int n);

int main(void)
{
  int i;
  int a[N];

  printf("Enter %d numbers to be sorted: ", N);
  for (i = 0; i < N; i++)
    scanf("%d", &a[i]);

  selection_sort(a, N);

  printf("In sorted order:");
  for (i = 0; i < N; i++)
    printf(" %d", a[i]);
  printf("\n");

  return 0;
}

void selection_sort(int a[], int n)
{

  int largest = 0, temp;
  largest = find_largest(a,n);
  temp = a[n-1];
  a[n-1] = a[largest];
  a[largest] = temp;
  if(n > 1){
    selection_sort(a,n-1);
  }
}

int find_largest(int arr[], int n){
    int i, max_index = 0;
    for(i = 1;i < n; i++){
        max_index = (arr[i] > arr[max_index]) ? i : max_index;
    }
    return max_index;
}

