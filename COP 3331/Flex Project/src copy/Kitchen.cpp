#include "Kitchen.h"

Kitchen::Kitchen(std::string file_path,Player& player) : Room(file_path){
    this->items.push_back(buildItem("Flash Light"));
}
void Kitchen::setDescription(Player& player){
    readDescription();
    this->description = this->room_description;
    Interactive drawers("Kitchen Drawers","Kitchen Drawers");
    addInteractive("drawer",drawers);
}
void Kitchen::addInteractive(std::string name,Interactive interactive){
    this->interactives.insert(std::pair<std::string,Interactive>(name,interactive));
}
std::string Kitchen::interactWith(std::string action,std::string name,Player& player){
    auto i = this->interactives.begin();
    for(; i != this->interactives.end(); ++i){
        if((*i).first == name){
            break;
        }
    }
    if(i == this->interactives.end()){ return "You can't do anything with that item.";}
    if(action == "check"){
        return getFlashLight(player);
    }
    return "Huh?";
}
void Kitchen::readDescription(){
    this->room_description = readFile("Rooms/" + file_path + "/" + file_path + "desc.txt");
}
std::string Kitchen::getFlashLight(Player& player){
    if(player.checkInventory(this->items.at(0))){
        return "The drawer is empty, looks like whatever was here was already taken.";
    }else{
        player.addToInventory(this->items.at(0));
        return "You find a Flash Light in the drawer.";
    }
}