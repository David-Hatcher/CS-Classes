#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

const std::string menu_file_name = "menu.txt";


using namespace std;

struct MenuItem{
    string name = "";
    int price = 0;
    string day = "";
};

vector<MenuItem> getMenuItems(const string file_name);
void dispTitle();
void dispCommands();
string getDay();
void printMenuItems(const string day, const vector<MenuItem> items);
bool isDayValid(const string day,const vector<string> days);
void invalidCommand();

int main(){
    vector<MenuItem> items = getMenuItems(menu_file_name);
    vector<string> days = {"sun","mon","tue","wed","thu","fri","sat"};
    dispTitle();
    dispCommands();
    bool run_flag = true;
    do{
        string day = getDay();
        if(day == "exit"){
            run_flag = false;
        }else{
            if(isDayValid(day,days)){
                printMenuItems(day,items);            
            }else{
                invalidCommand();
            }
        }
    }while(run_flag);
    cout << "Bye!";
}

vector<MenuItem> getMenuItems(const string file_name){
    
    vector<MenuItem> items;
    string line;
    ifstream input_file;
    input_file.open(file_name);
    
    while(getline(input_file,line)){
        stringstream ss(line);
        string substr;
        MenuItem item;
        string intHolder;
        getline(ss,item.name,'\t');
        getline(ss,intHolder,'\t');
        ss >> item.day;
        item.price = stoi(intHolder);
        items.push_back(item);
    }
    input_file.close();
    return items;
}

void dispTitle(){
    cout << "Menu of the Day" << endl << endl;
}

void dispCommands(){
    cout << "Specify the day using the three-letter format" << endl
    << "(mon, tue, wed, thu, fri, sat, sun)." << "Or, enter 'exit' to exit." << endl;
}

string getDay(){
    cout << "Day: ";
    string response;
    cin >> response;
    for(unsigned int i = 0; i < response.length(); i++){
        response[i] = tolower(response[i]);
    }
    return response;
}

void printMenuItems(const string day, const vector<MenuItem> items){
    for(MenuItem i: items){
        if(day == i.day){
            cout << setw(20) << left << i.name << setw(8) << right << i.price << endl;
        }
    }
    cout << left << endl;
}

bool isDayValid(const string day,const vector<string> days){
    for(string d : days){
        if(d == day){
            return true;
        }
    }
    return false;
}

void invalidCommand(){
    cout << "Invalid day" << endl << endl;
}
