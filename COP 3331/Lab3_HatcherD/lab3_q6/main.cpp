#include <iostream>
#include <iomanip>
#include "console.h"
#include "salestax.h"

using namespace console;
using namespace std;
using namespace taxes;

void dispPromt();
void dispTitle();
double askCost();
void dispTotals(double sub_total, double tax, double total);
char askCont();
bool isCharYorN(char a);

/**
 * Author: David Hatcher
 * Purpose: This program will allow the user to enter
 * any number of line items prices and then total those
 * prices and add in sales tax
 */
int main(){
    char again_var;//initialize check variable
    dispTitle();//display title
    do{
        double current_cost;//variable for current item
        double total_cost_pre_tax = 0.0;//running total for items

        dispPromt();//ask user to enter values
        do{
            current_cost = askCost();//ask user for cost of item
            if(current_cost == 0){//end loop on 0
                break;
            }
            total_cost_pre_tax += current_cost;//sum costs
        }while(true);
        double tax = getTax(total_cost_pre_tax);//gets tax amount
        double total_cost_post_tax = getTotalPlusTax(total_cost_pre_tax);//gets total with tax
        dispTotals(total_cost_pre_tax,tax,total_cost_post_tax);//display totals
        again_var = askCont();//would user like to do it again?
        while(!isCharYorN(again_var)){
            cout << "Invalid input please type y or n" << endl;
            again_var = askCont();
        }
        cout << endl;//skipline
    }while(again_var == 'y');//keep going while user enters y
    cout << "Thanks, bye!";
    return 0;
}
/**
 * askCost will as the cost of an item
 */
double askCost(){
    return get_double("Cost of Item: ",-0.1);
}
/**
 * dispTitle displays the title
 */
void dispTitle(){
    cout << "Sales Tax Calculator" << endl << endl;
}
/**
 * dispPromt will display the promt to the user
 */
void dispPromt(){
    cout << "ENTER ITEMS (ENTER 0 TO END)" << endl;
}
/**
 * display totals will display the totals for the
 * items entered
 */
void dispTotals(double sub_total, double tax, double total){
    cout << fixed << setprecision(2) << endl;
    cout << left << "Total:" << right << setw(20) << sub_total << endl;
    cout << left << "Sales Tax:" << right << setw(16) << tax << endl;
    cout << left << "Total after tax:" << right << setw(10) << total << endl << endl;    
}
/**
 * askCont will ask the user if they'd like to continue.
 * it will also sanitize input
 */
char askCont(){
    return tolower(get_char("Again? (y/n): "));
}
/**
 * isCharYorN takes an input character and returns a
 * boolean value based on if the character is a y or an n
*/
bool isCharYorN(char a){
    if(a == 'y' || a == 'n'){
        return true;
    }
    return false;
}