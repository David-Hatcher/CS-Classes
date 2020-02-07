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
void drop(vector<string> &inventory);//function for processing drop command
void show(vector<string> inventory);//function for processing show command
void exit();//function for processing exit command
vector<string> readFile(string file_name);//reads file contents, each line in vector element.
void pickUpItem(vector<string>& inventory, string item);//picks up item and adds it to inventory
string generateItem();//reads file and generates loot
void processCommand(string command, vector<string> &inventory);//main function to run program
void writeFile(vector<string> inventory);//writes to a file
unsigned int getNumber();//asks user for a number
char getCharacter();//asks user for a character
bool isCharYorN(char a);//tests for validity of pick up response


/**
 * Author: David Hatcher
 * Purpose: This program will allow a user to walk around as a wizard
 * and pick up items they find along the way. It reads a list of
 * possible items from a file and saves the wizards inventory into another file
*/
int main(){
    srand(time(nullptr));//set random seed for use in file
    vector<string> inventory = readFile(inventory_loot_file);//build inventory vector
    titleScreen();//display title screen
    showCommands();//show commands
    string command;//declare command variable
    do{
        command = getCommand();//gets a command from the user
        processCommand(command, inventory);//processes that command
    }while(command != "exit");//leaves it command == exit
    return 0;
}
/**
 * titleScreen function simply displays the title
*/
void titleScreen(){
    cout << "Wizard Inventory" << endl << endl;
}
/**
 * walk function handles the walk command.
*/
string walk(){
    string response = "While walking down a path, you see ";
    string loot = generateItem();//generate item to be found
    cout << endl << response << loot << "." << endl;//displays full response include item
    return loot;//returns the item that was found
}
/**
 * getCommand asks for user for their command and handle the stream
 * once the command is recieved it will sanitize it to lower case and
 * return the value
*/
string getCommand(){
    cout << "Command: ";
    string cmnd;
    cin >> cmnd;
    if(cin.fail()){
        cin.clear();
        cout << "Incorrect input please try again. " << endl;
    }
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    for(unsigned int i =0; i < cmnd.length();i++){
        cmnd[i] = tolower(cmnd[i]);
    }
    return cmnd;
}
/**
 * showCommands shows the user the availble commands
*/
void showCommands(){
    cout << "COMMAND MENU" << endl;
    cout << "walk - Walk down the path" << endl;
    cout << "show - Show all items" << endl;
    cout << "drop - Drop an item" << endl;
    cout << "exit - Exit Program" << endl;
}
/**
 * readFile takes a sting and reads that file then returns
 * the content of each line as a value in a vector
 * this is used to build out the possible loot as well as 
 * the current inventory
*/
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
/**
 * show takes a vector<string>, which is the current inventory
 * and displays the values. This function handles the show command
 * in it's entirety
*/
void show(vector<string> inventory){
    if(inventory.size() == 0){
        cout << "Inventory Empty!" << endl;
        return;
    }
    for(unsigned int i = 0; i < inventory.size(); i++){
        cout << (i+1) << ". " << inventory.at(i) << endl;
    }
}
/**
 * pickUpItem takes a vector<string> as a reference and
 * a string, it will then check if the size of the vector
 * if the vector has less than 4 items, it will append it
 * otherwise it will tell the user to drop something first.
 * It has no return as it just updates the inventory file on
 * finish.
*/ 
void pickUpItem(vector<string> &inventory, string item){
    if(inventory.size() < 4){
        inventory.push_back(item);
    }else{
        cout << "You can't carry any more items. Drop something first." << endl;
    }
    writeFile(inventory);//update the inventory file with new values
}
/**
 * generateItem randomly generates an item from the possible inventory
 * list.
*/
string generateItem(){
    vector<string> possible_loot = readFile(possible_loot_file);
    int rand_item = rand() % possible_loot.size();
    string item = possible_loot.at(rand_item);
    return item;
}
/**
 * processCommand takes a string and a vector<string> reference.
 * This function is the main driver of the program. It takes the command
 * and current inventory and then handles the input and runs the required functions.
*/
void processCommand(string command, vector<string> &inventory){
    if(command == "walk"){
        string item = walk();
        char ans = ' ';
        while(!isCharYorN(ans)){//This forces a requirement of y or n from the user
            cout << "Do you want to grab it? (y/n): ";
            ans = getCharacter();
            if(isCharYorN(ans)){//if the input is valid, y or n
                if(ans == 'y'){//if the input is y add the item to inventory
                    pickUpItem(inventory,item);
                }
            }else{//if the input is not valid warn user
                cout << "Invalid input, please type y or n." << endl;
            }       
        }
    }else if(command == "show"){
        show(inventory);
    }else if(command == "drop"){
        drop(inventory);
    }else if(command != "exit"){//if any non acceptable input is given warn using and show commands
        cout << "Incorrect command please try again!" << endl;
        showCommands();
    }
    cout << endl;
}
/**drop takes a vector<string> by reference then grabs a number
 * using the getNumber function then determines what item to drop 
 * based on the users response
*/
void drop(vector<string> &inventory){
    unsigned int number_to_drop = getNumber();//asks user for number
    if(inventory.size() == 0){
        //if the inventory is currently empty display error and cancel drop
        cout << "Inventory empty, cannot drop anything!" << endl;
        return;
    }else if(number_to_drop > inventory.size() || number_to_drop < 1){
        //if the number the user enters it outside of the range for items, show error cancel drop
        cout << endl << "Incorrect input, must be a number between 1 and " << inventory.size() << "." << endl;
        return;
    }
    //item removal can commence
    cout << endl << "You dropped " << inventory.at(number_to_drop-1) << "." << endl;
    inventory.erase(inventory.begin() + number_to_drop - 1);//remove item
    writeFile(inventory);//update inventory file
}
/**
 * getNumber asks the user to input a number
*/
unsigned int getNumber(){
    cout << "Number: ";
    unsigned int number_to_drop;
    cin >> number_to_drop;
    while(cin.fail()){//this handles non numerical inputs
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        return 0;
    }
    cin.ignore(numeric_limits<streamsize>::max(),'\n');//dump buffer in case of multiple inputs
    return number_to_drop;
}
/**
 * writeFile takes a vector<string>, the current inventory,
 * and updates the current inventory file with it's contents
*/
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
/**
 * getCharacter gets a single character from the user
*/
char getCharacter(){
    char character = ' ';
    cin >> character;
    if(cin.fail()){//stream error handling
        cin.clear();
    }
    cin.ignore(numeric_limits<streamsize>::max(),'\n');//dump buffer
    return tolower(character);//sanitize and return input
}
/**
 * isCharYorN takes an input character and returns a
 * boolean value based on if the character is a y or an n
*/
bool isCharYorN(char a){
    if(a == 'y' || a == 'n'){
        return true;
    }
    return false;
}
