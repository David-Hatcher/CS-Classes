#include "Game.h"
#include <string>
#include <sstream>

//constructor
Game::Game(std::string name,Player& player){
    this->name = name;
    this->player = &player;
    buildRooms();

}
//builds out all of the rooms
void Game::buildRooms(){
    //build rooms
    this->entrance = buildEntrance("Entrance");
    this->living_room = buildLiving_Room("LivingRoom");
    this->bedroom = buildBedroom("Bedroom");
    this->kitchen = buildKitchen("Kitchen");
    this->office = buildOffice("Office");
    this->library = buildLibrary("Library");
    this->basement = buildBasement("Basement");

    //assign exits
    this->entrance.addExit(&this->living_room);
    this->living_room.addExit(&this->entrance);
    this->living_room.addExit(&this->bedroom);
    this->living_room.addExit(&this->kitchen);
    this->living_room.addExit(&this->office);
    this->bedroom.addExit(&this->living_room);
    this->kitchen.addExit(&this->living_room);
    this->office.addExit(&this->library);
    this->office.addExit(&this->living_room);
    this->library.addExit(&this->office);
    this->basement.addExit(&this->library);

    this->current_room = &(this->entrance);
}
//interact with something in a room
std::string Game::interactWith(std::string command_1,std::string command_2){
    return (*this->current_room).interactWith(command_1,command_2,*player);
}

//room building functions
Living_Room Game::buildLiving_Room(std::string file_path){
    Living_Room living_Room(file_path,*(this->player));
    return living_Room;
}

Entrance Game::buildEntrance(std::string file_path){
    Entrance entrance(file_path,*(this->player));
    return entrance;
}

Bedroom Game::buildBedroom(std::string file_path){
    Bedroom bedroom(file_path,*(this->player));
    return bedroom;
}

Kitchen Game::buildKitchen(std::string file_path){
    Kitchen kitchen(file_path,*(this->player));
    return kitchen;
}

Office Game::buildOffice(std::string file_path){
    Office office(file_path,*(this->player));
    return office;
}

Library Game::buildLibrary(std::string file_path){
    Library library(file_path,*(this->player));
    return library;
}

Basement Game::buildBasement(std::string file_path){
    Basement basement(file_path, *(this->player));
    return basement;
}
//end room building functions

//returns the players journal
std::string Game::printJournal(){
    return (*(this->player)).getJournalDefault() + (*(this->player)).getJournal() + "\n\n";
}

//moves to a different room
std::string Game::goToExit(std::string exit){
    vector<Room*> exits = (*this->current_room).getExits();
    
    for(Room* r : exits){
        string r_name = Helper::strtolower((*r).getName());
        if(r_name == exit){
            this->current_room = r;
            return "You enter " + (*r).getName() + '\n';
        }
    }
    return "This is not an exit.\n";
}

//prints the room description
void Game::printRoomDescription(){
    Helper::writeConsole("\n\n" + (*this->current_room).getName() + '\n' + (*this->current_room).getDescription() + '\n');
}

std::string Game::runGame(){
    if((*this->player).checkFlags("Has_opened_basement")){
        (this->library).addExit(&(this->basement));
    }
    if((*this->player).checkFlags("Beaten_game")){
        this->gameRunning = false;
        return "Congratulations on completing the Disappearance of Emily Jane!\n";
    }
    (*this->current_room).setDescription(*this->player);
    printRoomDescription();
    Helper::writeConsole("EXITS: [ ");
    vector<Room*> current_exits = (*this->current_room).getExits();
    int counter = 0;
    for(Room* c_exit: current_exits){
        if(counter != current_exits.size() - 1){
            Helper::writeConsole((*c_exit).getName() + " | ");
            counter++;
        }else{
            Helper::writeConsole((*c_exit).getName() +" ]");
        }
    }
    Helper::writeConsole("\nType commands to view commands.");
    Helper::writeConsole("\n\n");
    Helper::writeConsole("\nWhat would you like to do? ");
    std::string input = Helper::readConsole();
    Helper::writeConsole("\n\n");
    vector<string> command = Helper::explode(input,' ');
    saveData((*this->player).getName(),*(this->player));
    try
    {                
        if(input == "commands"){
            return "Commands:\njournal - opens your journal to give you an idea of what to do next.\ntouch, look, check, open, break, read - allows you to interactive with different objects in the room, some verbs only with with certain objects and some objects work with multiple verbs differently. Objects in brackets can be interacted with.\ngo room_name - moves to into a different room from the list of exits\ninventory - shows your inventory\nquit - exits game and saves data";
        }else if(input == "up up down down left right left right b a"){
            return "Cheat codes unlocked.\n\n";
        }
        else if(command.at(0) == "go"){
            string exit_loc = command.at(1);
            for(int i = 2; i < command.size(); ++i){
                exit_loc += ' ' + command.at(i);
            }
            return goToExit(exit_loc);        
        }else if(command.at(0) == "inventory" || command.at(0) == "pockets" || command.at(0) == "inv"){
            return (*this->player).showInventory();
        }else if(command.at(0) == "quit"){
            this->gameRunning = false;
            if(saveData((*this->player).getName(),*(this->player))){
                return "Data Saved, Goodbye";
            }
            return "Data Not Saved, Goodbye";
        }else if(command.at(0) == "journal"){
            return printJournal();
        }
        else{
            try{return interactWith(command.at(0),command.at(1));}
            catch(const std::exception& e){return "Sorry I don't understand.\n";}
        }
    }
    catch(const std::exception& e)
    {
        return "Huh?";
    }

}

bool Game::checkGameRunning(){
    return this->gameRunning;
}


bool saveData(std::string player_name,Player& player){
    std::string inv_save_string = "";
    for(auto i = player.inventory.begin(); i != player.inventory.end(); ++i){
        if(i == player.inventory.end() - 1){
            inv_save_string += (*i).getName();
        }else{
            inv_save_string += (*i).getName() + '|';
        }
    }    
    bool inv_save = Helper::writeFile("Players/" + player_name + "inv",inv_save_string);
    std::string flags_save_string = "";
    for(auto i = player.flags.begin(); i != player.flags.end(); ++i){
        if(i == --player.flags.end()){
            flags_save_string += (*i).first + '|' + ((*i).second ? '1' : '0');
        }else{
            flags_save_string += (*i).first + '|' + ((*i).second ? '1' : '0') + '|';
        }
    }
    bool journal_save = Helper::writeFile("Players/" + player_name + "journal", player.getJournal());
    bool flag_save = Helper::writeFile("Players/" + player_name + "flags", flags_save_string);
    return (inv_save && flag_save);
}
bool loadData(std::string player_name,Player* player){
    std::string inv_load_string = Helper::readFile("Players/" + player_name + "inv.txt");
    std::string flags_load_string = Helper::readFile("Players/" + player_name + "flags.txt");
    std::string journal_load_string = Helper::readFile("Players/" + player_name + "journal.txt");
    (*player).setJournal(journal_load_string);
    vector<string> inv_vec = Helper::explode(inv_load_string, '|');
    vector<string> flags_vec = Helper::explode(flags_load_string,'|');
    for(int i = 0; i != inv_vec.size();++i){
        (*player).addToInventory(Helper::buildItem(inv_vec.at(i)));
    }
    for(int i = 0; i < flags_vec.size()/2; ++i){
        bool flag_val = false;
        if(flags_vec.at(2*i + 1) == "1"){
            flag_val = true;
        }
        (*player).setFlag(flags_vec.at(2*i), flag_val);
    }

    return true;
}
bool Game::load(){
    return loadData(this->name,this->player);
}