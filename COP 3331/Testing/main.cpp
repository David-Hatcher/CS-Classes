#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    vector<string> names_1 {"Mike", "Ben","Joel","Anne"};
    vector<string> names_2 { "Judy", "Samantha", "Kelly" };

    names_1.insert(names_1.end(), "Mary");
    names_1.erase(names_1.begin());
    names_1.insert(names_1.begin() + 2, ++names_2.begin(), names_2.end());
    names_1.swap(names_2);
    names_1.erase(++names_1.begin());
    names_1.insert(names_1.begin(), ++names_2.begin(), names_2.begin() + 2);



    for(string name : names_1){
        cout << name << ", ";
    }

    // vector<string> names_1 { "Joel" ,"Judy",  "Kelly" };
    // vector<string> names_2 { "Ben","Joel", "Samantha", "Kelly","Anne","Mary"};

}