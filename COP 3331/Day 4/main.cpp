//Header directives
#include <iostream>
#include <limits>
#include <iomanip>
#include <fstream>
#include <sstream>


using namespace std;

/*
 *
 * Chapter 6 How to work with I/O streams and files 
 * 
 * The error bits of a stream object
 * ios::eofbit end of file
 * ios::failbit failed operation, type incompatibility, cannot find file
 * ios::badbit operation failed and stream corrupted
 * ios::goodbit everything worked as planned
 * common stream manipulators
 * endl
 * setw(n) sets num of chars in column
 * left flushes text to left
 * right ...
 * setprecision(n) sets floating point sig figs
 * fixed shows specific # of digits after dec
 * show point gives all sig figs after number
 * #include <iomanip> to use these
 * aligning columns with tabs
 * 
 * ifstream
 * ofstream
 * fstream
 * open(filename
 * close())
 * 
 * istringstream
 * ostringstream
 * stringstream
 * 
 * str()
 * str(string)
 * 
 * #include <sstream>
*/


int main(){

    //cin.ignore(numeric_limits<streamsize>::max(),'\n');//this dumps the entire stream until we see a new line character
    double num;
    cout << "Enter Number: ";
    // if(cin >> num){
    //     cout << "Your number is " << num << endl;
    // }else{
    //     cout << "That's not a valie number1\n";
    // }
    cin >> num;
    if(cin.good()){
        cout << "Your number is " << num << endl;
    }else if(cin.fail()){//fail must go after eof if you're checking for eof
        cout << "That's not a valid number! Try again. \n";
    }else if(cin.bad()){
        cout << "An unrecoverable error has occurred. Bye!\n";
    }

    cout << left; //sticky, you need to cout << right; to change

    cout << setw(10) << "Previous" << setw(10) << right << "Current" << endl;
    cout << left << setw(10) << 305 << setw(10) << right << 234 << endl;
    cout << left << setw(10) << 5058 << setw(10) << right << 5084 << endl;


    cout << fixed << setprecision(2) << 10.125 << endl << 19.6 << endl << 42.0 << endl;

    double d3 = 4500.0;
    cout << setprecision(8) <<
    d3 << endl << showpoint << d3 << endl;

    // ifstream input_file; //read
    // ofstream output_file; //write
    // input_file.open("day3.txt", ios::app/*append mode*/);
    // input_file.close();

    ifstream input_file;
    string filename1 = "temp.txt";
    

    ofstream output_file;
    string filename = "temp.txt";
    output_file.open(filename);
    output_file << 4.823 << endl;
    output_file.close();
    return 0;
}