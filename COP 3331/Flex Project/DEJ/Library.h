#ifndef LIBRARY_H
#define LIBRARY_H
#include "Room.h"

class Library : public Room{

private:

    std::string door_closed_desc;
    std::string door_open_desc;
    void readDescriptions();
    std::string checkBookshelf(Player&);
    void updateDescription(Player&);

public:
    Library();
    Library(std::string file_path,Player& player);
    void setDescription(Player&);
    
    std::string interactWith(std::string,std::string,Player&);

};

#endif