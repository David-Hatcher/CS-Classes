#include "Room.h"

Room::Room(){}
Room::Room(std::string file_path){
    this->file_path = file_path;
    setName(Game::readFile("Rooms/" + file_path + "/" + file_path + ""));
}
std::string Room::getName() const{
    return this->name;
}
void Room::setName(std::string name){
    this->name = name;
}
void Room::setDescription(std::string description){
    this->description = description;
}
std::string Room::getDescription() const{
    return this->description;
}
void Room::addInteractives(std::string name,Interactive interactive){
    this->interactives.insert(std::pair<std::string, Interactive>(name,interactive));
}
std::map<std::string,Interactive> Room::getInteractives() const{
    return this->interactives;
}
void Room::setExits(){
    //still needs to be written.
}
std::vector<Room> Room::getExits() const{
    return this->exits;
}
void Room::addExit(Room room){
    this->exits.push_back(room);
}
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