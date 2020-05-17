#include <string>
#include "Customer.h"

//Getters
std::string Customer::getCustomerNumber() const{
    return this->customer_number;
}
//END Getters

//Setters
void Customer::setCustomerNumber(std::string customer_number){
    this->customer_number = customer_number;
}
//END Setters