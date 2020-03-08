#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person{

protected:
    int height;


private:
    std::string name;
    int age;

public:

//getters
    int getAge() const;
    int getHeight() const;
    std::string getName() const;

//setters
    void setAge(int);
    void setHeight(int);
    void setName(std::string);

    //virtual void printHeight() = 0;//this creates the abstract class
    virtual void printHeight();

};


#endif