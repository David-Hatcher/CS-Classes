#include <stdio.h>

void count_diff(int *a1, int *a2, int n, int *num_diff); 
void howManyDifferent(int *num_diff);

/*
David Hatcher
Project 4

This program will alow the user to input 2 arrays with the same size. Once enter the
program will determine how many differences there are between the two and then output
that information to the user.

*/

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
    int *a1, *a2;
    a1 = arr1;
    a2 = arr2;
    int arrayDiff = 0;
    int *num_diff;
    num_diff = &arrayDiff;

    count_diff(a1,a2,n,num_diff);
    howManyDifferent(num_diff);
    return 0;
}
//count_diff funtion will count the difference between both arrays given by pointers then
//output that differences to the point given for num_diff 
void count_diff(int *a1, int *a2, int n, int *num_diff){
    int *p,*q; 
    int count = 0;
    for(p = a1, q = a2; p < a1 + n; p++,q++){
        if(*p != *q){
            count++;
        }
    }
    *num_diff = count;
}
//howManyDifferent function determines the output for the user based on the differences between both
//arrays and and outputs that the screen
void howManyDifferent(int *num_diff){
    printf("\nOutput: ");
    if(*num_diff == 0){
        printf("The arrays are identical");
    }else{
        printf("The arrays are different by %d elements",*num_diff);
    }
}
