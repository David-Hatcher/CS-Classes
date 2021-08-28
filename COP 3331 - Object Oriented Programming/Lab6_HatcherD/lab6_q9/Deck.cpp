#include "Card.h"
#include "Deck.h"
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>


    //constructor
    Deck::Deck(){
        this->createDeck();
    }

    //private member functions

    int Deck::create_random(int i){
        return rand() % i;
    }
    //public member functions

    /**
     * shuffleDeck() shuffles the deck
    */
    void Deck::shuffleDeck(){
        srand(time(nullptr));
        auto b = this->cards.begin();
        auto e = this->cards.end();
        std::random_shuffle(b,e,this->create_random);
    }

    /**
     * createDeck() initializes and deck
    */
    void Deck::createDeck(){
        auto suits_b = this->suits.begin(), suits_e = this->suits.end(), ranks_b = this->ranks.begin(), ranks_e = this->ranks.end();
        for(auto i = suits_b; i < suits_e; ++i){
            for(auto j = ranks_b; j < ranks_e; ++j){
                Card current_card;
                current_card.setSuit(*(i));
                current_card.setRank(*(j));
                this->cards.push_back(current_card);
            }
        }
    }
    /**
     * getCard returns a single card from the deck and removes it
    */
    Card Deck::getCard(){
        Card card = this->cards.at(0);
        this->cards.erase(cards.begin());
        return card;
    }
    /**
     * getCount returns the count of the deck.
    */
    int Deck::getCount(){
        return this->cards.size();
    }