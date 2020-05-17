#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>
#include <map>
#include "Item.h"

class Player{

private:
    std::string name;
    std::vector<Item> inventory;
    std::string journal;
    std::map<std::string,bool> flags;

public:

    Player(std::string name);
    
    void setFlag(std::string,bool);
    void setJournal(std::string);
    void setName(std::string);

    std::string getName();
    std::string getJournal();

    bool checkFlags(std::string);
    bool checkInventory(Item&);
    void addToInventory(Item);

};

#endif
