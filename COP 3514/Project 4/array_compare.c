#include <stdio.h>

void count_diff(int *a1, int *a2, int n, int *num_diff); 
void howManyDifferent(int *num_diff);

int main()
{
    int n, i;
    printf("Enter the length of the arrays: ");
    scanf("%d",&n);
    printf("Enter the elements of the first array: ");
    int arr1[n];
    int *ptr1 = arr1;
    for(i = 0; i < n; i++){
        scanf("%d",ptr1++);
    }
    printf("Enter the elements of the second array: ");
    int arr2[n];
    int *ptr2 = arr2;
    for(i = 0; i < n; i++){
        scanf("%d",ptr2++);
    }
    int *a1 = arr1;
    int *a2 = arr2;
    int arrayDiff = 0;
    int *num_diff = &arrayDiff;

    count_diff(a1,a2,n,num_diff);
    howManyDifferent(num_diff);
    return 0;
}

void count_diff(int *a1, int *a2, int n, int *num_diff){
    int i;

    for(i = 0; i < n; i++){
        if(*a1++ == *a2++){
            num_diff++;
        }
    }
}

void howManyDifferent(int *num_diff){
    if(*num_diff == 0){
        printf("The arrays are identical");
    }else{
        printf("The arrays are different by %d elements",*num_diff);
    }
}
