#include <string>
#include "Card.h"

//setters
void Card::setRank(std::string rank){
    this->rank = rank;
}
void Card::setSuit(std::string suit){
    this->suit = suit;
}

//getters
std::string Card::getRank() const{
    return this->rank;
}
std::string Card::getSuit() const{
    return this->suit;
}

//member functions
/**
 * getCardName returns the name of the card with formatting
*/
std::string Card::getCardName() const{
    return this->rank + " of " + this->suit;
}