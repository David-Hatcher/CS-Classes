#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>

using namespace std;

void function2(){
    throw runtime_error("An Error occurred in function2!");
}

void function1(){
    try{
        function2();
        throw runtime_error("An error occurred in function1!");
    }
    catch(const exception& e){
        cout << "Function1 caught error" << e.what() << "\n\n";
    }
}

int main(){

    try{
        function1();
    }
    catch(const exception& e){
        cout << "Main caught error" << e.what() << "\n\n";
    }

}