#ifndef BEDROOM_H
#define BEDROOM_H
#include "Room.h"

class Bedroom : public Room{

private:
    std::string room_description;
    void readDescription();
    std::string checkDiary(Player&);

public:
    Bedroom();
    Bedroom(std::string, Player&);
    void setDescription();
    std::string interactWith(std::string,std::string,Player&);

};

#endif