#include <stdio.h>

int main(int argc, char const *argv[])
{
    /*
    ARRAYS:
    initialization
    processsing
    two dimensional

    
    */

    //Swaps two elements of an array

    //read the size, elements of the array

    printf("Enter the size of the array:");

    int n, i, indexA, indexB;
    scanf("%d", &n);
    int arr[n];

    printf("Enter the %d elements of the array", n);



    for(i = 0; i < n ; i++){
        scanf("%d",&arr[i]);
    }
    printf("Printing Array: ");
    for(i = 0; i < n ; i++){
        printf("%d ", arr[i]);
    }

    printf("\nWhich indices would you like to swap?");

    scanf("%d %d", &indexA, &indexB);
    int temp = arr[indexB];
    arr[indexB] = arr[indexA];
    arr[indexA] = temp;

    printf("Printing modifed array: ");
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    /*
    int arr[10] = {0} = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    
    */

    return 0;
}
