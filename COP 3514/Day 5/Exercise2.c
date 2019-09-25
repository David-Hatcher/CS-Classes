#include <stdio.h>
#include <ctype.h>

int main()
{
    char newChar;


    printf("Enter A Message: ");
    char ch = getchar();
    while(ch != '\n'){
        if(ch != toupper(ch) && isalpha(ch)){
         newChar = ch - 'a' + 'A';
        }else{
            newChar = ch;
        }
        printf("%c", newChar);
        ch = getchar();
    }
    return 0;
}