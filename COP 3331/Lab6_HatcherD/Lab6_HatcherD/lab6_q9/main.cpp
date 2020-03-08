#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <algorithm>
#include "Card.h"
#include "Deck.h"

using namespace std;

int const DECK_COUNT_MAX = 52;

void printCard(Card card);
void printAllCards(vector<Card> cards);
int getNumber(string output);
void displayTitle();
void shuffleDeck(Deck& deck);
void printCount(Deck deck);


/**
 * Author: David Hatcher
 * Purpose: This program uses the Deck and card classes to
 * create a hand of cards. It first asks the user how many cards
 * they'd like, then it will deal them that specified number of 
 * cards from a randomized deck.
*/
int main(){
    displayTitle();
    vector<Card> hand;
    Deck deck;
    shuffleDeck(deck);
    int number_of_cards = getNumber("How many cards would you like?: ");
    for(int i = 0; i < number_of_cards; ++i){
        hand.push_back(deck.getCard());
    }
    printAllCards(hand);

}

/**
 * printCard takes a card object and prints the name
*/
void printCard(Card card){
    cout << card.getCardName() << endl;
}

/**
 * printAllCards takes a vector of cards and prints
 * all of the cards
*/
void printAllCards(vector<Card> cards){
    auto b = cards.begin();
    auto e = cards.end();
    for_each(b,e,[](Card card){printCard(card);});
}

/**
 * getNumber gets the number of cards the user would like
*/
int getNumber(string output){
    int number;
    cout << output;
    cin >> number;
    if(cin.good()){
        if(number <= 0 || number > DECK_COUNT_MAX){
            cout << "Number must be between 1 and " + to_string(DECK_COUNT_MAX) + ", inclusive." << endl;
            number = getNumber(output);
        }
    }else{
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        number = getNumber(output);
    }
    return number;
}

/**
 * displayTitle displays the title of the program
*/
void displayTitle(){
    cout << "Card Dealer" << endl << endl;
}

/**
 * shuffleDeck takes a deck and shuffles it
 * then outputs confirmation to the console.
*/
void shuffleDeck(Deck& deck){
    deck.shuffleDeck();
    cout << "I have shuffled a deck of " + to_string(deck.getCount()) + " cards." << endl << endl;
}