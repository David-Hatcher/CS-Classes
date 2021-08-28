#ifndef ROOM_H
#define ROOM_H
#include <string>
#include <vector>
#include <map>
#include <fstream>


#include "Item.h"
#include "Interactive.h"

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
    std::string interactWith(std::string, std::string, std::map<std::string,bool>);
    Item buildItem(std::string item_name){
        std::string name = readFile("Items/" + item_name + "/" + item_name + ".txt");
        std::string desc = readFile("Items/" + item_name + "/" + item_name + "desc.txt");
        Item i(item_name,desc);
        return i;
    }
    std::string readFile(std::string file_path){
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
};
#endif