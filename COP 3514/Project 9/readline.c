#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "readline.h"

/* * * * * * * * * * * * * * * * * * * * ** 
 * function read_line takes a string array*
 * and an integer and the reads a line of *
 * text the user enters that is no longer *
 * than n and places that string into the *
 * array that was passed.                 *
 * * * * * * * * * * * * * * * * * * * * ** 
*/
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
