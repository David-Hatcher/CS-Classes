#include <string>
#include "Bedroom.h"


Bedroom::Bedroom(std::string file_path, Player& player) : Room(file_path){
    readDescription();
    Interactive diary("Diary","Emily's Diary");
    addInteractive("diary",diary);
}
void Bedroom::setDescription(){
    this->description = this->room_description;
}
void Bedroom::addInteractive(std::string name, Interactive interactive){
    this->interactives.insert(std::pair<std::string,Interactive>(name,interactive));
}
std::string Bedroom::interacteWith(std::string action,std::string name ,Player& player){
    auto i = this->interactives.begin();
    for(; i != this->interactives.end(); ++i){
        if((*i).first == name){
            break;
        }
    }
    if(i == this->interactives.end()){ return "You can't do anything with that item.";}
    if(action == "check" || action == "read"){
        return checkDiary(player);            
    }
    return "Huh?";
}
void Bedroom::readDescription(){
    this->room_description = Game::readFile("Rooms/" + this->file_path + "/" + this->file_path + "Desc.txt");
}
std::string Bedroom::checkDiary(Player& player){
    player.setJournal("TODO ADD JOURNAL ENTRY FOR READING DIARY");
    return "Emily's Diary Entries:\n" + interactives["diary"].getDescription();
}