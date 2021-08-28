#ifndef ENTRANCE_H
#define ENTRANCE_H
#include "Room.h"

class Entrance : public Room{

private:
    std::string no_beast_description;
    std::string beast_description;
    void readDescription();
    std::string openDoor(Player&);
    std::string checkDrawer(Player&);
    void updateDescription(Player&);

public:
    Entrance();
    Entrance(std::string,Player&);
    void setDescription(Player&);
    std::string interactWith(std::string,std::string,Player&);

};

#endif