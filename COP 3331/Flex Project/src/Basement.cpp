#include "Basement.h"



Basement::Basement(std::string file_path,Player& player) : Room(file_path){
    readDescriptions();
    this->items.push_back(Game::buildItem("Mirror Key"));
    Interactive lockBox("LockBox","Lock Box");
    this->interactives.insert(std::pair<std::string,Interactive>("lock box",lockBox));
}
void Basement::setDescription(Player& player){
    updateDescription(player);
}
void Basement::addInteractive(std::string name,Interactive interactive){
    this->interactives.insert(std::pair<std::string,Interactive>(name,interactive));
}
std::string Basement::interactWith(std::string action,std::string name,Player& player){
        auto i = this->interactives.begin();
        for(; i != this->interactives.end(); ++i){
            if((*i).first == name){
                break;
            }
        }
        if(i == this->interactives.end()){ return "You can't do anything with that item.";}
        if(action == "check" || action == "open"){
            return openLockBox(player);            
        }
        return "Huh?";
}

void Basement::readDescriptions(){
    this->lit_description = Game::readFile("Rooms/" + this->file_path + "/" + this->file_path + "desclit.txt");
    this->dark_description = Game::readFile("Rooms/" + this->file_path + "/" + this->file_path + "descdark.txt");
}
std::string Basement::openLockBox(Player& player){
    player.addToInventory(items.at(0));
    return "You open the lockbox and find a strange metallic key, as you pick the key up you realize it is covered in a mirrored coating and is cold to the touch.";
}
void Basement::updateDescription(Player& player){
    this->description = player.checkFlags("Has_Flashlight") ? this->lit_description : this->dark_description;
}