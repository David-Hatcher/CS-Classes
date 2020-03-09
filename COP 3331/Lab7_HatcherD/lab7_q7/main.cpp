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

void printTitle(string output){
    cout << output << endl << endl;
}

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

bool isCharEorC(char p){
    if(tolower(p) == 'e' || tolower(p) == 'c'){
        return true;
    }
    return false;
}


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

void printEmployee(const Employee& p){
    cout << endl << "EMPLOYEE" << endl;
    cout << "Name: " << p.getFullName() << endl;
    cout << "Email: " << p.getEmailAddress() << endl;
    cout << "SSN: " << p.getEmployeeSSN() << endl;
}

void printCustomer(const Customer& p){
    cout << endl << "CUSTOMER" << endl;
    cout << "Name: " << p.getFullName() << endl;
    cout << "Email: " << p.getEmailAddress() << endl;
    cout << "Number: " << p.getCustomerNumber() << endl;
}
