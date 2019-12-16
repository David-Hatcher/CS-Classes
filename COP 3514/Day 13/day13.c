#include <stdio.h>



int main()
{

    /*
    File Input Output
    Streams
        any input or output source, keyboard, monitor, files
        Buffer(a large array)
            speeds up data acquisition for reading file
            once file read is done, buffer is flushed
        fopen - opens file creates array
        fopen(char* filename, char* opentype)
        opentype = r,w,a
            read, write, append. write and append aren't required to exist
            write will overwrite 
            append adds to end
        fclose - closes file, flushes buffer 
        FILE - structure       
    */
    FILE *pFile,*wFile;
    pFile = fopen("hello_world.txt","r");
    if(pFile == NULL){
        printf("Error opening file");
        return 1;
    }
    wFile = fopen("not_hello_world.txt","w");
    if(wFile == NULL){
        printf("Error opening file");
    return 1;
    }

    /*
    The NULL pointer
    */
    //int *p = NULL;

    /*fgets()

    reads next line from a text file
    */
    char sentence[1001];
    while(fgets(sentence,1001,pFile) != NULL){
        printf("%s\n",sentence);
        fputs(sentence,wFile);
    }


    fclose(wFile);
    fclose(pFile);
    return 0;
}
