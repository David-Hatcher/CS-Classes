#include <iostream>
#include "Model.h"
#include "View.h"
#include "Controller.h"

using namespace std;

int main(){
    string file = "nums.txt";
    Model model(file);
    View view(model);
    Controller controller(model,view);
    model.getNumbers();
    controller.onLoad();
    view.Print("What would you like to set the numbers to 1 or 0?");
    controller.getInput();
    view.PrintValues();
    model.saveNumbers();
    view.Print("Bye!");
}