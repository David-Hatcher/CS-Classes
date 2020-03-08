#include "RandomIntVector.h"
#include <iostream>


using namespace std;

int main(){
    
    RandomIntVector randoms(12);

    cout << randoms.get_str();

    return 0;
}