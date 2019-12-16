#include <stdio.h>
#include <string.h>

#define MAXWORDLEN 101
#define MAXNAMELEN 101
#define MAXWORDS 1000
/*David Hatcher
MW 9:30-10:45
This program allows a user to enter a file name
it will then take that file name read all the text out of that file
extract only the first letter from each word
then place those letters in another file with the same name but 
with ".dcf" added to the end

*/

void extract(char words[][MAXWORDLEN], int num_words, char *result);
int readFile(char const *fileName, char words[][MAXWORDLEN]);
void writeFile(const char *fileName,char *wordToWrite);

int main(){
    printf("Enter the file name:");
    char fileName[MAXNAMELEN];
    scanf("%s",fileName);
    char words[MAXWORDS][MAXWORDLEN];
    int numberOfWords = readFile(fileName,words);
    if(numberOfWords > 0){
        char secretString[MAXWORDS];
        extract(words,numberOfWords,secretString);
        writeFile(fileName,secretString);
    }else{
        printf("Nothing found in file.");
    }
    return 0;
}
/*extract function takes in an array of strings a number of words 
in that string and a point to another string. It will then take the 
first character from every string in the array and place that character
into the value at the string pointer
*/
void extract(char words[][MAXWORDLEN], int num_words, char *result){
    char *ch;
    int i;
    for(ch = result, i = 0; strcmp(words[i], "\0") != 0; i++, ch++){
        *ch = words[i][0];
    }
}
/*writeFile function takes in two strings a file name and a string to write
it then creates a new file using the original fineName variable and adds
".dcf" to the end of it then write the wordToWrite to that file, if it 
fails at creating the file it will output an error
*/
void writeFile(char const *fileName,char *wordToWrite){
    char fileNameNew[MAXNAMELEN + 3];
    strcpy(fileNameNew,fileName);
    strcat(fileNameNew,".dcf");    
    FILE *fp = fopen(fileNameNew,"w");
    if(fp == NULL){
        printf("Error Writing File %s",fileNameNew);
        return;
    }else{
        printf("Output file name: %s",fileNameNew);
        fprintf(fp,"%s",wordToWrite);
    }
}
/*readFile function takes a file name and a string array
then reads all of the words out of that file and places each of them in
its own index in the string array, if it fails at finding the file it
will output an error
*/
int readFile(char const *fileName, char words[][MAXWORDLEN]){
    int i = -1;
    FILE *fp = fopen(fileName,"r");
    if(fp ==  NULL){
        printf("Error reading %s", fileName);
        return 0;
    }
    while(!feof(fp) && !ferror(fp)){
        fscanf(fp,"%s",words[++i]);
    }
    return i;
}



