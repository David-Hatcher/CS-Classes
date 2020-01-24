#include <iostream>
#include <limits>
#include <vector>
using namespace std;

/**
 * headers come from standard template library
 * 
 * Chapter 3 : How to make decisions
 * tolower(char), toupper(char)
 * ! -> && -> ||
 * switch must be numeric
 * 
 * Chapter 4 : How to code loops
 * 
 * Chapter 6 How to work with data types, strings, and vectors
 * 
 * long long data type 
 * auto data type, implicitly types value
 * const data_type name = value;
 * 
 * type promotion int -> unsigned int -> long -> unsigned long -> float -> double -> long double;
 * 
 * explicity convert
 * static_cast<type>(value)
 * int grade 
 * sizeof(type)
 * 
 * vector
 * 
 * .push_back(value) adds to end
 * .size() give value
 * .front() calls first value
 * .back() calls last value
 * .at(n) gives value at nth index
 * .erase(n) removes nth index
 * .insert(n,value) inserts value at nth index
 * 
 * string
 * 
 * .size()
 * for(char c : name) foreach on a string
 * .size() same as .length()
 * .length() same as .size()
 * .empty() tells if empty string
 * .push_back(char)
 * .pop_back()
 * .back()
 * .front()
 * .at(i)
 * .clear() clear string
 * .find(str) looks for first str in object
 * .find(str,i) looks for first str in object starting at i index
 * .rfind() same starts from back
 * .rfind(str,i) starts from .size() -1 - i index
 * finds return -1 if not there
 * ,find_first_of("value") looks for v a l u e
 * .substr(i) is i to end
 * .substr(i,len) is i to i+len
 * .insert(i,str)
 * .erase(i,len) erase i to i + len
 * .replace(i,str)
 * 
 * char
 * isupper(char)
 * isalpha(char)
 * isalnum(char)
 */

int main(){
    const auto value = 1;
    cout << value;

    int grade = static_cast<int>(93.67);
    cout << endl << grade;

    //auto size = sizeof(unsigned short);

    //cout << size << " bytes \n" << endl;
    auto result1 = numeric_limits<int>::min();
    cout << result1 << endl;

    vector<int> nums(3);
    vector<int> scores = {99,83,22};
    cout << endl << scores[0];

    int sizeScores = scores.size(); //3
    for(int score: scores){
        cout << score << ' ';
    }
    //size can be set at runtime
    //or allowed to dynamically adjust size
    return 0;
}