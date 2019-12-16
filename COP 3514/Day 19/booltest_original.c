#include <stdio.h>
#define TRUE 1
#define FALSE 0
typedef int Bool;

Bool logical_and(Bool a, Bool b);
Bool logical_or(Bool a, Bool b);
Bool logical_not(Bool a);
void print_bool(Bool b);
int main(){
		
	Bool a = TRUE;
	Bool b = FALSE;
	
	print_bool(logical_and(a, b));
	print_bool(logical_or(a, b));
	return 0;
}
	
Bool logical_and(Bool a, Bool b){
		return (a&&b);

}
Bool logical_or(Bool a, Bool b)
{
		return (a||b);
}
Bool logical_not(Bool a)
{
		return (!a);
}

void print_bool(Bool b)
{
		printf("%s\n", (b ? "TRUE" : "FALSE"));
}


	

