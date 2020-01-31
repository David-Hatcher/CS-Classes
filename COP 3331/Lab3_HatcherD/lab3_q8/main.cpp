#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>

struct itemGen{
    string item;
    string response;
}

using namespace std;

void showCommands();//disp commands
void titleScreen();//title screen disp
string getCommand();//asks user for command
void walk();//function for processing walk command
string walkDescGenerator(int num);//selects walking response
void drop(vector<string> &inventory);//function for processing drop command
void show(vector<string> inventory);//function for processing show command
void exit();//function for processing exit command
vector<string> readFile(string file_name);//reads file contents, each line in vector element.
void pickUpItem(vector<string>& inventory, string item);
vector<itemGen> generatorItem(string file_name));//reads file and generates loot



int main(){
    srand(time(nullptr));
    string possible_loot_file = "wizard_all_items.txt";
    string inventory_loot_file = "wizard_inventory.txt";
    titleScreen();
    vector<string> possible_loot = readFile(possible_loot_file);
    vector<string> inventory_loot = readFile(inventory_loot_file);


    show(inventory_loot);

    return 0;
}

void titleScreen(){
    cout << "Wizard Inventory" << endl << endl;
}

void walk(){
    int desc_num = rand() % 4;
}

string walkDescGenerator(int num){
    string response = "ERROR NUMBER OUT OF RANGE";
    switch (num)
    {
    case 0:
        response = "While strolling down the forest path, you notice ";
        break;
    case 1:
        response = "As you stumble down the cobble stone road, you glimpse ";
        break;
    case 2:
        response = "As you explore the eerie passageway, you spot ";
        break;
    case 3:
        response = "While walking down a path, you see ";
        break;    
    default:
        break;
    }
}

string getCommand(){
    cout << "Command: ";
    string cmnd;
    cin >> cmnd;
    for(unsigned int i =0; i < cmnd.length();i++){
        cmnd[i] = tolower(cmnd[i]);
    }
    return cmnd;
}

void showCommands(){
    cout << "COMMAND MENU" << endl;
    cout << "walk - Walk down the path" << endl;
    cout << "show - Show all items" << endl;
    cout << "drop - Drop an item" << endl;
    cout << "exit - Exit Program" << endl;
}

vector<string> readFile(string file_name){
    vector<string> items;

    ifstream input_file;
    string input_buffer;

    input_file.open(file_name);
    while(getline(input_file,input_buffer)){
        items.push_back(input_buffer);
    }
    input_file.close();

    return items;
}

void show(vector<string> inventory){
    for(unsigned int i = 0; i < inventory.size(); i++){
        cout << (i+1) << ". " << inventory.at(i) << endl;
    }
}

void pickUpItem(vector<string> &inventory, string item){
    if(inventory.size() < 4){
        inventory.push_back(item);
    }else{
        cout << "You can’t carry any more items. Drop something first.";
    }
}

vector<itemGen> generatorItem(string file_name){
    vector<string> possible_loot = readFile(file_name);
    int rand_item = rand() %
}
