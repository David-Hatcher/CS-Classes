#include <stdio.h>

int main(int argc, char const *argv[])
{
    //Lvalues error means you put the variables on the wrong side of operand
    //
    /*
    Boolean 
    1 = true
    0 = false
    if (n >= 1 <= 10)
    This works in c    

    variable = boolean can be done
    int first_earlier = first < second;
    this will be 0 or 1 depending on the outcome of the boolean
    
    */
   int month_1,day_1,year_1,month_2,day_2,year_2;
   int first_earlier = 0;
    printf("Enter First Date (mm/dd/yy):");
    scanf("%d/%d/%d",&month_1,&day_1,&year_1);
    printf("Enter Second Date (mm/dd/yy):");
    scanf("%d/%d/%d",&month_2,&day_2,&year_2);
    if(year_1 < year_2){
        first_earlier = 1;        
    }else if(year_2 == year_1){
        if(month_1 < month_2){
            first_earlier = 1;
        }else if(month_1 == month_2){
            if(day_1 < day_2){
                first_earlier = 1;
            }
        }
    }
    if(first_earlier == 1){
        printf("First date is earlier!");
    }else{
        printf("Second date is earlier!");
    }
 
    
    

    return 0;
}
