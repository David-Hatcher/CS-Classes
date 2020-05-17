#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>


#include "Room.h"
#include "Player.h"
#include "Entrance.h"
class Game{

private:
    Entrance* entrance;
    std::string title;
    std::vector<std::string> room_names;
    std::map<std::string,Room*> rooms;
    Room* current_room;
    std::string save_loc;
    Player* player;
    void setSaveLoc(std::string);
    void buildRooms();
    Room buildRoom(std::string);

public:
    Game(std::string,Player&);
    static std::string read();
    static void print(std::string);
    static Item buildItem(std::string);
    static std::string readFile(std::string file_path);
    std::string printJournal();
    void goToExit(std::string);
    std::string interactWith(std::string);
    bool loadData(std::string);
    bool saveData(std::string);

    

};

#endif