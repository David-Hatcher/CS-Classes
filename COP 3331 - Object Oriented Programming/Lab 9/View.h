#ifndef VIEW_H
#define VIEW_H
#include <iostream>
#include <vector>
#include "Model.h"


class View{

private:
    Model *model;
    
public:
    View(Model &model){
        this->model = &model;
    }

    View(){ }

    void PrintValues(){
        std::cout << "Current Data Values: ";
        std::vector<int> values = (*model).Values();
        for(auto i = values.begin(); i != values.end(); ++i){
            std::cout << *i << ' ';
        }
        std::cout << std::endl;
    }
    
    void Print(std::string a){
        std::cout << a << std::endl;
    }

};

#endif