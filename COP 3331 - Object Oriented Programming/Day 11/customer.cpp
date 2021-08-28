#include "customer.h"
#include <string>

    std::string Customer::getFullAddress() const{
        std::string full_address = this->first_name + ' ' + this->last_name + '\n' + this->company + '\n' 
                                   + this->address + '\n' + this->city + ", " + this->state + ' ' +
                                   this->postal_code;

        return full_address;
    }


    std::string Customer::getId() const{
        return this->id;
    }

    std::string Customer::getFirstName() const{
        return this->first_name;
    }

    std::string Customer::getLastName() const{
        return this->last_name;
    }
    std::string Customer::getCompany() const{
        return this->company;
    }
    std::string Customer::getAddress() const{
        return this->address;
    }
    std::string Customer::getCity() const{
        return this->city;
    }
    std::string Customer::getState() const{
        return this->state;
    }
    std::string Customer::getPostalCode() const{
        return this->postal_code;
    }

    //setters
    void Customer::setId(std::string id){
        this->id = id;
    }
    void Customer::setFirstName(std::string first_name){
        this->first_name = first_name;
    }
    void Customer::setLastName(std::string last_name){
        this->last_name = last_name;
    }
    void Customer::setCompany(std::string company){
        this->company = company;
    }
    void Customer::setAddress(std::string address){
        this->address = address;
    }
    void Customer::setCity(std::string city){
        this->city = city;
    }
    void Customer::setState(std::string state){
        this->state = state;
    }
    void Customer::setPostalCode(std::string postal_code){
        this->postal_code = postal_code;
    }