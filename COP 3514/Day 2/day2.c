#include <stdio.h>

int main(){
    int hours;
    double hourlyRate = 25.7;
    double amount;

    printf("Hourly rate is %.2f\n", hourlyRate);
    printf("Please enter the number of hours: ");
    scanf("%d", &hours);
    amount = hourlyRate * hours;
    printf("Total pay = %.2f",amount);

    return 0;
}