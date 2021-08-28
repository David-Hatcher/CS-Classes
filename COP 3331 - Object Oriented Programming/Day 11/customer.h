#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer{

private:
    std::string id;
    std::string first_name;
    std::string last_name;
    std::string company;
    std::string address;
    std::string city;
    std::string state;
    std::string postal_code;

public:

    //getters
    std::string getId() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getCompany() const;
    std::string getAddress() const;
    std::string getCity() const;
    std::string getState() const;
    std::string getPostalCode() const;
    std::string getFullAddress() const;

    //setters
    void setId(std::string);
    void setFirstName(std::string);
    void setLastName(std::string);
    void setCompany(std::string);
    void setAddress(std::string);
    void setCity(std::string);
    void setState(std::string);
    void setPostalCode(std::string);

};

#endif