#include "RandomIntVector.h"
#include <iomanip>
#include <iostream>
#include <limits>


using namespace std;
const string TITLE = "Random Integer List";
const string COUNT_QUESTION = "How many random integers should the list container?: ";
const string CONTINUE_STRING = "Continue? (y/n): ";

void printTitle(string output);
void askCount(int& count,string output);
void printNumbers(RandomIntVector randoms);
void printCount(RandomIntVector randoms);
void printTotal(RandomIntVector randoms);
void printAverage(RandomIntVector randoms);
bool askContinue(string output);


/**
 * Author: David Hatcher
 * Purpose: This program allows the user to enter a number and creates 
 * a RandomIntVector with that many values and then prints those values
 * along with the sum, average, and count of those values
*/
int main(){
    printTitle(TITLE);
    int count;
    bool cont = true;
    
    while(cont){
        askCount(count, COUNT_QUESTION);
        RandomIntVector rand_ints(count);
        printNumbers(rand_ints);
        printCount(rand_ints);
        printTotal(rand_ints);
        printAverage(rand_ints);
        cont = askContinue(CONTINUE_STRING);
    }


    cout << "Bye!" ;

    return 0;
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
 * printTitle prints the title of the program
*/
void printTitle(string output){
    cout << left << output << endl << endl;
}

/**
 * askCount requets the user to enter a count of vectors
 * this also handles cin errors and incorrect input
*/
void askCount(int& count, string output){
    int testCount;
    cout << output;
    cin >> testCount;
    if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << left << "Invalid input, please enter a number!" << endl << endl;
        askCount(count,output);
    }else{
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        count = testCount;
    }
}

/**
 * printNumbers takes a RandomIntVector and prints all of the values in the vector
*/
void printNumbers(RandomIntVector randoms){
    cout << setw(10) << "Integers:" << randoms.get_str() << endl;
}

/**
 * printCount takes a RandomIntVector prints the count of the numbers in the vector
*/
void printCount(RandomIntVector randoms){
    cout << setw(10) << "Count:" << randoms.size() << endl;
}

/**
 * printTotal takes a RandomIntVector and prints the sum of the values
*/
void printTotal(RandomIntVector randoms){
    cout << setw(10) << "Total:" << randoms.get_sum() << endl;
}

/**
 * printAverage takes a RandomIntVector and prints the average of the values in the vector
*/
void printAverage(RandomIntVector randoms){
    cout << setw(10) << "Average:" << randoms.get_avg() << endl;
}