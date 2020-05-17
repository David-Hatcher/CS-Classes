#ifndef CARD_H
#define CARD_H
#include <string>


class Card{

private:

    std::string rank;
    std::string suit;

public:
    //setters
    void setRank(std::string);
    void setSuit(std::string);

    //getters
    std::string getRank() const;
    std::string getSuit() const;
    
    //member functions
    std::string getCardName() const;
};

#endif