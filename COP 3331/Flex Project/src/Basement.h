#ifndef BASEMENT_H
#define BASEMENT_H
#include "Room.h"
#include "Game.h"
class Basement : public Room{

private:
    std::string lit_description;
    std::string dark_description;
    void readDescriptions();
    std::string openLockBox(Player&);
    void updateDescription(Player&);
public:
    Basement(std::string,Player&);
    void setDescription(Player&);
    void addInteractive(std::string,Interactive);
    std::string interactWith(std::string,std::string,Player&);

};


#endif