#include <stdio.h>
/*
David Hatcher
Project 4

This program takes a user input of any number of digit.
After that it encrypts them by adding 6 to each digit then taking
the modulo 10 of that number and assigning that to the new
digit in that place. Once that is done it takes the first and last
digits and swaps them.
*/

void encrypt(int *a, int *b, int n);
void swap(int *p, int *q);

int main()
{
    int n,i;
    printf("Enter the number of digits of the input number: ");
    scanf("%d",&n);
    int arrA[n], arrB[n];
    printf("Enter the number: ");
    for(i = 0; i < n; i++){
        scanf("%1d",&arrA[i]);
    }
    encrypt(&arrA[0],&arrB[0],n);
    printf("\nOutput: ");
    for(i = 0; i < n; i++){
        printf("%d",arrB[i]);
    }
    return 0;
}
/*encrypt function takes the digit at each place in one array, a, adds 6,
then takes the modulo ten of the value and places that into
the same place in a second array, b. Once it has placed all the
encrypted numbers in a array b, it will then call the swap
function on the first and last values of array b.
*/
void encrypt(int *a, int *b, int n){
    int *p,*q;
    for(p = a, q = b; p < a + n; p++,q++){
        *q = (*p + 6)%10;
    }
    swap(b,b+(n-1));
}
/*swap function takes two integer pointers as input then swaps each
of their values with the value of the other. p = original q, q = original p.
*/
void swap(int *p, int *q){
    int temp = *p;
    *p = *q;
    *q = temp;
}

