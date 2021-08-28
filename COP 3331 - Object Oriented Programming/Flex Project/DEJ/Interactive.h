#ifndef INTERACTIVE_H
#define INTERACTIVE_H
#include <string>
#include "Helper.h"

class Interactive{

private:
    std::string name;
    std::string description;
    void setName(std::string);
    void setDescription(std::string);
public:
    Interactive();
    Interactive(std::string, std::string);
    std::string getName() const;
    std::string getDescription() const;


};

#endif