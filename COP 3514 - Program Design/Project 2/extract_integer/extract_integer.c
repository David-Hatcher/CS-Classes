/*David Hatcher
This program allows the user to input a string containing any characters,
it will then print out all the integers in the order they were input
*/
#include <stdio.h>

int main()
{

    printf("Input:");
    char ch = getchar();
    printf("Output:");
    while(ch != '\n'){
        if(ch >= '0' && ch <= '9'){
            printf("%c",ch);
        }
        ch = getchar();
    }
    return 0;
}
