#include <iostream>
#include <string>

using namespace std;

char getCharacter(){
    char character;
    cin >> character;
    cin.ignore(1000,'\n');
    return character;
}

void skipLine(){
    cout << endl;
}

char manipCharacter(char character){
    switch(character){
        case 'a':
            return toupper(character);
            break;
        case 'e':
    }
}

int main(){

    string user_str = "";
    char user_input;

    do{
        cout << "Enter a character: ";
        user_input = getCharacter();
        skipLine();
        switch(user_input){
            case 'a' :

        }
    }while(user_input != '0');

    return EXIT_SUCCESS;
}