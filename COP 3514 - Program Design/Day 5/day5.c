#include <stdio.h>

int main()
{
    /*
    char ch1 = 'A';
    char ch2 = 't';
    char ch3 = ' ';
    char ch4 = '\n';
    i = 'a';

   Check if an input is valid password 
    */
    char ch;
    int is_valid = 1;
    int count = 0;

    ch = getchar();
    while(ch !='\n'){
        if(!((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))){
            is_valid = 0;    
        }
        ch = getchar();
        count++;
    }
    if(count > 8){
        is_valid =0;
    }
    if(is_valid){
        printf("Valid");
    }else{
        printf("Invalid");
    }



    return 0;
}
