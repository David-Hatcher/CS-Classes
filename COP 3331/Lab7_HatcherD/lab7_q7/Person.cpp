#include <string>
#include "Person.h"

std::string Person::getFirstName() const{
    return first_name;
}

std::string Person::getLastName() const{
    return last_name;
}

std::string Person::getEmailAddress() const{
    return email_address;
}

void Person::setFirstName(std::string first_name){
    this->first_name = first_name;
}

void Person::setLastName(std::string last_name){
    this->last_name = last_name;
}

void Person::setEmailAddres(std::string email_address){
    this->email_address = email_address;
}

std::string Person::getFullName() const{
    return this->getFirstName() + " " + this->getLastName();
}