#include <iostream>
#include <limits>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
const std::string file_name = "monthly_sales.txt";

using namespace std;
/**
 * This struct is do create a tuple of the month name
 * along with the sales for that month to populate a
 * vector with those values for easy iteration
*/
struct month_sales{
    string month_name;
    double month_sales;
};

char getCommand();
vector<month_sales> getSales(string file_name);
void printSales(vector<month_sales> data);
void printSummary(vector<month_sales> data);
void dispTitle();
void dispCommands();
/**
 * Author: David Hatcher
 * Purose: This program will pull in data from a text file, monthly_sales.txt
 * which contains each month and sales for that month and allow the user to
 * either display a yearly summary with average monthly sales or display
 * the values month by month
*/
int main(){
    dispTitle();//display title
    dispCommands();//display commands

    vector<month_sales> sales = getSales(file_name);//build the vector of months and sales
    char user_input = getCommand();//get users command

    while(user_input != 'x'){//main loop to run while user has not input x
        if(user_input == 'm'){//show months
            printSales(sales);
        }else if(user_input == 'y'){//show yearly totals
            printSummary(sales);
        }else{//if input is invalid warn user
            cout << "Invalid command. Try again." << endl;
        }
        user_input = getCommand();
    }
    cout << "Bye!";
    return 0;
}
/**
 * getCommand gets a single character
 * command from the user and dumps the buffer
 * then returns that character
 */
char getCommand(){
    cout << endl << "Command: ";
    char character;
    cin >> character;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << endl;
    return character;
}
/**
 * getSales takes a string file name and builds 
 * a vector of month_sales structs out of the values in that file
 * 
 */
vector<month_sales> getSales(string file_name){
    vector<month_sales> sales_from_file;
    struct month_sales month;

    ifstream input_file;//instanciating file object
    input_file.open(file_name);//opening file object
    string input_buffer;
    while(getline(input_file,input_buffer)){//runs while it hasn't hit the end
        stringstream ss(input_buffer);
        ss >> month.month_name >> month.month_sales;//first value is the name of the month second is sales
        sales_from_file.push_back(month);//append to vector
    }
    input_file.close();

    return sales_from_file;
}
/**
 * printSales takes a vector and prints the values
 * month_sales.month_name and month_sales.month_sales
 * formatted
 */
void printSales(vector<month_sales> data){
    cout << right << fixed << setprecision(2);
    cout << "MONTHLY SALES" << endl;
    for(month_sales month : data){
        cout << left << month.month_name << right << setw(15) << showpoint << month.month_sales << endl;
    }
}
/**
 * printSummary takes a vector of month_sales structs
 * and prints the total of the month_sales.month_sales
 * along with an average of those values
 */
void printSummary(vector<month_sales> data){
    double sum = 0.0;
    int totalMonths = data.size();
    for(month_sales month : data){
        sum += month.month_sales;
    }
    cout << left; 
    cout << "YEARLY SUMMARY" << endl << fixed << setprecision(2);;
    cout << left << "Yearly total: " << right << setw(12) << sum << endl;
    cout << left << "Montly average: " << right << setw(10) << sum/totalMonths << endl;
}
/**
 * dispTitle displays the title
 */
void dispTitle(){
    cout << "Monthly Sales" << endl << endl;
}
/**
 * dispCommands displays the commands
 */
void dispCommands(){
    cout << "COMMAND MENU" << endl;
    cout << "m - View Monthly Sales" << endl;
    cout << "y - View yearly summary" << endl;
    cout << "x - Exit program" << endl << endl;
}