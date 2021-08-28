#ifndef TEACHER_H
#define TEACHER_H

#include <string>
#include "Person.h"

class Teacher : public Person{

private:

    std::string course;

public:
    //setters
    void setCourse(std::string);

    //getters
    std::string getCourse() const;
    
    void printHeight();

};

#endif