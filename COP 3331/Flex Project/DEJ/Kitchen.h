#ifndef KITCHEN_H
#define KITCHEN_H
#include "Room.h"

class Kitchen : public Room{

private:
    std::string room_description;
    void readDescription();
    std::string getFlashLight(Player&);
public:
    Kitchen();
    Kitchen(std::string,Player&);
    void setDescription(Player&);
    std::string interactWith(std::string,std::string,Player&);

};


#endif