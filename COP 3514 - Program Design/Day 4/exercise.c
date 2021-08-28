#include <stdio.h>

int main()
{
    int number, counter, sum, counter_1;
    printf("Enter a number to find the sum of consecutive integers:\n");
    scanf("%d",&number);
    for(counter_1 = 1; counter_1 <= number; counter_1++){
        sum = 0;
        for(counter = 1; counter <= counter_1; counter++){
            sum += counter;        
        }
        if(sum > 100){
            break;
        }
        if(sum % 2 != 0){
            continue;
        }
        printf("%d\n", sum);
    }
    return 0;
}
