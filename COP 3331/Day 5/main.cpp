#include <iostream>
#include <string>
#include "temp.h"

using namespace std;
using namespace tempr;
/**
 * Chapter 7 How to code functions
 * 
 * 
 * 
 * headerfiles
 * 
 * 
*/

//void print(string);//parameter name not needed
void dostuff(const string& val);//won't change the value of the input string

void print(string name = "default");
void print(double num);//overloading
void increasePrice(double& price);
int main(){
    string stuff = "print me";
    double stuff_double = 0.2;
    print();
    print(stuff_double);

    double p1 = 54.50;
    double p3 = p1;
    p1 = 57.50;//only changes p1
    cout << endl << "after p2" << endl;
    print(p3);
    double &p2 = p1;//double& p2 = p1;
    p1 = 103.4;//changes both
    cout << endl << "after &p2" << endl;
    print(p2);
    increasePrice(p2);
    cout << endl << "after increasePrice(p2)" << endl;
    print(p2);

    double new_num = 2.3;
    double newnew_num = to_celsius(new_num);
    cout << endl;
    print(newnew_num);
    return 0;
}

void print(string name){
    //this is default but you can only the default declared on
    //either the prototype or the definition
    cout << name;
}

void print(double num){
    cout << num;
}

void increasePrice(double& price){
    price *= 1.1;
}