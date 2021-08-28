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
    std::string journal_default;
    std::map<std::string,bool> flags;

public:
    Player();
    Player(std::string name);
    
    void setFlag(std::string,bool);
    void setJournal(std::string);
    void addJournal(std::string);
    void setName(std::string);

    std::string getName();
    std::string getJournal();
    std::string getJournalDefault();

    bool checkFlags(std::string);
    bool checkInventory(Item&);
    void addToInventory(Item);
    std::string showInventory();
    friend bool loadData(std::string,Player&);
    friend bool saveData(std::string,Player&);

};

#endif
