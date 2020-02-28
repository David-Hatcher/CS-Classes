#include <iostream>
#include <list>
#include <ctime>
#include <algorithm>
#include <limits>

/*Declaring constants*/
const int LIST_COUNT = 10, RANDOM_MIN = 1, RANDOM_MAX = 100, END_VALUE = 0;

using namespace std;

/**
 * struct Guess is for user input
*/
struct Guess{
    int number = -1;//initializing number outside of range
    int max = RANDOM_MAX;//max value
    int min = RANDOM_MIN;//min value
    int end_val = END_VALUE;// end value
    void getNumber();
    bool validateNumber(int num);
};

template<typename T>
void printList(list<T> value, string label);
int generateRandom(int min, int max);
list<int> generateRandomList(int count,int min,int max);

int main(){
    srand(time(nullptr));   //setting random seed
    list<int> randoms = generateRandomList(LIST_COUNT,RANDOM_MIN,RANDOM_MAX);   //generate list of numbers
    randoms.sort();     //sorting numbers for binary search
    printList(randoms,"Random numbers");    //print list of randoms
    //declare iterators for randoms list
    auto b = randoms.begin();
    auto e = randoms.end();
    string in_list_response;    //creating string for NOT in list value
    while(true){
        in_list_response = "";
        Guess current_guess;    //initialize user guess object
        while(current_guess.number == -1){  
        //value is initialized at -1 and only sets once a valid number is input
            current_guess.getNumber();
        }
        if(current_guess.number == END_VALUE){  //loop end value ends loop
            break;
        }else{  //if loop is not over then check if value is there
            if(!binary_search(b,e,current_guess.number)){//if it's not then assign NOT to in list response
                in_list_response = "NOT ";
            }
        }
        //print out response
        cout << current_guess.number << " is " << in_list_response << "in random numbers." << endl << endl;

    }
    cout << "Bye!";
    return 0;
}

/**
 * generateRandom takes two integers, min and max,
 * and returns a random number between those two numbers
 * inclusive of the min and max
*/
int generateRandom(int min, int max){
    return (rand() % ((max - min) + 1)) + min;
}

/**
 * generateRandomList takes in a count, a min value, and max value,
 * and creates a list of random integers from the min value to the max value
*/
list<int> generateRandomList(int count, int min, int max){
    list<int> random_list(count);
    for_each(random_list.begin(),random_list.end(),[=](int &val){val = generateRandom(min,max);});
    return random_list;
}

/**
 * printList takes a list of any type and a string
 * label of the list and prints out of values of that list
*/
template<typename T>
void printList(list<T> value, string label){
    auto first = value.begin();
    auto last = value.end();
    cout << label <<": [";
    for_each(first,--last,[](int val){cout << val << ", ";});
    //need to have this to not have extra comma
    cout << *(last) << "]" << endl << endl;

}

/**
 * the struct Guess member function getNumber
 * asks the user for a number 
*/
void Guess::getNumber(){
    cout << "Enter a number from " << min << " to " << max <<": ";
    int prevalid_number;
    cin >> prevalid_number;
    if(cin.fail()){//check for fail on cin
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Invalid input, please enter a number." << endl << endl;
    }else{//value was a interger
        if(validateNumber(prevalid_number)){//check if input is valid
            number = prevalid_number;
        }else{
            cout << "Number must be in range [" << min << "," <<  max << "]" << endl << endl;
        }
    }
}

/**
 * the struct Guess member function validateNumber takes
 * an interger number and determines if it is within the range
 * of min and max or if it is the end loop value and returns
 * a boolean
*/
bool Guess::validateNumber(int num){
    if((num <= max && num >= min) || num == end_val){
        return true;
    }
    return false;
}