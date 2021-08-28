#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
#include "Person.h"


class Employee : public Person{

private:
    std::string employee_ssn;
public:

    //getters
    std::string getEmployeeSSN() const;

    //setters
    void setEmployeeSSN(std::string);

};

#endif