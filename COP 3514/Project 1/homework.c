/*David Hatcher Project 1.2
This program allows the user to input a number for todays day of the 
week 0-6 and a number of days to work on the assignment and it will output 
what day of the week it is due along with the number of actual days of work
available to the user.
*/


#include <stdio.h>


int main(int argc, char const *argv[])
{
    int todays_day;
    int days_of_work;

    printf("Enter the day for today (0 for Sunday, 1 for Monday, etc.):\n");
    scanf("%d",&todays_day);
    if(todays_day >= 0 && todays_day <=6){
        printf("Enter the number of days for doing the work:\n");
        scanf("%d",&days_of_work);
        int day_for_iteration = todays_day;
        int i;
        for(i = 0; i < days_of_work; i++){                
            day_for_iteration++;
            if(day_for_iteration == 7){
                day_for_iteration = 0;
            }
        }
        switch (day_for_iteration)
        {
            case 0:
                days_of_work += 1;
                printf("The due date is Monday.  The number of days until due date is %d.",days_of_work);
                break;
            case 1:
                printf("The due date is Monday.  The number of days until due date is %d.",days_of_work);
                break;
            case 2:
                printf("The due date is Tuesday.  The number of days until due date is %d.",days_of_work);
                break;
            case 3:
                printf("The due date is Wednesday.  The number of days until due date is %d.",days_of_work);
                break;
            case 4:
                printf("The due date is Thursday.  The number of days until due date is %d.",days_of_work);
                break;
            case 5:
                days_of_work += 3;
                printf("The due date is Monday.  The number of days until due date is %d.",days_of_work);
                break;
            case 6:
                days_of_work += 2;
                printf("The due date is Monday.  The number of days until due date is %d.",days_of_work);
                break;
            default:
                break;
        }
    }else{
        printf("Invalid input. The day should be in the range of 0 to 6.");
    }
    
    return 0;
}
