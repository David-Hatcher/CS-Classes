#include <iostream>
#include <limits>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>


using namespace std;
struct month_sales{
    string month_name;
    double month_sales;
};

char getCommand();
vector<month_sales> getTaxes(string file_name);
void printTaxes(vector<month_sales> data);
void printSummary(vector<month_sales> data);

int main(){
    string file_name = "monthly_sales.txt";
    vector<month_sales> taxes = getTaxes(file_name);

    cout << "Monthly Sales" << endl << endl;

    cout << "COMMAND MENU" << endl;
    cout << "m - View Monthly Sales" << endl;
    cout << "t - View yearly summary" << endl;
    cout << "x - Exit program" << endl << endl;
    char user_input = getCommand();
    while(user_input != 'x'){
        if(user_input == 'm'){
            printTaxes(taxes);
        }else if(user_input == 't'){
            printSummary(taxes);
        }else{
            cout << "Invalid command. Try again.";
        }
        user_input = getCommand();
    }
    cout << "Bye!";
    return 0;
}

char getCommand(){
    cout << endl << "Command: ";
    char character;
    cin >> character;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    return character;
}

vector<month_sales> getTaxes(string file_name){
    vector<month_sales> taxes_from_file;
    struct month_sales month;

    ifstream input_file;
    input_file.open(file_name);
    string input_buffer;
    while(getline(input_file,input_buffer)){
        stringstream ss(input_buffer);
        ss >> month.month_name >> month.month_sales;
        taxes_from_file.push_back(month);
    }
    input_file.close();

    return taxes_from_file;
}

void printTaxes(vector<month_sales> data){
    cout << right << fixed << setprecision(2);
    cout << "MONTHLY SALES" << endl;
    for(month_sales month : data){
        cout << left << month.month_name << right << setw(15) << showpoint << month.month_sales << endl;
    }
}

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

