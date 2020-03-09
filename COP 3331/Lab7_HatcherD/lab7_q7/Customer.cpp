#include <string>
#include "Customer.h"

std::string Customer::getCustomerNumber() const{
    return this->customer_number;
}

void Customer::setCustomerNumber(std::string customer_number){
    this->customer_number = customer_number;
}