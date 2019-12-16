#include <stdio.h>
#include "request.h"
/*This program allows the user to create a waiting list by adding
a class, first name, last name, and phone number. It creates a linked list
of these values. It will let you update the class of one, append one to the end,
print them, and then clears the memory allocation when closed.
*/

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
int main(void)
{
  char code;

  struct request *wait_list = NULL;
  printf("Operation Code: a for appending to the list, u for updating a book"
	  ", p for printing the list; q for quit.\n");
  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
      case 'a': wait_list = append_to_list(wait_list);
                break;
      case 'u': update(wait_list);
                break;
      case 'p': printList(wait_list);
                break;
      case 'q': clearList(wait_list);
		return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}
