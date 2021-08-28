#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

char getCharacter();


/*Author: David Hatcher
*Purpose: This program will allow a user to guess at a number
*that the program is self determines between 1 and 10
*once guessed it will allow the user to continue and play
*again if they wish
*/
int main() {
    int upper_limit = 10;
    cout << "Guess the number!\n";
    cout << "I'm thinking of a number from 1 to " << upper_limit << "\n\n";
    char cont;
    // get a random number between 1 and the upper limit
    srand(time(NULL));              // seed the rand() function
    do{
        int number = rand() % upper_limit; // number is >= 0 and < upper_limit
        ++number;                          // number is >= 1 and <= upper_limit

        int count = 0;//initialize count at 0
        int guess;//initiallizing guess, for user guess
        //
        do{
            cout << "Your guess: ";
            cin >> guess;

            if (guess < 1 || guess > upper_limit) {
                cout << "Invalid guess. Try again." << endl;
                continue;
            }

            if (guess < number) {
                cout << "Too low.\n";
            }
            else if (guess > number) {
                cout << "Too high.\n";
            }
            ++count;
        }while (guess != number);
        cout << "You guessed it in " << count << " tries.\n\n";
        cout << "Would you like to play again (y/n)?: ";
        cont = tolower(getCharacter());//calling getCharacter to get the input

    }while(cont == 'y');

    cout << "Bye!\n\n";

    return 0;
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