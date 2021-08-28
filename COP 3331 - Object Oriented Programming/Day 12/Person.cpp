#include <string>
#include <iostream>
#include "Person.h"

//getters
int Person::getAge() const{
    return this->age;
}
int Person::getHeight() const{
    return this->height;
}
std::string Person::getName() const{
    return this->name;
}

//setters
void Person::setAge(int age){
    this->age = age;
}

void Person::setHeight(int height){
    this->height = height;
}

void Person::setName(std::string name){
    this->name = name;
}

void Person::printHeight(){
    std::cout << "Person Height = " << this->height  << " inches. "  << std::endl;
}