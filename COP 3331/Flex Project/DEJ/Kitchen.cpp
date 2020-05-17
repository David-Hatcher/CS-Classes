#include "Kitchen.h"

Kitchen::Kitchen(){}
Kitchen::Kitchen(std::string file_path,Player& player) : Room(file_path){
    this->items.push_back(Helper::buildItem("Flash Light"));
    Interactive drawers("Kitchen Drawers","Kitchen Drawers");
    addInteractives("drawers",drawers);
    setDescription(player);
}
void Kitchen::setDescription(Player& player){
    readDescription();
    this->description = this->room_description;

}
std::string Kitchen::interactWith(std::string action,std::string name,Player& player){
    auto i = this->interactives.begin();
    for(; i != this->interactives.end(); ++i){
        if((*i).first == name){
            break;
        }
    }
    if(i == this->interactives.end()){ return "You can't do anything with that item.\n";}
    if(action == "check" || action == "open"){
        return getFlashLight(player);
    }
    return "Huh?\n";
}
void Kitchen::readDescription(){
    this->room_description = Helper::readFile("Rooms/" + file_path + "/" + file_path + "desc.txt");
}
std::string Kitchen::getFlashLight(Player& player){
    if(player.checkInventory(this->items.at(0))){
        return "The drawer is empty, looks like whatever was here was already taken.\n";
    }else{
        player.addJournal("I found a flash light, I should be able to see if any rooms are dark now.");
        player.addToInventory(this->items.at(0));
        player.setFlag("Has_Flashlight",true);
        return "You find a Flash Light in the drawer. You put the flash light in your pocket.\n";
    }
}