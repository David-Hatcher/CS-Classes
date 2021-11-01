#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include "safe-math.h"

//function to clear the buffer of extra data
void clearBuffer() {
    char c;
    while((c = getchar()) != '\n');
}

int main(void){
    long A, B;
    char input1[128], input2[128];

    //Read A
    if(fgets(input1, 128, stdin) == NULL) {
        A = 0; 
    }
    //Checking input1 to see if we can find a newline character
    //if no newline is found then there is extra data in the buffer before the second entry
    int newLineFlag = 0, i;
    for(i = 0; i < 128; i++){
        if(input1[i] == '\n'){
            newLineFlag = 1;
            break;
        }
    }
    //if there is extra data in the stdin buffer then clear it out up until, and include the newline character
    if(!newLineFlag) {
        clearBuffer();
    }
    //Read B
    if(fgets(input2, 128, stdin) == NULL) {
        B = 0; 
    }
    
    A = strtol(input1, NULL, 10);
    if(errno) {
        printf("%s and %s cannot be multiplied as longs.", input1, input2);
        return 0;
    }
    B = strtol(input2, NULL, 10);
    if(errno) {
        printf("%ld and %s cannot be multiplied as longs.", A, input2);
        return 0;
    }
    
    //Check smallest primative first to see if they can fit in character space
    if (A <= CHAR_MAX && A >= CHAR_MIN && B <= CHAR_MAX && B >= CHAR_MIN) {
        char charMultResult;
        psnip_safe_bool succ = psnip_safe_char_mul(&charMultResult, A, B);
        
        if (succ) {
            printf("%ld and %ld can be successfully multipled as chars, producing product %hhd.", A, B, charMultResult);
            return 0;
        }

    }
    
    //Check next smallest primiative to see if they can fit in int space
    if(A <= INT_MAX && A >= INT_MIN && B >= INT_MIN && B >= INT_MIN) {
        //Now, see if the multiplication overflows
        int intMultResult;
        psnip_safe_bool success = psnip_safe_int_mul(&intMultResult, A, B);
        
        if(success)
        {
            printf("%ld and %ld can be successfully multiplied as chars, producing product %d.", A, B, intMultResult);
            return 0;
        }
    }
    
    //Check next smallest primative to see if they can fit in long space
    if (A <= LONG_MAX && A >= LONG_MIN && B <= LONG_MAX && B >= LONG_MIN) {
        long longMultResult;
        psnip_safe_bool succ = psnip_safe_long_mul(&longMultResult, A, B);
        
        if (succ) {
            printf("%ld and %ld can be successfully multipled as longs, producing product %ld.", A, B, longMultResult);
            return 0;
        }

    }
    
    //The multiplication cannot fit in long space thus will overflow, exit
    printf("%ld and %ld cannot be multiplied as longs.", A, B);
    return 0;
}
