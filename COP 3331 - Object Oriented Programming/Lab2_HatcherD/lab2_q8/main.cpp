#include <cctype>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <locale>

using namespace std;

char manipCharacter(char character);
char getCharacter();
char characterOrNumber(char character);
/*Author: David Hatcher
 * Purpose: This program will ask a user to enter a character
 * on each line until they enter 0. It will then print their 
 * characters as one string on the console with all vowels
 * in uppercase and all consonants in lowercase numbers will
 * remain the same.
 */
int main(){
    //initializing variables
    string user_str = ""; //running string containing user manipulated characters
    char user_input;//current character to be added to string

    //looping to grab each character
    do{
        cout << "Enter a character: ";
        user_input = getCharacter();//grab single character and dump buffer
        if(user_input == '0'){//leaving loop on input of 0
            break;
        }
        user_input = manipCharacter(user_input);//determine if character needs to be changed
        user_str += user_input;//add manipulated character to user string
    }while(true);

    cout << "Your String: " << user_str;//print user input string
    return 0;
}

/*function manipCharacter takes a character then 
*if it is a vowel it will force uppercase, if already
*uppercase it will maintain it's case. If the character
*is a consonant then it will force lowercase
 */
char manipCharacter(char character){
    switch(character){
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return toupper(character);
            break; 
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            return character;
            break;
        default:
            return tolower(character);
            break;
    }
}

/*Funtion getCharacter will get a single character from the console
*flush the input buffer
*/
char getCharacter(){
    char character;
    cin >> character;
    cin.ignore(1000,'\n');
    return character;
}

/*characterOrNumber will determine if the input is an alphebtical
*character if alpha then it will run it through manipCharacter
*and then return in input character
*/
char characterOrNumber(char character){
    char ret_char = character;
    if(isalpha(character)){
       ret_char = manipCharacter(character);
    }
    return ret_char;
}
