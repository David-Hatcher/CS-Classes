#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include "Room.h"
#include "Interactive.h"
#include "Player.h"
#include "Item.h"
#include "Entrance.h"
#include "Living_Room.h"
#include "Bedroom.h"
#include "Kitchen.h"
#include "Office.h"
#include "Library.h"
#include "Basement.h"
class Game{

private:
    std::string name;
    bool gameRunning = true;
    Office office;
    Kitchen kitchen;
    Bedroom bedroom;
    Entrance entrance;
    Living_Room living_room;
    Library library;
    Basement basement;
    // std::vector<std::string> room_names;
    // std::map<std::string,Room*> rooms;
    Room* current_room;
    // std::string save_loc;
    Player* player;
    // void setSaveLoc(std::string);
    void buildRooms();
    Kitchen buildKitchen(std::string);
    Entrance buildEntrance(std::string);
    Living_Room buildLiving_Room(std::string);
    Bedroom buildBedroom(std::string);
    Office buildOffice(std::string);
    Library buildLibrary(std::string);
    Basement buildBasement(std::string);

public:
    Game(std::string,Player&);
    // static std::string read();
    std::string printJournal();
    std::string goToExit(std::string);
    std::string interactWith(std::string,std::string);
    friend bool loadData(std::string,Player&);
    bool load();
    friend bool saveData(std::string,Player&);
    void printRoomDescription();  
    std::string runGame();  
    bool checkGameRunning();

};

#endif