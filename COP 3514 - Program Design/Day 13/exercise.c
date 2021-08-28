#include <stdio.h>

int countChars(char *line);
int countNonSpaces(char *line);

int main(int argc, char const *argv[])
{
    FILE *rf;
    int count = 0,countNonSpace = 0;
   
    rf = fopen("test.txt","r");

    if(rf == NULL){
        printf("Error reading file");
        return 1;
    }
    char buffer[1001];
    while(fgets(buffer,1001,rf) != NULL){
        count += countChars(buffer);
        countNonSpace += countNonSpaces(buffer);
    }
    printf("Char count = %d\nChar Count without spaces = %d",count,countNonSpace);
    fclose(rf);

    return 0;
}

int countChars(char *line){
    char *p;
    int count = 0;
    for(p = line;*p != '\0'; p++){
        count++;
    }
    return count;
}
int countNonSpaces(char *line){
    char *p;
    int count = 0;
    for(p = line;*p != '\0'; p++){
        if(*p != ' ' && *p != '\n'){
            count++;
        }
    }
    return count;
}