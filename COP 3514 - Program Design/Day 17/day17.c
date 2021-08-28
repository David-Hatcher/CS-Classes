#include <stdio.h>
#include <stdlib.h>
//  ---------
//  |       |
//  |       |
//  |       |
//  |       |
//  ---------
//  instruction
//  memory
//  ---------
//  |       |
//  |       |   static memory allocation
//  |       |
//  |       |
//  ---------
//  data
//  memory
//  ---------
//  |       |
//  |       | dynamic memory allocation
//  |       |
//  |       |
//  ---------
//  heap memory
//
//  malloc - allocates a block of memory but doesn't initialize it
//  calloc allocates a block of memory and clears it
//  realloc resizes a previously allocated block of memory
//

int main(){
    int n;
    printf("Entersize of the array: ");
    scaf("%d",&n);

    //variable-sized array
    int *a;
    a = malloc(n*sizeof(int));
    if(a == NULL){
        prinft("Memory allocation failed");
        return 0;
    }
    int i;
    printf("Enter %d array elements: ",n);
    for(i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }
    return 1;
}