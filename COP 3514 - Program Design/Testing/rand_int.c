#include <stdio.h>
#include <stdlib.h>

int pick(int a, int b);

int main()
{
    int randomNumber;
    randomNumber = pick(1,5);
    printf("%d",randomNumber);
    
    return 0;
}
int pick(int a, int b){
    int upper_bound = b - a + 1;
    int max = RAND_MAX - RAND_MAX % upper_bound;
    int r;

    do {
        r = rand();
    }while(r >= max);
    r = r % max;
    return a + r;
}
