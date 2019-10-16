#include <stdio.h>

int main(){
    int num=25;
    int *p;
    p =&num;

    *p = 36;
    printf("%d",num);
}