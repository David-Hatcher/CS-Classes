#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Model.h"
#include "View.h"

class Controller{
private:
    Model *model;
    View *view;

public:
    Controller( Model &model, View &view){
        this->model = &model;
        this->view = &view;
    }

    void onLoad(){
        (*this->view).PrintValues();
    }

    void getInput(){
        char input;
        std::cin >> input;
        if(input == '1'){
            (*model).setOnes();
        }else if(input == '0'){
            (*model).setZeros();
        }
    }


};
#endif