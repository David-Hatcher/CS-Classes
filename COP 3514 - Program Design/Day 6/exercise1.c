#include <stdio.h>
#define alphaSize 26

int main(){
    int i, isSameFlag;
    int alpha[alphaSize] = {0};
    //int alphaB[alphaSize] = {0};

    printf("Please enter first word:");
    char ch = getchar();
    while(ch != '\n'){
        int a = ch - 'a';
        alpha[a]++;
        ch = getchar();
    }    

    // printf("Please enter second word:");
    // ch = getchar();
    // while(ch != '\n'){
    //     int a = ch - 'a';
    //     alphaB[a]++;
    //     ch = getchar();
    // }

    // isSameFlag = 1;
    // for(i = 0; i < alphaSize; i++){
    //     if(alpha[i] != alphaB[i]){
    //         isSameFlag = 0;
    //     }
    // }
    // if(isSameFlag){
    //     printf("The words are anagrams.");
    // }else{
    //     printf("The words are not anagrams.");
    // }

    printf("Please enter second word:");
    ch = getchar();
    while(ch != '\n'){
        int a = ch - 'a';
        alpha[a]--;
        ch = getchar();
    }

    isSameFlag = 1;
    for(i = 0; i < alphaSize; i++){
        if(alpha[i] != 0){
            isSameFlag = 0;
        }
    }
    if(isSameFlag){
        printf("The words are anagrams.");
    }else{
        printf("The words are not anagrams.");
    }



    return 0;
}