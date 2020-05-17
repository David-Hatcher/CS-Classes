#include "Game.h"
#include <string>


Game::Game(std::string name,Player& player){
    this->player = &player;
    buildRoom("Entrance");
}
std::string Game::read(){
    std::string input;
    std::getline(std::cin,input);
    return input;
}
void Game::print(std::string output){
    std::cout << output;
}

Item Game::buildItem(std::string item_name){
    std::string name = readFile("Items/" + item_name + "/" + item_name + ".txt");
    std::string desc = readFile("Items/" + item_name + "/" + item_name + "desc.txt");
    Item i(item_name,desc);
    return i;
}

void Game::buildRooms(){
    this->entrance = new Entrance("Entrance",(*player));
    this->rooms.insert(std::pair<std::string, Room*>("Entrance",entrance));
}

Room Game::buildRoom(std::string file_path){
    Entrance entrance(file_path,*(this->player));
    return entrance;
}

std::string Game::readFile(std::string file_path){
    std::ifstream file;
    file.open(file_path);
    std::string file_text = "";
    std::string line;
    while(getline(file,line)){
        file_text += line;
    }
    file.close();
    return file_text;
}

std::string Game::printJournal(){
    return (*(this->player)).getJournal();
}

void Game::goToExit(std::string exit){
    auto i = this->rooms.begin();
    for(;i != this->rooms.end();++i){
        if((*i).first == exit){
            break;
        }
    }
    if(i == this->rooms.end()){
        print("This is not an exit.\n");
    }
}
