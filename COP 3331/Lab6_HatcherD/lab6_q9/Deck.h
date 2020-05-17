#ifndef DECK_H
#define DECK_H
#include <string>
#include <vector>
#include "Card.h"

class Deck{

private:
    std::vector<std::string> suits{"Clubs","Diamonds","Hearts","Spades"};
    std::vector<std::string> ranks{"2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace"};
    std::vector<Card> cards;

    //private methods
    static int create_random(int);
public:

    //constructor
    Deck();

    //member functions
    void shuffleDeck();
    void createDeck();
    Card getCard();
    int getCount();


    
};
#endif