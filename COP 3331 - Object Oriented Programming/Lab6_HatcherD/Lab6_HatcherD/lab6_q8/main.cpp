#include <iostream>
#include <limits>
#include <iomanip>
#include "Rectangle.h"

using namespace std;

int getLength(string output);
bool askContinue(string output);
void printValue(Rectangle rect, string output, bool area = true);
void printDisplay();

/**
 * Author: David Hatcher
 * Purpose: This program gets a length and width from the user
 * and creates a rectangle on the screen using the Rectangle class
*/
int main(){
    printDisplay();
    bool cont = true;

    while(cont){
        Rectangle rect;
        rect.setHeight(getLength("Height"));
        rect.setWidth(getLength("Width"));
        printValue(rect,"Perimeter",false);
        printValue(rect,"Area");

        cout << rect.getPerimeterString();

        cont = askContinue("Continue? (y/n): ");
    }
    cout << "Bye!";
    return 0;
}

/**
 * getLength takes a string, output, and asks the user for the value
 * corrosponding to the value given in output and returns an int, it also handles invalid
 * inputs from the user
*/
int getLength(string output){
    string output_string = output + ":";
    cout << left << setw(11) << output_string;
    int length;
    cin >> length;
    if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Invalid Input please enter a number!" << endl;
        length = getLength(output);
    }
    if(length < 1){
        cout << "Value must be greater than 0." << endl;
        length = getLength(output);
    }
    return length;
}
/**
 * askContinue takes a string, output, prints it and takes 
 * a users input either y or n and returns a boolean
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
        cout << "Invalid Input please enter y or n!" << endl;
        return askContinue(output);
    }
}
/**
 * printValue takes a Rectangle Object, the output string, and a boolean.
 * The boolean is default to true and determines whether to print area or perimeter
*/
void printValue(Rectangle rect, string output, bool area){
    string output_string = output + ":";
    int value;
    if(area){
        value = rect.getArea();
    }else{
        value = rect.getPerimeter();
    }
    cout << left << setw(11) << output_string << value << endl;
}

/**
 * printDisplay prints the title
*/
void printDisplay(){
    cout << "Rectangle Calculator" << endl << endl;
}