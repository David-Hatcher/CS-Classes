#include <stdio.h>
#define N 10

//int find_largest(int arr[], int n);

int main()
{
    /*
    Functions
    return
    function call
    function declarations
    array arguments
        Arrays are passed by reference
        single items are passed by value
    recursive function
    
    */
    //find largest

    // int i, index_largest;
    // int a[N];

    // printf("Enter %d elements for the array: ",N);
    // for(i = 0;i < N; i++){
    //     scanf("%d",&a[i]);
    // }
    // index_largest = find_largest(a,N);
    // printf("The largest value is: %d at index %d\n",a[index_largest],index_largest);
    printf("Give a number to find factorial:");
    printf("The factorial of this number is");

    return 0;
}

// int find_largest(int arr[], int n){
//     int i, max_index = 0;
//     for(i = 1;i < n; i++){
//         max_index = (arr[i] > arr[max_index]) ? i : max_index;
//     }
//     return max_index;
// }

int fact(int n){
    if(n <= 1){
        return 1;
    }else{
        return n * fact(n-1);
    }
}

int power(int x, int n){
    if(n == 0){
        return 1;
    }else{
        return x * power(x,n-1);
    }
}

int 
