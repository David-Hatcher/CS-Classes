#include <stdio.h>
void print_arrays(int *a,int n);

int main()
{
    int *p;
    int i = 4;
    p = &i;
    printf("Value of i = %d, Value of *p = %d\n",i,*p);
    printf("Value of p = %p, Pointer of &i = %p\n",p,&i);
    *p = 32;
    printf("Value of i = %d, Value of p = %d\n",i,*p);
    int j,n=4;
    int a[4] = {5,8,2,9};
    print_arrays(a,n);
    for(j = 0; j < n; j++){
      
        printf("Address of a[%d] = %p\n",j,&a[j]);
    }

    
    return 0;
}
void print_arrays(int *a,int n){
    int j;
    for(j = 0; j < n; j++){
      
        printf("Address of a[%d] = %p\n",j,&a[j]);
    }
}
