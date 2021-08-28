#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "customer.h"

using namespace std;

const string FILE_NAME = "customers.txt";

vector<Customer> buildList(string file_name);

int main(){
    vector<Customer> customers = buildList(FILE_NAME);
    auto b = customers.begin();
    auto e = customers.end();
    while(true){
        string id_to_find;
        string customer_val = "No customer with that ID";
        cout << "Enter a customer ID: ";
        cin >> id_to_find;

        for(auto i = b; i < e; ++i){
            if(id_to_find == (*i).getId()){
                customer_val = (*i).getFullAddress();
                break;
            }
        }
        cout << endl << customer_val << endl;
        char cont;
        cout << endl << "Continue? (y/n)";
        cin >> cont;
        cout << endl << endl;
        if(cont == 'n'){
            break;
        }
    }



    return 0;
}

vector<Customer> buildList(string file_name){
    ifstream input_file;
    vector<Customer> customers;
    input_file.open(file_name);
    string line;
    string titles;
    getline(input_file,titles);

    while(getline(input_file,line)){
        Customer current_customer;
        stringstream ss(line);
        string id;
        getline(ss,id,'\t');
        current_customer.setId(id);
        string first_name;
        getline(ss,first_name,'\t');
        current_customer.setFirstName(first_name);
        string last_name;
        getline(ss,last_name,'\t');
        current_customer.setLastName(last_name);
        string company_name;
        getline(ss,company_name,'\t');
        current_customer.setCompany(company_name);
        string address;
        getline(ss,address,'\t');
        current_customer.setAddress(address);
        string city;
        getline(ss,city,'\t');
        current_customer.setCity(city);
        string state;
        getline(ss,state,'\t');
        current_customer.setState(state);
        string postal_code;
        getline(ss,postal_code,'\t');
        current_customer.setPostalCode(postal_code);
        customers.push_back(current_customer);
    }
    input_file.close();
    return customers;
}