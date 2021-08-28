#include "Player.h"
#include <string>

    //constructors
    Player::Player(){}
    Player::Player(std::string name){
        setName(name);
        this->journal_default = "I spoke with Emily's mother and she said that emily kept a diary. It was never entered into evidence so maybe that will have some clue as to where she has gone. Most people write in their journals before bed, her bedroom is probably the best place to look.\n\n";
    }

    //returns a string containing the inventory
    std::string Player::showInventory(){
        if(this->inventory.size() == 0){
            return "You inventory is empty.\n\n";
        }else{
            std::string inv_string = "";
            int count = 1;
            for(auto i = this->inventory.begin(); i != this->inventory.end(); ++i){
                inv_string += std::to_string(count++) + ". " + (*i).getName() + '\n' + (*i).getDescription() + "\n\n";
            }
            return inv_string;
        }
    }
    
    //sets a flag on the player
    void Player::setFlag(std::string flag_name,bool value){
        auto iter = this->flags.find(flag_name);
        if(iter == this->flags.end()){
            this->flags.insert({flag_name,value});
        }else{
            iter->second = value;
        }
    }

    //journal setter
    void Player::setJournal(std::string entry){
        this->journal = entry;
    }
    ///adds string to journal
    void Player::addJournal(std::string entry){
        this->journal += '\n' + entry + '\n';
    }
    //sets player name
    void Player::setName(std::string name){
        this->name = name;
    }
    //gets player name
    std::string Player::getName(){
        return this->name;
    }
    //gets journal_default
    std::string Player::getJournalDefault(){
        return this->journal_default;
    }
    //gets information in journal
    std::string Player::getJournal(){
        return this->journal;
    }
    //checks the value of a flag
    bool Player::checkFlags(std::string flag){
        for(auto i = flags.begin(); i != flags.end(); i++){
            if((*i).first == flag){
                return (*i).second;
            }
        }
        return false;
    }
    //checks inventory for an item
    bool Player::checkInventory(Item& item){
        for(auto i = this->inventory.begin(); i < this->inventory.end(); ++i){
            if(*(i) == item){
                return true;
            }
        }
        return false;
    }
    //adds an item to the players inventory
    void Player::addToInventory(Item i){
        this->inventory.push_back(i);
    }