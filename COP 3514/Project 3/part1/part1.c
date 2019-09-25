#include <stdio.h>

int search(int a[], int n, int value);

int main()
{
    int n, i, searchVal;
    printf("Enter the length of the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for(i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the value for searching: ");
    scanf("%d",&searchVal);

    int indexOfValue = search(arr,n,searchVal);

    printf("Output: %d", indexOfValue);
    
    return 0;
}

int search(int a[], int n, int value){
    int i;
    for(i = 0; i < n; i++){
        if(a[i] == value){
            return i;
        }
    }
    return -1;
}

