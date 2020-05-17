#ifndef PET_H
#define PET_H
#include <string>

class Pet{

private:

    std::string name;
    std::string species;

public:
    //default constructor
    Pet(){
        setName("");
        setSpecies("");
    }
    //constructor
    Pet(std::string name,std::string species){
        setName(name);
        setSpecies(species);
    }
    //copy constructor
    Pet(const Pet& tocopy){
        this->setName(tocopy.getName());
        this->setSpecies(tocopy.getSpecies());
    }

    //getters
    std::string getName() const{
        return this->name;
    }
    std::string getSpecies() const{
        return this->species;
    }

    //setters
    void setName(std::string name){
        this->name = name;
    }
    void setSpecies(std::string species){
        this->species = species;
    }
    //copy assignment operator
    Pet& operator=(const Pet& tocopy){
        this->name = tocopy.getName();
        this->species = tocopy.getSpecies();
        return *this;
    }
};

#endif