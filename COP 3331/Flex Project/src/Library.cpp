#include "Library.h"

Library::Library(std::string file_path,Player& player) : Room(file_path){
    readDescriptions();
    Interactive bookshelf("Bookshelf","Bookshelf");
    addInteractive("bookshelf",bookshelf);
}
void Library::setDescription(Player& player){
    updateDescription(player);
}
void Library::addInteractive(std::string name,Interactive interactive){
    this->interactives.insert(std::pair<std::string,Interactive>(name,interactive));
}
std::string Library::interactWith(std::string action,std::string name,Player& player){
        auto i = this->interactives.begin();
        for(; i != this->interactives.end(); ++i){
            if((*i).first == name){
                break;
            }
        }
        if(i == this->interactives.end()){ return "You can't do anything with that item.";}
        if(action == "check" || action == "open"){
            return checkBookshelf(player);            
        }
        return "Huh?";
}
void Library::readDescriptions(){
    this->door_closed_desc = Game::readFile("Rooms/" + file_path + "/" + file_path + "doorcloseddesc.txt");
    this->door_open_desc = Game::readFile("Rooms/" + file_path + "/" + file_path + "dooropendesc.txt");
}
std::string Library::checkBookshelf(Player& player){
    player.setFlag("Has_opened_basement", true);
    return "While inspecting the bookshelf you pull one of the books and hear a click. Suddenly the bookshelf swings open revealing another stairs descending to a dark basement";
}
void Library::updateDescription(Player& player){
    this->description = player.checkFlags("Has_opened_basement") ? door_open_desc : door_closed_desc;
}