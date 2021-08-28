#include "Task.h"
#include <string>

    //constructor - default name "", default complete false
    std::Task::Task(std::string name,bool complete){
        this->name = name;
        this->complete = complete;
    }
    //getters
    std::string std::Task::getName() const{
        return this->name;
    }
    bool std::Task::getComplete() const{
        return this->complete;
    }
    //setters
    void std::Task::setName(std::string name){
        this->name = name;
    }
    void std::Task::setComplete(bool complete){
        this->complete = complete;
    }


