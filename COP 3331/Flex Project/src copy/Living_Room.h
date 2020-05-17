#ifndef LIVINGROOM_H
#define LIVINGROOM_H
#include "Room.h"

class Living_Room : public Room{

private:
    std::string room_description;
    void readDescription();
    std::string getHammer(Player&);

public:
    Living_Room(std::string,Player&);
    void setDescription(Player&);
    void addInteractive(std::string,Interactive);
    std::string interactWith(std::string,std::string,Player&);

};

#endif

