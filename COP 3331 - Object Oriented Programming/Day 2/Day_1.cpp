/*
Need to get textbook
Still using student cluster



Speed, portability(move from environments),scales well,job security


*/

#include <iostream>//input output
#include <cmath>//math header
#include <ctime>//time header
#include <string>//string class


using namespace std;// use all elements of the std namespace

using std::cout;// use the cout object
using std::sqrt;//use the sqrt function
using std::round;//using round function

int main(){
    cout << "Hello World" << endl;
    int num = 7;
    double root = std::sqrt(num);//just pulling the function out of the 
    double rounded_root = std::round(root);//same thing;
    //cin can be chained 
    //cin >> value1 >> value2;

    //srand(seed) sets a seed value for the random number generation, rand() sets the seed at 1 and
    //will always be the same.
    //time(timer) gives you the time in seconds currently. 

    int elapsed_seconds = time(nullptr);//pass it a null pointer

    srand(elapsed_seconds);//sets seed of srand

    int die1 = rand() % 6;//between [0,6)
    die1 = die1 + 1;// between [1,6]
    cout << "Die roll = " << die1;

    char middle_initial = 'M';

    string message1 = "Invalid data entry";
    string message2 = "";

    string first_name = "Bob";
    string last_name = "Smith";

    string name = last_name + ", " + first_name;
    name = first_name + ' ' + middle_initial + ' ' + last_name;
    string new_name = first_name + ' ';
    new_name += middle_initial;
    new_name += ' ';
    new_name += last_name;
    cout << "Name: "<< name << endl;
    cout << "New Name: "<< new_name << endl;

    string sep = "\\";
    cout << "C:" << sep << "murach" << endl;

    string value;
    cout << "Enter Your Name" << endl;
    getline(cin,value);
    cout << "Hello, " << value << endl;

    //member function of cin object
    //get() gets one character
    //ignore()
    //ingore(numofchars,delimiter)

    // cin.ignore(1000,'\n');
    // cout <<"\nPress [Enter] to close terminal";
    // cin.ignore();
}