#ifndef ITEM_H
#define ITEM_H
#include <string>

class Item{

private:
    std::string name;
    std::string description;

public:
    Item(std::string name,std::string description);

    void setDescription(std::string);
    void setName(std::string);

    std::string getName();
    std::string getDescription();

    friend bool operator==(Item& a,Item& b);
};

#endif