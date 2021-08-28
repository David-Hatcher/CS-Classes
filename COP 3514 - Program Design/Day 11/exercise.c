#include <stdio.h>
#define STR_LEN 50

int read_line(char *str, int n);
int read_line2(char *str, int n);


int main(){
    int num_chars;
    char sen[STR_LEN + 1];
    printf("Enter a sentence: ");
    num_chars = read_line(sen,STR_LEN);
    printf("You entered: %s, it has %d characters", sen, num_chars);
}

int read_line(char *str, int n){
    int ch, i = 0,leading_space = 1;

    while((ch = getchar()) != '\n'){
        if(ch == ' ' && leading_space == 1){
            continue;
        }else
        {
            leading_space = 0;
            if(i < n){
                *str++ = ch;
                i++;
            }
        }
    }
    *str = '\0';
    return i;    
}

int read_line2(char *str, int n){
    int ch, i = 0;

    while((ch = getchar()) == ' ');

    while(ch != '\n'){
        if(i < n){
            *str++ = ch;
            i++;
        }
        ch = getchar();
    }
    *str = '\0';
    return i;    
}