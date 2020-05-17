#include <iostream>
#include <limits>
#include <vector>
#include "Employee.h"
#include "Customer.h"
#include "Person.h"

using namespace std;

const string TITLE = "Customer/Employee Data Entry";
const string PERSON_TYPE_STRING = "Customer or employee? (c/e): ";
const string LOOP_HEADER = "DATA ENTRY";
const string CONTINUE_STRING = "Continue? (y/n): ";


Customer createCustomer(string first_name, string last_name, string email);
Employee createEmployee(string first_name, string last_name, string email);
auto createPerson(char p);
void printTitle(string output);
char askPersonType(string output);
bool askContinue(string output);
bool isCharEorC(char p);
void printEmployee(const Employee& p);
void printCustomer(const Customer& p);

/**
 * Author: David Hatcher
 * Purpose: This program allows a user to create an employee or customer object
 * and then prints the values of that object to the console
*/
int main(){
    printTitle(TITLE);

    bool cont = true;

    while(cont){
        char person_type = askPersonType(PERSON_TYPE_STRING);        
        cout << endl << LOOP_HEADER << endl;
        vector<string> values{"First name: ","Last name: ", "Email: "};
        for(string& value : values){
            cout << value;
            cin >> value;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        if(person_type == 'e'){
            Employee e = createEmployee(values.at(0), values.at(1), values.at(2));
            printEmployee(e);
        }else{
            Customer c = createCustomer(values.at(0), values.at(1), values.at(2));
            printCustomer(c);
        }
        cont = askContinue(CONTINUE_STRING);
    }
    cout << "Bye!";
}

/**
 * printTitle prints the title of the program
*/
void printTitle(string output){
    cout << output << endl << endl;
}

/**
 * askContinue takes a string, outputs it to the console and asks the user for a y or n the returns it
 * it also has cin error handling and handling for incorrect inputs
*/
bool askContinue(string output){
    cout << endl << output;
    char input;
    cin >> input;
    cout << endl;
    if(tolower(input) == 'y'){
        return true;
    }else if(tolower(input) == 'n'){
        return false;
    }else{
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << left << "Invalid Input please enter y or n!" << endl;
        return askContinue(output);
    }
}

/**
 * askPersonType takes a string, outputs it to the console and asks the user for a c or e. 
 * it handles cin errors and invalid character inputs
*/
char askPersonType(string output){
    cout << output;
    char person_type;
    cin >> person_type;
    if(cin.fail() || !isCharEorC(person_type)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Invalid input, please enter c or e!" << endl;
        person_type = askPersonType(output);
    }
    return tolower(person_type);
}

/**
 * isCharEorC takes a character and returns true if it is c or e
 * otherwise returns false
*/
bool isCharEorC(char p){
    if(tolower(p) == 'e' || tolower(p) == 'c'){
        return true;
    }
    return false;
}

/**
 * createCustomer takes a first name, last name, and email and returns a customer object
*/
Customer createCustomer(string first_name, string last_name, string email){
    Customer p;
    p.setLastName(last_name);
    p.setFirstName(first_name);
    p.setEmailAddres(email);
    string number;
    cout << "Number: ";
    cin >> number;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    p.setCustomerNumber(number);
    return p;
}

/**
 * createEmployee takes a first name, a last name and an email and creates an employee object
*/
Employee createEmployee(string first_name, string last_name, string email){
    Employee p;
    p.setLastName(last_name);
    p.setFirstName(first_name);
    p.setEmailAddres(email);
    string number;
    cout << "SSN: ";
    cin >> number;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    p.setEmployeeSSN(number);
    return p;
}

/**
 * printEmployee takes an Employee object and prints out the values
*/
void printEmployee(const Employee& p){
    cout << endl << "EMPLOYEE" << endl;
    cout << "Name: " << p.getFullName() << endl;
    cout << "Email: " << p.getEmailAddress() << endl;
    cout << "SSN: " << p.getEmployeeSSN() << endl;
}

/**
 * printCustomer takes an Customer object and prints out the values
*/
void printCustomer(const Customer& p){
    cout << endl << "CUSTOMER" << endl;
    cout << "Name: " << p.getFullName() << endl;
    cout << "Email: " << p.getEmailAddress() << endl;
    cout << "Number: " << p.getCustomerNumber() << endl;
}
