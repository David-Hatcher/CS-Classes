#include <iostream>
#include <string>

using namespace std;

string testStrength(string password);
string rankPassword(int numbers, int punct, int letters, int caps);

/* Author: David Hatcher
 * Purpose: This program will allow a user to enter a password
 * then based on the ranking system in rankPassword it will 
 * present the user with a rating of Weak, Medium, or Hard 
 */
int main(){
    string password;

    cout << "Password Analyzer" << endl << endl;
    cout << "Enter Password: ";

    cin >> password; //grab string from buffer
    string strength = testStrength(password); //test password strength
    cout << endl << "Strength: " << strength << endl << endl << "Bye!";

    return 0;
}
/* testStrength takes a string and will iterate 
 * through the password string counting each 
 * alpha character, uppercase alpha character, 
 * number, and punctuation in the string. Then 
 * passes these values rankPassword and returns
 * value
 */
string testStrength(string password){
    int punct = 0;
    int letters = 0;
    int numbers = 0;
    int caps = 0;    
    for(int i = 0; i < password.length(); i++){
        if(ispunct(password[i])){punct++;}
        if(isalpha(password[i])){
            letters++;
            if(password[i] == toupper(password[i])){
                caps++;
            }    
        }
        if(isdigit(password[i])){numbers++;}
    }
    return rankPassword(numbers,punct,letters,caps);
}
/* rankPassword takes 4 integers numbers, punct, letters, and caps
 * it will then give a ranking to the password represented by
 * these values. If the password contains atleast 4 numbers, 3 
 * punctuation characters, and 8 alpha characters, at least 2 of which
 * are capitalized, it will rank it as a "Hard" password. If it only 
 * contains at least 2 numbers, 1 punctuation, and 5 letters, at least
 * 1 of which is capitalized, it will rank it as a "Medium" password.
 * All other scores will be ranked as "Weak".
 */
string rankPassword(int numbers, int punct, int letters, int caps){
    if(numbers >= 4 && punct >= 3 && letters >= 8 && caps >= 2){
        return "Hard";
    }else if(numbers >= 2 && punct >= 1 && letters >= 5 && caps >= 1){
        return "Medium";
    }else{
        return "Weak";
    }
}