#ifndef PERSON_H
#define PERSON_H
#include <string>

class Person{
private:
    std::string first_name;
    std::string last_name;
    std::string email_address;
public:
    //getters
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getEmailAddress() const;

    //setters
    void setFirstName(std::string);
    void setLastName(std::string);
    void setEmailAddres(std::string);

    //member functions
    std::string getFullName() const;
};

#endif