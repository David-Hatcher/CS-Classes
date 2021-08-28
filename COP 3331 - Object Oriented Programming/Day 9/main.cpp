#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;


/**
 * Chapter 12 How to work with built-in arrays and C strings
 *  
 * type array_name[number_of_elements];
 * 
 * continuous memory
 * 
 * passing a built in array the array turns into a pointer to the first value in that array
 *      this is called array decay
 * 
 * expressions also cause array decay such as arr1 == arr2 will check if first mem location of arr1 is the same
 * as the first mem location of arr2
*/

struct NegativeGallons{
    string message;
    double gallons;
};

void display_array(int nums[], int size){
    for(int i = 0; i < size; ++i){
        cout << nums[i] << ' ';
    }
    cout << endl;
}

void caps(char cstr[]){
    int len = strlen(cstr);
    for(int i = 0; i < len; ++i){
        cstr[i] = toupper(cstr[i]);
    }
}

double calcMPG(double miles,double gallons){
    if(miles <= 0.0){
        throw invalid_argument("Error! Miles must be > 0");
    }else if(gallons <= 0){
        NegativeGallons error;
        error.message = "Error! Gallons must be > 0";
        error.gallons = gallons;
        throw error;
    }
    double mpg = miles/gallons;
    mpg = round(mpg*10)/10;
    return mpg;
}
int main(){
    int week[7];


    const int size = 5;
    double prices[size] {9.99,10.32,3.22,8.99,1.30}; //must be a value declared at compile time
 
    auto ptr = prices;

    auto end = prices + size;
    //now algo's can be used

    for(auto p = ptr; p < end; ++p){
        cout << *p << endl;
    }

    // const int rows = 3,cols = 4;

    // int table[rows][cols];

    //c string
    //a c string is a built in array of characters with a null terminator at the end
    //not the same as a string object, string object has no null terminator
    // char greeting[] = {'h','e','l','l','o','\0'};
    // //explicit null terminator
    // char greating[] = "hello";
    // //implicit null terminator

    char state[15] = "";
    cout << "Enter State Name: ";
    cin.getline(state,15);
    if(cin.fail()){
        cin.clear();
        cin.ignore(1000,'\n');
    }
    cout << "State name is " << state << endl << endl;

    int state_size = strlen(state);

    cout << "strlen(state) = " << state_size << endl;

    //strcmp(string1,string2) == 0 means same

    //exceptions
    
    double miles;
    double gallons;
    cout << "Miles? ";
    cin >> miles;
    cout << "Gallons? ";
    cin >> gallons;

    try{
        calcMPG(miles,gallons);
    }catch(const invalid_argument& e){
        cout << e.what() << "\n";
    }catch(const NegativeGallons& e){
        cout << e.message << "\n" << "You entered: " << e.gallons << "\n\n";
    }
    


    return 0;
}