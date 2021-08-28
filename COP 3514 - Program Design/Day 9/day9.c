#include <stdio.h>
#define N 10

void max_min(int arr[], int n, int *max, int *min);
int *max(int *a, int *b);

int main()
{
    /*
    


    */
    int b[N], i, big = 0, small = 0;
    printf("Enter 10 Numbers: ");
    for(i = 0; i < N; i++){
        scanf("%d",&b[N]);
    }

    int *max, *min;
    max = &big;
    min = &small;



    max_min(b,N,max,min);

    int *p;
    i = 4;
    int j = 9;
    p = max(&i, &j);



    return 0;
}

void max_min(int arr[], int n, int *max, int *min){
    int i;
    *max = *min = *arr;
    int *p;
    for(p = arr;p < arr + n; i++){
        if(*p > *max){
            *min = *max;
            *max = *p;
        }else if(*p < *min){
            *min = *p;
        }
    }
}
int * max(int *a, int *b){
    if (*a > *b){
        return a;
    }else{
        return b;
    }
}
int *find_middle(int a[], int n){
    return &a[n/2];
}
