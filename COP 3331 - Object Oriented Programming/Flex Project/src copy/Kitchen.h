#ifndef KITCHEN_H
#define KITCHEN_H
#include "Room.h"

class Kitchen : public Room{

private:
    std::string room_description;
    void readDescription();
    std::string getFlashLight(Player&);
public:
    Kitchen(std::string,Player&);
    void setDescription(Player&);
    void addInteractive(std::string,Interactive);
    std::string interactWith(std::string,std::string,Player&);

};


#endif