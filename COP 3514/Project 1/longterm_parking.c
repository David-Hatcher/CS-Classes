/*This program will determine the amount of money due for parking
based on a users input of how many hours and minutes they spent
parked there.
*/

#include <stdio.h>
#define MINUTES_IN_DAY  (24 * 60)
#define MINUTES_BEFORE_COST_CAP 180
#define DAILY_COST_CAP 18
int calculateAmountOwed(int minutes, int hours);
int amountOwedMoreThanOneDay(int minutes);
int amountOwedLessThanOneDay(int minutes);

int main(int argc, char const *argv[])
{
    int minutes;
    int hours;    

    printf("Enter hours parked:\n");
    scanf("%d",&hours);
    printf("Enter minutes parked:\n");
    scanf("%d",&minutes);
    if(minutes > 0 && minutes < 60 && hours >= 0){
        int amount_owed = calculateAmountOwed(minutes, hours);
        printf("Amount owed ($): %d", amount_owed);
    }else{
        printf("Invalid input. Hours should be positive and minutes should be in range 0-60");
    }

    return 0;
}

int calculateAmountOwed(int minutes, int hours){
    //This is to determine whether to use the function for time more than a day or less than a day
    int total_minutes = minutes + (hours * 60);
    int amount_owed = 0;
    if(total_minutes >= MINUTES_IN_DAY){
        amount_owed = amountOwedMoreThanOneDay(total_minutes);
    }else{
        amount_owed = amountOwedLessThanOneDay(total_minutes);
    }
    return amount_owed;
}
int amountOwedMoreThanOneDay(int minutes){
    //This determines the cost of parking for more than a day
    int total_minutes = minutes;
    int amount_owed = 0;
    while(total_minutes > MINUTES_IN_DAY){
        total_minutes -= MINUTES_IN_DAY;
        amount_owed += DAILY_COST_CAP;
    }
    if(total_minutes >= MINUTES_BEFORE_COST_CAP){
        amount_owed += DAILY_COST_CAP;
    }else{
        while(total_minutes > 0){
            total_minutes -= 20;
            amount_owed += 2;
        }
    }
    
    return amount_owed;
}
int amountOwedLessThanOneDay(int minutes){
    //This determines the cost of parking for less than a day
    int total_minutes = minutes;
    int amount_owed = 0;
    while(total_minutes > 60){                                  
        if(total_minutes > 80){                                 
            total_minutes -= 20;
            amount_owed += 2;
        }else if(total_minutes > 60 && total_minutes <= 80){
            total_minutes -= 80;
            amount_owed += 4;
        }
        if(amount_owed > DAILY_COST_CAP){
            amount_owed = DAILY_COST_CAP;
            break;
        }
    }
    return amount_owed;
}