#include <stdio.h>
#include "stack.h"

int main(void)
{
   int n;
   struct node *stack1 = NULL;
   struct node *stack2 = NULL;
   stack1 = push(stack1, 25);
   stack1 = push(stack1, 32);
   stack1 = push(stack1, 8);
   stack1 = push(stack1, 94);
   stack2 = push(stack2, 21);
	
   printf("stack1:\n");
   print_stack(stack1);
   printf("stack2:\n");
   print_stack(stack2);   

   stack1 = pop(stack1, &n);
   printf("Popped %d from stack1\n", n);
   printf("stack1:\n");
   print_stack(stack1);
 
   stack2 = push(stack2, n);
   printf("stack2:\n");
   print_stack(stack2);
 
   stack1 = pop(stack1, &n);
   printf("Popped %d from stack1\n", n);
   printf("stack1:\n");
   print_stack(stack1);
 
  
   stack1 = make_empty(stack1);
   printf("stack1:\n");
   print_stack(stack1);


   stack2 = make_empty(stack2);
   printf("stack2:\n");
   print_stack(stack2);

   return 0;

}
