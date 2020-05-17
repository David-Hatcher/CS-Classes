#include <string>
#include "Employee.h"


//Getters
std::string Employee::getEmployeeSSN() const{
    return this->employee_ssn;
}
//END Getters

//Setters
void Employee::setEmployeeSSN(std::string employee_ssn){
    this->employee_ssn = employee_ssn;
}
//END Setters