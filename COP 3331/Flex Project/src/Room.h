#ifndef ROOM_H
#define ROOM_H
#include <string>
#include <vector>
#include <map>

class Interactive;

#include "Game.h"
#include "Item.h"
#include "Interactive.h"
#include "Player.h"

class Room{

protected:
    std::string file_path;
    std::map<std::string,Interactive> interactives;
    std::vector<Room> exits;
    std::string description;
    std::string name;
    std::vector<Item> items;

public:
    Room();
    Room(std::string);
    std::vector<Room> getExits() const;
    std::string getName() const;
    void setName(std::string);
    void setDescription(std::string);
    std::string getDescription() const;
    void addInteractives(std:: string,Interactive);
    std::map<std::string,Interactive> getInteractives() const;
    void setExits();
    void addExit(Room);
    std::string interactWith(std::string, std::string, Player&);
};
#endif