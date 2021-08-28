#include <iostream>
#include <string>
#include <limits>

using namespace std;

void swap_names(string* a, string* b);

int main(){

    string name_1;
    string name_2;
    char cont = 'y';
    while(tolower(cont) == 'y'){
        cout << "Enter First Name: ";
        getline(cin,name_1,'\n');
        cout << "Enter Second Name: ";
        getline(cin,name_2,'\n');

        string* ptr_1 = &name_1;
        string* ptr_2 = &name_2;

        swap_names(ptr_1,ptr_2);

        cout << "Name 1: " << name_1 << endl;
        cout << "Name 2: " << name_2 << endl;

        cout << "Repeat? ";
        cin >> cont;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }





    return 0;
}

void swap_names(string* a, string* b){
    string temp = *a;
    *a = *b;
    *b = temp;
}
