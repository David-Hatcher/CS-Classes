#include <string>
#include <iostream>
#include "Teacher.h"


    //setters
    void Teacher::setCourse(std::string course){
        this->course = course;
    }

    //getters
    std::string Teacher::getCourse() const{
        return this->course;
    }

    void Teacher::printHeight(){
        std::cout << "Teacher Height = " << this->height << " inches. " << std::endl;
    }