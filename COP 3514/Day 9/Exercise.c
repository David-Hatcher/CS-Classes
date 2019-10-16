#include <stdio.h>


void find_two_largest(int a[], int n, int *largest, int *second_largest);


int main()
{
    int i, max, second_max, N;
    N = 10;
    int a[N];

    printf("Enter %d elements for the array: ", N);
    for(i = 0; i < N; i++){
        scanf("%d", &a[i]);
    }

    find_two_largest(a, N, &max, &second_max);
    printf("the largest value is: %d and the second largest is: %d\n",max, second_max);
    
    return 0;
}

void find_two_largest(int a[], int n, int *largest, int *second_largest){
    int i, temp;
    *largest = a[0];
    *second_largest = a[1];
    for(i = 0; i < n; i++){
        if(a[i] > *largest){
            temp = *largest;
            *largest = a[i];
            *second_largest = temp;
        }else if(a[i] > *second_largest){
            *second_largest = a[i];
        }
    }
}
