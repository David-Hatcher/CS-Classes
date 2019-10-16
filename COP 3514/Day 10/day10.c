#include <stdio.h>

double array_average(int *arr, int n);
int main()
{
    /*
    Pointers and Arrays
                             p1           p2            p4      p3
    int a[5] = {11000,11001,11002,11003,11004,11005,..,11021,.,11024};

    actually four bytes apart from each other
    
    p2 = p1 + 2
    p4 = p3 - 3

    p3 - p2 = difference between them = 22

    3 forms of pointer arithmetic
    *Adding an integer to a pointer
    *subtracting an integer from apointer
    *subtracting one point from another pointer, from same array.
       
    */

   int arr[5] = {1,2,3,4,5};
   int *p;
   p = arr;
   printf("%f",array_average(p,5));

   /*
   Combining * and ++ operators

   a[i++] = j;

    p = &a[i];
    *p++ = 35;
    the increment is on the pointer, not the value;
    so it makes p = 35 then p++ not 35++;


   */




    return 0;
}
double array_average(int *arr, int n){

    int sum = 0;
    double average;
    int *p;

    for(p = arr;p < (arr + n);p++){
        sum += *p;
    }
    average = (double)sum/n;
    return average;
}
