#include "Player.h"
#include <string>

    Player::Player(std::string name){
        setName(name);
        this->journal = "";
    }
    
    void Player::setFlag(std::string flag_name,bool value){
        auto iter = this->flags.find(flag_name);
        if(iter == this->flags.end()){
            this->flags.insert({flag_name,value});
        }else{
            iter->second = value;
        }
    }
    void Player::setJournal(std::string entry){
        this->journal += entry;
    }
    void Player::setName(std::string name){
        this->name = name;
    }

    std::string Player::getName(){
        return this->name;
    }
    std::string Player::getJournal(){
        return this->journal;
    }

    bool Player::checkFlags(std::string flag){
        return this->flags[flag];
    }
    bool Player::checkInventory(Item& item){
        for(auto i = this->inventory.begin(); i < this->inventory.end(); ++i){
            if(*(i) == item){
                return true;
            }
        }
        return false;
    }
    void Player::addToInventory(Item i){
        this->inventory.push_back(i);
    }