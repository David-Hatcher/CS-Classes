#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*This program will allow a user to enter an operand followed by two integers when
executed it will then perform that operation if it is mathimatically possible and output
the value. If it is not mathimatically possible it will inform the user.
*/

int multiply(int a, int b);
int divide(int a, int b);
int add(int a, int b);
int subtract(int a, int b);
int mathMe(const char *op, int a, int b);
int isMathable(const char *op, int b);
void convertNums(char *strs[], int numbers[], char *operator);

/*function main will run the function convertNums using the array of 
strings input at execution, to convert them to usable information
it then checks if a mathimatically operation is possible using
isMathable function. If an operation is possible it will run the 
function mathMe with the values given and output them to the user.
If an operation is not possible it will inform the user. 
*/
int main(int argc, char *argv[]){
    char operator[2];
    int numArr[2];
    if(argc == 4){
        convertNums(argv,numArr,operator);
        if(isMathable(operator,numArr[1]) == 1){
            int answer = mathMe(operator,numArr[0],numArr[1]);
            printf("Output: %d",answer);
        }else{
            printf("Invalid option. +, -, x, or / followed by two operands and second operand cannot be 0 in division");            
        }
    }

    return 0;
}
/*convertNums function takes in an array of strings, a point to an
array of integers and string pointer. It will take the first value of
that array, the operand, and put in the in string that was given. It will then take
the next two values of the array and apply them to the first and second indices
of the integer array
*/
void convertNums(char *strs[], int *numbers, char *operator){
    strcpy(operator,strcat(strs[1],"\0"));
    *numbers++ = atoi(strs[2]);
    *numbers = atoi(strs[3]);
}
/*multiply function will multiply two numbers*/
int multiply(int a, int b){
    return (int)a*b;
}
/*divide function will divide two numbers, truncates because it returns
and integer*/
int divide(int a, int b){
    return (int)a/b;
}
/*add function adds the second integer to the first*/
int add(int a, int b){
    return a+b;
}
/*subtract function subtracts the first integer given from the second*/
int subtract(int a, int b){
    return a-b;
}
/*isMathable function will take in a string and 1 integer. It then checks
if that string is the same as one of the possible operations. If it is it
will set the variable mathCanBeDone to 1, it then checks if the operation 
is division and the number is 0. If this is the case it will set mathCanBeDone
to 0. After it does this it returns mathCanBeDone. 
*/
int isMathable(const char *op, int b){
    char operations[][2] = {"x","-","/","+"};
    int i, mathCanBeDone = 0;
    for(i = 0; i < 4; i++){
        if(strcmp(operations[i],op) == 0){
            mathCanBeDone = 1;
            if(strcmp(op,"/") == 0 && b == 0){
                mathCanBeDone = 0;
            }
            break;
        }
    }
    return mathCanBeDone;    
}
/*function mathMe takes in a character string pointer(operand), and two integers
it then determines which mathimatically operation to perform.
*/
int mathMe(const char *op, int a, int b){
    if(strcmp(op,"x") == 0 || strcmp(op,"X") == 0){
        return multiply(a,b);
    }else if(strcmp(op,"/") == 0){
        return divide(a,b);
    }else if(strcmp(op,"+") == 0){
        return add(a,b);
    }else if(strcmp(op,"-") == 0){
        return subtract(a,b);
    }
    return 0;
}