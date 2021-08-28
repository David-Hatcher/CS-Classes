#include "readline.h"
#include <stdio.h>
#include <string.h>
#define NAME_LEN 25
#define MAX_COLORS 100

struct color{
   char name[NAME_LEN+1];
   int red;
   int green;
   int blue;
};

void print(struct color colors[], int nc);
void insert(struct color colors[], int *nc);
void search(struct color colors[], int nc);
int find(struct color colors[], int nc, char name[]);

int main()
{

 char code;
  struct color cols[MAX_COLORS];
  int num_colors = 0;

  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
      case 'i': insert(cols, &num_colors);
                break;
      case 's': search(cols, num_colors);
                break;
      case 'p': print(cols, num_colors);
                break;
      case 'q': return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }

    return 0;
}

/*insert a color to the array */
void insert(struct color colors[], int *nc)
{
  struct color newColor;
  
  if (*nc == MAX_COLORS) {
    printf("Database is full; can't add more parts.\n");
    return;
  }
  printf("Enter the name you'd like to add: ");
  read_line(newColor.name,NAME_LEN);
  if(find(colors,*nc,newColor.name) >= 0){
    printf("Color name already exists!\n");
    return;
  } 
  printf("Enter red number:");
  scanf("%d",&newColor.red);
  printf("Enter green number:");
  scanf("%d",&newColor.green);
  printf("Enter blue number:");
  scanf("%d",&newColor.blue);
  colors[*nc] = newColor;  
  printf("Color %s added", colors[*nc].name);
  (*nc)++;
}
/*display the colors stored in the array*/
void print(struct color colors[], int nc)
{

  int i;

  printf("Color\tRed\t"
         "Green\tBlue\n");
  for (i = 0; i < nc; i++)
  printf("%s\t%d\t%d\t%d\n", colors[i].name, colors[i].red,
           colors[i].green, colors[i].blue);
}
/*search a color by name and display the RGB if found */
void search(struct color colors[], int nc)
{
  int i;
  char name[25+1];
  printf("Enter the name you'd like to search for.");
  scanf("%s",name);
  for(i = 0; i < nc; i++){
    if(strcmp(colors[i].name,name) == 0){
      printf("Color found RGB = %d,%d,%d",colors[i].red,colors[i].green,colors[i].blue);
      return;
    }
  }
  printf("Color not found!");
  return;
}
int find(struct color colors[], int nc, char name[]){
  int i;
  for(i = 0; i < nc; i++){
    if(strcmp(colors[i].name,name) == 0){
      return i;
    }
  }
  return -1;
}

