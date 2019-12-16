#include <stdio.h>

int is_digit_or_character(char c);
int main(int argc, char const *argv[])
{
    char x = '3';
    printf("%d",is_digit_or_character(x));
    return 0;
}
int is_digit_or_character(char c){
    if((c >= 'A' && c <='Z') || (c >= 'a' && c <='z')){
        return 1;
    }else{
        return 0;
    }
}
