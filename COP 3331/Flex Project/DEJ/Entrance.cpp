#include "Entrance.h"

Entrance::Entrance() : Room(){}

Entrance::Entrance(std::string file_path,Player& player): Room(file_path){
    readDescription();
    setDescription(player);
    Interactive door("Door","Door");
    Interactive drawers("Entrance Drawers","Entrance Drawers");
    addInteractives("drawer",drawers);
    addInteractives("door",door);
    items.push_back(Helper::buildItem("Lockbox Key"));
}
void Entrance::setDescription(Player& player){
    updateDescription(player);
}

std::string Entrance::interactWith(std::string action,std::string name,Player& player){
    auto i = this->interactives.begin();
    for(; i != this->interactives.end(); ++i){
        if((*i).first == name){
            break;
        }
    }
    if(i == this->interactives.end()){ return "You can't do anything with that item.";}

    if((action == "check" || action == "open") && (*i).first == "drawer"){
        return checkDrawer(player);
    }else if(action == "open" && (*i).first == "door"){
        return openDoor(player);
    }
    return "Huh?";
}
void Entrance::readDescription(){
    this->no_beast_description = Helper::readFile("Rooms/" + file_path + "/" + file_path + "nobeastdescription.txt");
    this->beast_description = Helper::readFile("Rooms/" + file_path + "/" + file_path + "beastdescription.txt");
}
std::string Entrance::openDoor(Player& player){
    if(player.checkFlags("Mirror_broken")){
        player.setFlag("Beaten_game",true);
        return "As you turn the door nob you feel the warmth from the sun outside move into the doorway. With a smile on her face, Emily thanks you for helping her escape and see the light of day again. \n\n";
    }else if(!player.checkFlags("Has_released_emily")){
        return "You need to find clues as to what happened to Emily.\n";
    }else{
        return "You cannot do that, the beast is in the way.\n";
    }
}
std::string Entrance::checkDrawer(Player& player){
    if(!player.checkInventory(items.at(0))){
        player.addJournal("I found what looks to be a lockbox key, I wonder what this opens.");
        player.addToInventory(items.at(0));
        return "You find a key that looks like it could fit a lockbox. You put the key in your pocket.\n";
    }else{
        return "There is nothing of interest in this drawer.\n";
    }
}
void Entrance::updateDescription(Player& player){
    if(player.checkFlags("Has_released_emily") && !player.checkFlags("Mirror_broken")){
        this->description = this->beast_description;
    }else{
        this->description = this->no_beast_description;
    }
}
