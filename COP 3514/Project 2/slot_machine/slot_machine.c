/*David Hatcher 
This program allows the user to input a starting balance, 
then lets them play a slot machine game. Each turn of the game will
remove 5 credits from their beginning balance and outputs 3 random fruit. 
If they get all 3 of the same fruit they will win 100 credits. This
will continue until the user quits or runs out of funds.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randGen(int min, int max);
void chooseFruit(int value);
void printAllFruit(int fruitOne, int fruitTwo, int fruitThree);
int doesUserQuit();
void displayBalance(int balance);

int main(){
    srand(time(NULL));

    int balance, zeroForQuit;
    printf("Enter initial balance (in cents):");
    scanf("%d",&balance);
    zeroForQuit = doesUserQuit();
    do{
        int randOne = randGen(0,13);
        int randTwo = randGen(0,13);
        int randThree = randGen(0,13);
        printAllFruit(randOne,randTwo,randThree);
        balance -= 5;
        if(randOne == randTwo && randTwo == randThree){
            balance += 100;
        }
        displayBalance(balance);
        zeroForQuit = doesUserQuit();
    }while(balance >= 5 && zeroForQuit != 0);

    if(zeroForQuit == 0){
        printf("\nThanks for playing!\n");
        displayBalance(balance);
    }else if(balance < 5){
        printf("\nInsufficient fund");
    }

    return 0;
}

int randGen(int min, int max){
    return rand() % (max - min + 1) + min;
}

void chooseFruit(int value){
    switch (value)
    {
    case 0:
        printf("Pineapple ");
        break;
    case 1:
        printf("Kiwi ");
        break;
    case 2:
        printf("Apple ");
        break;
    case 3:
        printf("Orange ");
        break;
    case 4:
        printf("Lime ");
        break;
    case 5:
        printf("Peach ");
        break;
    case 6:
        printf("Lemon ");
        break;
    case 7:
        printf("Pear ");
        break;
    case 8:
        printf("Banana ");
        break;
    case 9:
        printf("Cherry ");
        break;
    case 10:
        printf("Grape ");
        break;
    case 11:
        printf("Blueberry ");
        break;
    case 12:
        printf("Blackberry ");
        break;
    case 13:
        printf("Apricot ");
        break;
    default:
        printf("Incorrect Number ");
        break;
    }
}

void printAllFruit(int fruitOne,int fruitTwo, int fruitThree){
    printf("\n");
    chooseFruit(fruitOne);
    chooseFruit(fruitTwo);
    chooseFruit(fruitThree);
    printf("\n");
}

int doesUserQuit(){
    int quit;
    printf("\nWould you like to play (press 1 to play or 0 to quit)?");
    scanf("%d", &quit);
    while(quit < 0 || quit > 1){
        printf("\nIncorrect input please press 1 to play or 0 to quit.");
        scanf("%d", &quit);
    }
    return quit;
}
void displayBalance(int balance){
    printf("\nRemaining Balance: %d\n", balance);
}