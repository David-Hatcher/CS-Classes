#ifndef OFFICE_H
#define OFFICE_H
#include "Room.h"


class Office : public Room{

private:
    std::string mirror_broken_desc;
    std::string mirror_not_broken_desc;
    void readDescriptions();
    std::string breakMirror(Player&);
    std::string touchMirror(Player&);
    std::string lookMirror(Player&);
    void updateDescription(Player&);

public:
    Office(std::string, Player&);
    void setDescription(Player&);
    void addInteractive(std::string,Interactive);
    std::string interactWith(std::string,std::string,Player&);

};


#endif