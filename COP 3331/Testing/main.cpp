#include <iostream>

using namespace std;

int main(){
    int num;
    string opps;
    cout << "Type a number: ";
    cin >> num;
    cout << endl;
    if(cin.fail()){
        cin.clear();
        cin >> opps;
    }
    cout << "num = " << num << endl; 
    cout << "opps = " <<  opps << endl;
}