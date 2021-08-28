#include "Room.h"
#include "Helper.h"

//constructors
Room::Room(){}
Room::Room(std::string file_path){
    this->file_path = file_path;
    setName(Helper::readFile("Rooms/" + file_path + "/" + file_path + ".txt"));
}

//getter for name
std::string Room::getName() const{
    return this->name;
}
//setter for name
void Room::setName(std::string name){
    this->name = name;
}
//setter for description
void Room::setDescription(Player& player){
    this->description = description;
}
//getter for description
std::string Room::getDescription() const{
    return this->description;
}
//adds an interactive object to the interactives map
void Room::addInteractives(std::string name,Interactive interactive){
    this->interactives.insert(std::pair<std::string, Interactive>(name,interactive));
}
//returns the interactives map
std::map<std::string,Interactive> Room::getInteractives() const{
    return this->interactives;
}
//returns the exits vector
std::vector<Room*> Room::getExits() const{
    return this->exits;
}
//adds an exit to the exits vector
void Room::addExit(Room* room){
    for(Room* exit: exits){
        if((*exit).getName() == (*room).getName()){
            return;
        }
    }
    this->exits.push_back(room);
}
//allows for interaction with the interactive objects
std::string Room::interactWith(std::string action, std::string name, Player& player){
    auto i = this->interactives.begin();
    for(; i != this->interactives.end(); ++i){
        if((*i).first == name){
            break;
        }
    }
    if(i == this->interactives.end()){ return "Huh?";}
    if(action == "get"){
        player.addToInventory(items.at(0));
        return items.at(0).getName() + " Added to inventory";
    }
    return "huh?";
}