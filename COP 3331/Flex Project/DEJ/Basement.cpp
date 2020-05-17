#include "Basement.h"

//constructors
Basement::Basement(){}
Basement::Basement(std::string file_path,Player& player) : Room(file_path){
    readDescriptions();
    this->items.push_back(Helper::buildItem("Mirror Key"));
    Interactive lockBox("LockBox","Lock Box");
    addInteractives("lockbox",lockBox);
}
//sets dsecription
void Basement::setDescription(Player& player){
    updateDescription(player);
}
//allows for interaction with interactive objects in the room
std::string Basement::interactWith(std::string action,std::string name,Player& player){
        auto i = this->interactives.begin();
        for(; i != this->interactives.end(); ++i){
            if((*i).first == name){
                break;
            }
        }
        if(i == this->interactives.end()){ return "You can't do anything with that item.\n\n";}
        if(action == "check" || action == "open"){
            return openLockBox(player);            
        }
        return "Huh?";
}
//gets the room descriptions
void Basement::readDescriptions(){
    this->lit_description = Helper::readFile("Rooms/" + this->file_path + "/" + this->file_path + "desclit.txt");
    this->dark_description = Helper::readFile("Rooms/" + this->file_path + "/" + this->file_path + "descdark.txt");
}
//allows for interaction with the lockbox interactive object
std::string Basement::openLockBox(Player& player){
    Item lockbox_key =  Helper::buildItem("Lockbox Key");
    if(!player.checkInventory(lockbox_key)){
        return "The box is locked, the mirror on the box looks extremely similar to the one on the drawer in the entrance.";
    }else if(!player.checkInventory(items.at(0))){
        player.addToInventory(items.at(0));
        player.addJournal("I found a strange key that looks metallic and reflective, maybe this is the key from her journal?");
        return "You open the lockbox and find a strange metallic key, as you pick the key up you realize it is covered in a mirrored coating and is cold to the touch.\n\n";
    }else{
        return "The lockbox is empty.\n\n";
    }

}
//updates the description based on player flags
void Basement::updateDescription(Player& player){
    this->description = player.checkFlags("Has_Flashlight") ? this->lit_description : this->dark_description;
}