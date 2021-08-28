#include "Item.h"
//constructor
Item::Item(std::string name, std::string description){
    setName(name);
    setDescription(description);
}
//setters
void Item::setDescription(std::string description){
    this->description = description;
}

void Item::setName(std::string name){
    this->name = name;
}
//getters
std::string Item::getDescription(){
    return this->description;
}

std::string Item::getName(){
    return this->name;
}
//check if items are the same
bool operator==(Item& a, Item& b){
    return ((a.getDescription() == b.getDescription()) && a.getName() == b.getName());
}