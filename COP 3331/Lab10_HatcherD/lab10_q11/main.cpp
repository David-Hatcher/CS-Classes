#include <iostream>
#include <vector>
#include "Pet.h"

using namespace std;

void displayTitle();
void printPet(const Pet&);
void printPets(vector<Pet*>);
string getInput(string);
void closeProgram(vector<Pet*>);
template<typename T>
void printLine(T output);
template<typename T>
void print(T output);
template<typename T>
T getInput(string output);



int main(){
    displayTitle();
    vector<Pet*> pets;
    char another = 'y';
    while(another == 'y' || another == 'Y'){
        Pet* current_pet = new Pet(getInput<string>("Enter the pet's name: "),getInput<string>("Enter the pet's species: "));
        another = getInput<char>("Add another pet? (y/n): ");
        pets.push_back(current_pet);
        printLine("");
    }
    printPets(pets);
    closeProgram(pets);  
    printLine("\nBye!");
    return 0;
}

void displayTitle(){
    printLine("Dynamic Pets\n");
}

template<typename T>
void printLine(T output){
    cout << output << endl;
}

template<typename T>
void print(T output){
    cout << output;
}
template<typename T>
T getInput(string output){
    print(output);
    T input;
    cin >> input;
    cin.ignore(1000,'\n');
    return input;
}

void printPet(const Pet& p){
    print(p.getName());
    printLine(" is a(n) " + p.getSpecies());
}

void printPets(vector<Pet*> pets){
    for(Pet* p: pets){
        printPet(*p);
    }
}


void closeProgram(vector<Pet*> pets){
    for(Pet* p: pets){
        delete p;
    }
}