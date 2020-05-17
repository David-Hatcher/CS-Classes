#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include "Person.h"


class Customer : public Person{

private:
    std::string customer_number;

public:
    //getters
    std::string getCustomerNumber() const;

    //setters
    void setCustomerNumber(std::string);

};

#endif