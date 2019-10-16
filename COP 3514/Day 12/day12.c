#include <stdio.h>
#include <string.h>



int main(int argc, char *argv[]){
    /*
    String Library Functions
        string.h is required for these
        strcmp(str1,str2) compares two string adds their ascii values and tells you the difference
            zero means they're the same, or at least have the same characters
        size_t strelen(const char *s) tells the length of the string
        strcpy(str1,str2) copies str2 -> str1
        strcat(str1,str2) str1 = str1+str2

    Array of Strings

    Command-line arguments    
    */

//arrays of string
    char *planets[] = {"Mercury","Venus","Earth","Mars","Jupiter","Saturn","Uranus","Neptune"}; //string literal
    //can't be changed
    //char planets2[][8] = {"Mercury","Venus","Earth","Mars","Jupiter","Saturn","Uranus","Neptune","Pluto"}; //string variable
    //can be changed
    int i, isPlanet = 0;
    if(argc == 2){
        for(i = 0; i < 8; i++){
            if(strcmp(planets[i],argv[1]) == 0){
                isPlanet = 1;
                break;
            }
        }
        if(isPlanet == 1){
            printf("Is a planet");
        }else{
            printf("Is not a planet");
        }
    }


   return 0;
}