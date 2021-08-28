#include <stdio.h>
#define N 100
/*This program allows the user to enter a string, it will then parse that
string and try to find a range of characters in the form of [x-y]
if it finds that it will output the same string but replace the range
with the characters in that range (Ex. [d-f]ine will output define).
If there is no range it will tell the user that there is no range
in the input
*/
int replace(char *s1, char *s2);
int read_line(char *str, int n);

int main(){
    printf("Enter the input:");
    char str1[N+1];
    char str2[N+1];
    read_line(str1,N);
    int rangeBool = replace(str1,str2);
    if(rangeBool == 1){ 
        printf("Output: %s",str2);
    }else{
        printf("There is no range in the input");
    }
    return 0;
}
/*replace function takes two string pointers and places each character
from the first to the second. If it finds a '[' character this indicates that there is a range
if there is a range it will replace the range with each character in that range of 
characters then return 1. Otherwise it will return 0
*/
int replace(char *s1, char *s2){
    char *p,*q;
    q = s2;
    int rangeBool = 0;
    for(p = s1; p < s1 + N + 1;p++){
        if(*p == '[' && *(p+4) == ']'){
            char startingChar = *(p+1);
            char endingChar = *(p+3);
            p = p + 4; 
            do{
                *q++ = startingChar++;
            }while(startingChar != endingChar + 1);
            
            rangeBool = 1;
        }else{
            *q++ = *p;
        }
    }
    return rangeBool;
}
/*read_line function is used to read each character of an input and add it 
to a the value at a char* pointer
*/
int read_line(char *str, int n){
    int ch, i = 0;
    while((ch = getchar()) != '\n'){
        if(i < n){
            *str++ = ch;
            i++;
        }
    }
    *str = '\0';
    return i;    
}

