#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "request.h"


/*function append_to_list allows the user to add a single request struct
to the linked list. It will specifically add alphabetically sorted by class then last name. It takes
a pointer to a linked list and returns a pointer to a linked list. If that list is null
it will return a pointer to the newAdd linked list, otherwise it will return the pointer
to the original linked list with the new value added at the end
*/
struct request *append_to_list(struct request *list){

  struct request *newAdd, *p, *cur, *prev;
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
  for(cur = list, prev = NULL; cur != NULL;prev = cur, cur = cur->next){
    if(cur->next == NULL && strcmp(cur->classroom,newAdd->classroom) < 0){
      cur->next = newAdd;
      return list;
    }else if(strcmp(cur->classroom,newAdd->classroom) == 0){
      struct request *sameClassCur, *sameClassPrev;
      for(sameClassCur = cur, sameClassPrev = NULL; sameClassCur != NULL && strcmp(sameClassCur->classroom, newAdd->classroom) == 0; sameClassPrev = cur, sameClassCur = sameClassCur->next){
        if(strcmp(sameClassCur->last,newAdd->last) >= 0){
          break;
        }
      }
      newAdd->next = sameClassCur;
      if(sameClassPrev == NULL){
        if(prev == NULL){
          return newAdd;
        }else{
          prev->next = newAdd;
          return list;
        }
      }else{
        sameClassPrev->next = newAdd;
        return list;
      }
    }else if(strcmp(cur->classroom,newAdd->classroom) > 0){
      newAdd->next = cur;
      if(prev == NULL){
        return newAdd;
      }else{
        prev->next = newAdd;
        return list;
      }
    }
  }
  return list;
}
/* * * * * * * * * * * * * * * * * * * * * * * * * * *
function delete_from_list takes a struct request list 
pointer and will ask the user which node to delete
it will then scan through the list looking for the
specified node. If it exists it will delete it from the
list and return the modified list. Otherwise, it will
let the user know that no such node exists and return
the unalter list.
* * * * * * * * * * * * * * * * * * * * * * * * * * */
struct request *delete_from_list(struct request *list){
  if(list == NULL){
    printf("List is empty.");
    return list;
  }
  struct request *cur,*prev;
  char classroom[ROOM_LEN], first[NAME_LEN], last[NAME_LEN];
  printf("Enter classroom: ");
  read_line(classroom,ROOM_LEN);
  printf("Enter child first name: ");
  read_line(first,NAME_LEN);
  printf("Enter child last name: ");
  read_line(last,NAME_LEN);
  for(cur = list, prev = NULL; cur != NULL; prev = cur, cur = cur->next){
    if(strcmp(cur->classroom,classroom) == 0 && strcmp(cur->first,first) == 0 && strcmp(cur->last,last) == 0){
      if(prev == NULL){
        list = cur->next;
      }else{
        prev->next = cur->next;
      }
      free(cur);
      printf("%s %s is deleted from the waiting list for %s classroom.\n",first,last,classroom);
      return list;
    }
  }
  printf("%s %s was not found on the waiting list for %s classroom.\n",first,last,classroom);
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