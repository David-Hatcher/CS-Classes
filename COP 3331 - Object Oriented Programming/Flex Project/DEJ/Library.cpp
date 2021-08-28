#include "Library.h"

Library::Library(){}
Library::Library(std::string file_path,Player& player) : Room(file_path){
    readDescriptions();
    Interactive bookshelf("Bookshelf","Bookshelf");
    addInteractives("bookshelf",bookshelf);
}
void Library::setDescription(Player& player){
    updateDescription(player);
}
std::string Library::interactWith(std::string action,std::string name,Player& player){
        auto i = this->interactives.begin();
        for(; i != this->interactives.end(); ++i){
            if((*i).first == name){
                break;
            }
        }
        if(i == this->interactives.end()){ return "You can't do anything with that item.\n\n";}
        if(action == "check" || action == "open" || action == "touch"){
            return checkBookshelf(player);            
        }
        return "Huh?\n\n";
}
void Library::readDescriptions(){
    this->door_closed_desc = Helper::readFile("Rooms/" + file_path + "/" + file_path + "doorcloseddesc.txt");
    this->door_open_desc = Helper::readFile("Rooms/" + file_path + "/" + file_path + "dooropendesc.txt");
}
std::string Library::checkBookshelf(Player& player){
    player.addJournal("Apparently this house has a hidden basement.");
    player.setFlag("Has_opened_basement", true);
    return "While inspecting the bookshelf you pull one of the books and hear a click. Suddenly the bookshelf swings open revealing another stairs descending to a dark basement.\n\n";
}
void Library::updateDescription(Player& player){
    this->description = player.checkFlags("Has_opened_basement") ? door_open_desc : door_closed_desc;
}