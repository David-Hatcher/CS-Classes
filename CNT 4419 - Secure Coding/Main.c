#include <stdio.h>
#include "bstrlib.h"

//Removes the newline character at the end of the bstring, if one is present.
void rmNewLine(bstring a) {
    if(a->data[a->slen - 1] == '\n') {
        bdelete(a, a->slen - 1, 1); 
    }
}

int main(void) {
    bstring s = bgets ((bNgetc) fgetc, stdin, '\n');
    if(s) {  //Check that a string was read
        rmNewLine(s);
        printf("The input string is: %s\n", s->data);
        printf("The length of this string is: %d\n", s->slen);
    }
    else {
        puts("Please provide input in the Input tab.");
        return -1;
    }
    int dest = bdestroy(s);
    if(dest == BSTR_ERR) {
        return -1;
    }
    
    bstring s1 = bgets((bNgetc) fgetc, stdin, '\n');
    bstring s2 = bgets((bNgetc) fgetc, stdin, '\n');
    
    if(s1 && s2) {
        rmNewLine(s1),rmNewLine(s2);
        printf("The concatenation of '%s' and '%s' is: ", s1->data, s2->data);
        int concat = bconcat(s1,s2);
        if(concat == BSTR_OK) {
            printf("%s\n", s1->data);
        }
        else {
            puts("Error concatenating strings.");
            return -1;
        }
    }
    else {
        puts("Please provide input in the Input tab.");
        return -1;
    }
    int dest2 = bdestroy(s1);
    int dest3 = bdestroy(s2);
    if(dest2 == BSTR_ERR || dest3 == BSTR_ERR) {
        return -1;
    }
    
    s1 = bgets((bNgetc) fgetc, stdin, '\n');
    s2 = bgets((bNgetc) fgetc, stdin, '\n');
    
    if(s1 && s2) {
        rmNewLine(s1),rmNewLine(s2);
        if(binstr(s1, 0, s2) != BSTR_ERR) {
            printf("Finally, '%s' is a substring of '%s'", s2->data, s1->data);
        }
        else {
            printf("Finally, '%s' is not a substring of '%s'", s2->data, s1->data);
        }
    }
    else {
        puts("Please provide input in the Input tab.");
        return -1;
    }
    int dest4 = bdestroy(s1);
    int dest5 = bdestroy(s2);
    if(dest4 == BSTR_ERR || dest5 == BSTR_ERR) {
        return -1;
    }
    return 0;
}