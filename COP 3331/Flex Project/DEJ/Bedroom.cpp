#include <string>
#include "Bedroom.h"

//constructor
Bedroom::Bedroom(){}
Bedroom::Bedroom(std::string file_path, Player& player) : Room(file_path){
    readDescription();
    setDescription();
    Interactive diary("Diary","Emily's Diary");
    addInteractives("diary",diary);
}
//sets description
void Bedroom::setDescription(){
    this->description = this->room_description;
}
//allows for interaction with interactive objects
std::string Bedroom::interactWith(std::string action,std::string name ,Player& player){
    auto i = this->interactives.begin();
    for(; i != this->interactives.end(); ++i){
        if((*i).first == name){
            break;
        }
    }
    if(i == this->interactives.end()){ return "You can't do anything with that item.\n";}
    if(action == "check" || action == "read" || action == "look"){
        return checkDiary(player);            
    }
    return "Huh?\n";
}
//sets the local room description
void Bedroom::readDescription(){
    this->room_description = Helper::readFile("Rooms/" + this->file_path + "/" + this->file_path + "Desc.txt");
}
//allows for interaction with the diary interactive
std::string Bedroom::checkDiary(Player& player){
    std::string entries = this->interactives["diary"].getDescription();
    std::string journal = "Emily mentioned something about a mirror in her office and a key? Maybe that has something to do with where she went.";
    if(!player.checkFlags("Read_diary")){
        player.setFlag("Read_diary",true);
        player.addJournal(journal);
    }
    return "\nEmily's Diary Entries:\n" + entries + '\n';
}