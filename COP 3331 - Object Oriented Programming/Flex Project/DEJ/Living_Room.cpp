#include "Living_Room.h"


Living_Room::Living_Room(){}

Living_Room::Living_Room(std::string file_path,Player& player) : Room(file_path){
    Interactive drawers("Entrance Drawers","Entrance Drawers");
    setDescription(player);
    addInteractive("drawer",drawers);
    this->items.push_back(Helper::buildItem("Hammer"));
}
void Living_Room::setDescription(Player& player){
    this->readDescription();
    this->description = this->room_description;
}
void Living_Room::addInteractive(std::string name,Interactive interactive){
    this->interactives.insert(std::pair<std::string,Interactive>(name,interactive));
}
std::string Living_Room::interactWith(std::string action,std::string name,Player& player){
    auto i = this->interactives.begin();
    for(; i != this->interactives.end(); ++i){
        if((*i).first == name){
            break;
        }
    }
    if(i == this->interactives.end()){ return "You can't do anything with that item.";}
    if(action == "check" || action == "open"){
        return getHammer(player);
    }
    return "Huh?\n";
}
void Living_Room::readDescription(){
    this->room_description = Helper::readFile("Rooms/" + file_path + "/" + file_path + "desc.txt");
}
std::string Living_Room::getHammer(Player& player){
    if(!player.checkInventory(this->items.at(0))){
        player.addJournal("I found a hammer, maybe I can break something if I need to. Or just hang a picture");
        player.addToInventory(this->items.at(0));
        return "You find a hammer that could easily BREAK a mirror. You put the hammer in your pocket.\n";
    }else{
        return "You find nothing of interest in the drawer.\n";
    }
}