#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <limits>

using namespace std;

const string possible_loot_file = "wizard_all_items.txt";
const string inventory_loot_file = "wizard_inventory.txt";

void showCommands();//disp commands
void titleScreen();//title screen disp
string getCommand();//asks user for command
string walk();//function for processing walk command
string walkDescGenerator(int num);//selects walking response
void drop(vector<string> &inventory);//function for processing drop command
void show(vector<string> inventory);//function for processing show command
void exit();//function for processing exit command
vector<string> readFile(string file_name);//reads file contents, each line in vector element.
void pickUpItem(vector<string>& inventory, string item);
string generateItem();//reads file and generates loot
void processCommand(string command, vector<string> &inventory);
void writeFile(vector<string> inventory);
unsigned int getNumber();
char getCharacter();



int main(){
    srand(time(nullptr));
    vector<string> inventory = readFile(inventory_loot_file);
    titleScreen();
    showCommands();
    string command;
    do{
        command = getCommand();
        processCommand(command, inventory);        
    }while(command != "exit");

    return 0;
}

void titleScreen(){
    cout << "Wizard Inventory" << endl << endl;
}

string walk(){
    int desc_num = rand() % 4;
    string response = walkDescGenerator(desc_num);
    string loot = generateItem();
    cout << response << loot << '.' << endl;
    return loot;
}

string walkDescGenerator(int num){
    string response = "ERROR NUMBER OUT OF RANGE";
    switch (num)
    {
    case 0:
        response = "While strolling down the forest path, next to a tree, you spot a ";
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
    return response;
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
    if(inventory.size() == 0){
        cout << "Inventory Empty!" << endl;
        return;
    }
    for(unsigned int i = 0; i < inventory.size(); i++){
        cout << (i+1) << ". " << inventory.at(i) << endl;
    }
}

void pickUpItem(vector<string> &inventory, string item){
    if(inventory.size() < 4){
        inventory.push_back(item);
    }else{
        cout << "You can't carry any more items. Drop something first." << endl;
    }
    writeFile(inventory);
}

string generateItem(){
    vector<string> possible_loot = readFile(possible_loot_file);
    int rand_item = rand() % 9;
    string item = possible_loot.at(rand_item);
    return item;
}

void processCommand(string command, vector<string> &inventory){
    if(command == "walk"){
        string item = walk();
        cout << "Do you want to grab it? (y/n): ";
        char ans = getCharacter();
        if(ans == 'y'){
            pickUpItem(inventory,item);
        }
    }else if(command == "show"){
        show(inventory);
    }else if(command == "drop"){
        drop(inventory);
    }else if(command != "exit"){
        cout << "Incorrect command please try again!" << endl;
        showCommands();
    }
    cout << endl;
}

void drop(vector<string> &inventory){
    unsigned int number_to_drop = getNumber();
    if(inventory.size() == 0){
        cout << "Inventory empty, cannot drop anything!" << endl;
        return;
    }else if(number_to_drop > inventory.size() || number_to_drop < 1){
        cout << endl << "Incorrect value, must be between 1 and " << inventory.size() << "." << endl;
        return;
    }
    cout << "You dropped a " << inventory.at(number_to_drop-1) << '.' << endl;
    inventory.erase(inventory.begin() + number_to_drop - 1);
    writeFile(inventory);
}

unsigned int getNumber(){
    cout << "Number: ";
    unsigned int number_to_drop;
    cin >> number_to_drop;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    return number_to_drop;
}

void writeFile(vector<string> inventory){
    ofstream output_file;
    output_file.open(inventory_loot_file);
    if(output_file.is_open()){
        for(string item : inventory){
            output_file << item << endl;
        }
    }else{
        cout << "Error opening file" << endl;
    }
    output_file.close();
}

char getCharacter(){
    char character;
    cin >> character;
    cin.ignore(1000,'\n');
    return character;
}