#include <stdio.h>

int main(int argc, char const *argv[])
{

    //Vim
    //Edit mode - i
    /*VI            Edit Mode           Regular Mode
     v                   i                   esc
     y                                         :w (save)
     p                                       :q  (quit)
    d                                      :wq (write quit)
                                            :q! (no save quit)
                                            yy (copy line) 
                                            p (paste line)
                                            dd( delete line)
    */

    /*


    
    */

//    int number;

//     for(;;){
//         printf("Please enter a number in the range of 0 to 5, inclusive:");
//         scanf("%d",&number);        
//         if(number >= 0 && number <=5){
//             break;
//         }
//     }

//     /*
//     null statement 
//     ;

//     */
//    int d;
//    for(d = 2; d < number; d++){
//        if(number % d == 0){
//            break;
//        }
//    }
//     //These are the same loop, null statement required
//    for(d = 2; d < number && number % d != 0; d++){
//        ;
//    }


    int number;
    printf("Enter a number to find the sum of consecutive integers:\n");
    scanf("%d",&number);
    int counter;
    for(counter = 1; counter <= number; counter++){
        counter += 1;
        printf("%d", counter);
    }

    /* code */
    return 0;
}
