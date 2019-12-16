#include <stdio.h>


int main(int argc, char *argv[])
{

    char color[31];
    int weight, count, total_count = 0;

    if(argc == 2){
        FILE *fp = fopen(argv[1],"r");
        if(fp ==  NULL){
            printf("Error opening file");
            return 1;
        }    

        while(!feof(fp) && !ferror(fp)){
            if(fscanf(fp,"%d%s%d",&weight,color,&count) == 3){
                printf("%d\t%s\t%d\n",weight,color,count);
                total_count += count;
            }
        }

        printf("There are %d number of dumbbells", total_count);
    }else{
        printf("Please enter a file name on run");
    }
    

    /*int fscanf(FILE* pFile, char* format string(same as scanf),....variables to read)

    */
    return 0;
}
