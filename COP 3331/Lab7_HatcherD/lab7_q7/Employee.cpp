#include <string>
#include "Employee.h"


//getters
std::string Employee::getEmployeeSSN() const{
    return this->employee_ssn;
}

//setters
void Employee::setEmployeeSSN(std::string employee_ssn){
    this->employee_ssn = employee_ssn;
}