#ifndef BEDROOM_H
#define BEDROOM_H
#include "Room.h"



class Bedroom : public Room{

private:
    std::string room_description;
    void readDescription();
    std::string checkDiary(Player&);

public:
    Bedroom(std::string, Player&);
    void setDescription();
    void addInteractive(std::string, Interactive);
    std::string interacteWith(std::string,std::string,Player&);

};

#endif