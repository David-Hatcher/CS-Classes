#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
LINKED LIST

    add(to beginning)
    search
    delete
    clear

*/
struct node{
    int value;
    struct node *next;
};

struct node *add_to_list(struct node *list, int n);
struct node *search_list(struct node *list, int n);
struct node *delete_from_list(struct node *list, int n);

int main(){


    struct node *first = NULL;
    int number, count= 0;

    first = add_to_list(first,3);
    first = add_to_list(first, 64);
    first = add_to_list(first,98);
    first = add_to_list(first,3);
    first = add_to_list(first,64);
    first = add_to_list(first,136);

    struct node *s_node = search_list(first,56);
    //if(*s_node != NULL){
    //    printf("56 found!")
    //}
    return 0;
}

struct node *add_to_list(struct node *list, int n){
    struct node *new_node;
    new_node = malloc(sizeof(struct node));
    if(new_node == NULL){
        printf("Malloc fail in add_to_list\n");
        return list;
    }
    new_node->value = n;
    new_node->next = list;
    return new_node;

}

struct node *search_list(struct node *list, int n){
    struct node *p;
    for(p = list; p != NULL; p = p->next){
        if(p->value == n){
            return p;
        }
    }
    return NULL;
}

struct node *delete_from_list(struct node *list, int n){
    struct node *cur, *prev;
    for(cur = list, prev = NULL; cur != NULL && cur->value != n; prev = cur, cur = cur->next);
    if(cur == NULL){
        return list;
    }
    if(prev == NULL){
        list = list->next;
    }else{
        prev->next = cur->next;
    }
    free(cur);
    return list;
}
void clear_list(struct node *list){
    struct node *p;
    while(list != NULL){
        p = list;
        list = list->next;
        if(p != NULL){
            free(p);
        }
    }
}

