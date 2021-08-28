#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct node* push(struct node* top, int i)
{
   struct node *new_node;
   new_node = malloc(sizeof(struct node));
   if(new_node == NULL)
   {
	printf("malloc failed");
        return top;
   }
   
   new_node->value = i;
   new_node->next = top;
   return new_node;

}

struct node *make_empty(struct node *top)
{
   struct node *p;
   while(top != NULL){
      p = top;
      top = top->next;
      if(p != NULL){
         free(p);
      }
   }
  return top;
}

struct node *pop(struct node *top, int *i)
{
   struct node *p = top->next;
   *i = top->value;
   free(top);
   top = p;
   return top;
}

void print_stack(struct node *top)
{
   struct node *p;
   if(top != NULL){
      for(p = top; p !=NULL; p=p->next)
	printf("%d\n", p->value);
      printf("\n");
   }
   else
      printf("stack is empty\n");
}
