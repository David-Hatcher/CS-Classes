#include <stdio.h>
// double array_average(int a[], int n);
int main()
{
    /*TOPICS:
    Local vs Global variables
        Scope and duration
    Function prototype
    Pointers    
    */
    // int a[5]={5,8,24,68,78};
    // double average;
    // average = array_average(a,5);
    // printf("The average is : %.4f",average);
    /*Pointers
        Address of FIRST byte,

    1. Declare pointer variable
    */
    int i = 0;
    int *ptr;
    ptr = &i;

    printf("i value = %d, i address = %p\n",i,ptr);
    //2. Indirect operator  (To change the value you musthave the *)
    *ptr = 78;// same as i = 78   *ptr is an alias of i 
    printf("i value = %d, i address = %p",i,ptr);
    

    return 0;
}

// double array_average(int arr[], int n){
//     int i, sum = 0; 
//     double average;
//     for(i = 0; i < n; i++){
//         sum += arr[i];
//     }
//     average = (double)sum/n;
//     return average;
// }
