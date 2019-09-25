#include <stdio.h>

int main(int argc, char const *argv[])
{
    int arr[5] = {1,2,3,4,5};
    int *i;
    for(i = arr; i < arr + 5;i++){
        printf("index val = %d\n",*i);
    }

    return 0;
}
