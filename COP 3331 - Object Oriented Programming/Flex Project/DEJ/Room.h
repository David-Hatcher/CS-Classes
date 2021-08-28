#ifndef ROOM_H
#define ROOM_H
#include <string>
#include <vector>
#include <map>

class Interactive;

#include "Item.h"
#include "Interactive.h"
#include "Player.h"
#include "Helper.h"

class Room{

protected:
    std::string file_path;
    std::map<std::string,Interactive> interactives;
    std::vector<Room*> exits;
    std::string description;
    std::string name;
    std::vector<Item> items;

public:
    Room();
    Room(std::string);
    std::vector<Room*> getExits() const;
    std::string getName() const;
    void setName(std::string);
    virtual void setDescription(Player&);
    std::string getDescription() const;
    void addInteractives(std:: string,Interactive);
    std::map<std::string,Interactive> getInteractives() const;
    void addExit(Room*);
    virtual std::string interactWith(std::string, std::string, Player&) = 0;
};
#endif