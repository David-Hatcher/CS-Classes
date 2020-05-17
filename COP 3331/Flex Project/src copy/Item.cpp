#include "Item.h"

Item::Item(std::string name, std::string description){
    setName(name);
    setDescription(description);
}

void Item::setDescription(std::string description){
    this->description = description;
}

void Item::setName(std::string name){
    this->name = name;
}

std::string Item::getDescription(){
    return this->description;
}

std::string Item::getName(){
    return this->name;
}

bool operator==(Item& a, Item& b){
    return ((a.getDescription() == b.getDescription()) && a.getName() == b.getName());
}