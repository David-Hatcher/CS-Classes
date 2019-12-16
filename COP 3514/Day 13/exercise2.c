#include <stdio.h>
#include <string.h>

int appendFileLine(char *filename,char *linePuts);

int main()
{
    int i;
    char *fileName = "planets.txt";
    char *planets[] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune", "Pluto"};
    for(i = 0;i < 9; i++){
        if(appendFileLine(fileName,planets[i]) == 0){
            printf("writing went wrong on %s", planets[i]);
        }        
    }
    
    return 0;
}

int appendFileLine(char *filename,char *linePuts){
    FILE *wf;
    wf = fopen(filename,"a");
    if(wf == NULL){
        return 0;
    }
    fputs(linePuts,wf);
    fputs("\n",wf);
    fclose(wf);
    return 1;
}