#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    vector<int> nums;
    int sum = 0;
    int currentNum = -1;
    int i = 5;
    while(currentNum != 0){
        cout << "Enter a Number: ";
        cin >> currentNum;
        sum += currentNum;
    }
    cout << "Average = " << (double)sum/i;
}