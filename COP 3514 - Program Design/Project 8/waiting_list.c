#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ROOM_LEN 100
#define NAME_LEN 30
#define PHONE_LEN 15
/*This program allows the user to create a waiting list by adding
a class, first name, last name, and phone number. It creates a linked list
of these values. It will let you update the class of one, append one to the end,
print them, and then clears the memory allocation when closed.
*/

struct request{
	char classroom[ROOM_LEN];
	char first[NAME_LEN+1];
	char last[NAME_LEN+1];
	char phone[PHONE_LEN+1];;

	struct request *next;
};


struct request *append_to_list(struct request *list);
void update(struct request *list);
void printList(struct request *list);
void clearList(struct request *list);
int read_line(char str[], int n);

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
/*function append_to_list allows the user to add a single request struct
to the linked list. It will specifically add it to the end of the list. It takes
a pointer to a linked list and returns a pointer to a linked list. If that list is null
it will return a pointer to the newAdd linked list, otherwise it will return the pointer
to the original linked list with the new value added at the end
*/
struct request *append_to_list(struct request *list){

  struct request *newAdd, *p;
  newAdd = malloc(sizeof(struct request));

  if(newAdd == NULL){
    printf("malloc failed in append_to_list");
    return list;
  }
  newAdd->next = NULL;
  printf("Enter classroom: ");
  read_line(newAdd->classroom,ROOM_LEN);
  printf("Enter child first name: ");
  read_line(newAdd->first,NAME_LEN);
  printf("Enter child last name: ");
  read_line(newAdd->last,NAME_LEN);

  if(list == NULL){
    printf("Enter contact phone number: ");
    read_line(newAdd->phone,PHONE_LEN);
    return newAdd;
  }else{
    for(p = list; p != NULL; p = p->next){
      if(strcmp(p->classroom,newAdd->classroom) == 0 && strcmp(p->first,newAdd->first) == 0 && strcmp(p->last,newAdd->last) == 0){
        printf("%s %s found on the waiting list for %s classroom.",newAdd->first,newAdd->last,newAdd->classroom);
        return list;
      }
    }
    printf("Enter contact phone number: ");
    read_line(newAdd->phone,PHONE_LEN);
  }
  for(p = list;; p = p->next){
    if(p->next == NULL){
      p->next = newAdd;
      break;
    }
  }
  return list;
}
/*the update function takes a pointer to a linked list and allows
the user to update a single struct in the list. If that struct
does not exist then it will let the user know that and return the
pointer to the same unaltered linked list. If that struct does exist,
it will return the same pointer to the linked list but it will be altered
with the new data
*/
void update(struct request *list)
{ 
  if(list == NULL){
    printf("List is empty!");
    return;
  }
  struct request *p;
  char classroom[ROOM_LEN], first[NAME_LEN], last[NAME_LEN];
  printf("Enter classroom: ");
  read_line(classroom,ROOM_LEN);
  printf("Enter child first name: ");
  read_line(first,NAME_LEN);
  printf("Enter child last name: ");
  read_line(last,NAME_LEN);
  for(p = list; p != NULL; p = p->next){
    if(strcmp(p->classroom,classroom) == 0 && strcmp(p->first,first) == 0 && strcmp(p->last,last) == 0){

          printf("%s %s found on the waiting list for %s classroom.\n",first,last,classroom);
          printf("Enter new classroom: ");
          read_line(p->classroom,ROOM_LEN);
          return;
    }
  }
  printf("%s %s was not found on the waiting list for %s classroom.",first,last,classroom);

}

/*function printList takes a pointer to a linked list and
will print out the list to the terminal.
*/
void printList(struct request *list){
  if(list == NULL){
    printf("List is empty");
    return;
  }
  struct request *p;
  printf("Classroom\t\t\t\tFirst Name\t\tLast Name\t\tContact Phone Number\n");
  for(p = list; p != NULL; p = p->next){
    printf("%-9s\t\t\t\t%-10s\t\t%-9s\t\t%-20s\n",p->classroom,p->first,p->last,p->phone);
  }
  printf("\n");
}

/*function clearList takes a pointer to a linked list and 
will free all memory allocation from the pointer
to the linked list
*/
void clearList(struct request *list){
  struct request *p;
  printf("Clearing list.\n");
  while(list != NULL){
    p = list;
    list = list->next;
    if(p != NULL){
      free(p);
    }
  }
  printf("List cleared.");
}

int read_line(char str[], int n)
{
  int ch, i = 0;

  while (isspace(ch = getchar()))
    ;
  str[i++] = ch;
  while ((ch = getchar()) != '\n') {
    if (i < n)
      str[i++] = ch;
    
   }
   str[i] = '\0';
   return i;
}
