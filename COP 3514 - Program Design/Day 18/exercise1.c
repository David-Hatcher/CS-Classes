#include <stdio.h>

int count_n(struct node *list, int n){
    int count = 0;
    struct node *p;
    for(p = list; p != NULL; p = p->next){
        if(p->value == n){
            count++;
        }
    }
    return count;
}

struct node{
    int value;
    struct node *next;
};


int main(){
    return 0;
}