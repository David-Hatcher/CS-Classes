#include <stdio.h>
#define N 50

void extract(char *str1, char *str2);
int read_line(char *str, int n);

int main()
{
    /* String Literals(constants) vs String Variables

    char *str = "hello"; this is a string literal
    char str[] = "hello"; string variable

    String
    input/output
    not a type in c, arrays of characters
    they always end with null character

    */
    printf("Input: \n");
    //char* str1 = "sdh2793ljd4"; //string literal
    char str1[N+1];
    char str2[N+1]; //string variables this can hold 50 characters because last place is null character \o
    int n = read_line(str1,N);
    extract(str1,str2);

    printf("Output: %s",str2);

    /*
    Reading Strings using scanf
    line i/o
    */


    return 0;
}

void extract(char *str1, char *str2){
    char *p;
    char *q = str2;
    for(p = str1; *p != '\0'; p++){
        if(*p >= '0' && *p <= '9'){
            *q++ = *p;
        }
    }
    *q = '\0';
}

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
