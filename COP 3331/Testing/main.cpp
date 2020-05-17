#include <iostream>
#include <fstream>

using namespace std;

int main(){

    ofstream output;
    output.open("Player/david.txt");
    output << "Text";
    output.close();

    return 0;
}