#ifndef HELPER_H
#define HELPER_H
#include "Item.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Helper{

public:

    static vector<string> explode(const string& s, const char& c)
    {
        string buff{""};
        vector<string> v;
        
        for(auto n:s)
        {
            if(n != c) buff+=n; else
            if(n == c && buff != "") { v.push_back(buff); buff = ""; }
        }
        if(buff != "") v.push_back(buff);
        
        return v;
    }
    static string readFile(string file_path){
        std::ifstream file;
        file.open(file_path);
        std::string file_text = "";
        std::string line;
        int lineCount = 0;
        while(getline(file,line)){
            if(lineCount++ == 0){
                file_text += line;
            }else{
                file_text += '\n' + line;
            }
        }
        file.close();
        return file_text;
    }
    static bool writeFile(string file_path, string to_write){
        bool saved_flag = true;
        ofstream output;
        output.open(file_path + ".txt");
        output << to_write;
        if(output.bad()){
            saved_flag = false;
        }
        output.close();
        return saved_flag;
    }
    static string readConsole(){
        string input;
        getline(cin,input);        
        return strtolower(input);
    }
    static void writeConsole(string output){
        cout << output;
    }
    static Item buildItem(std::string item_name){
        std::string name = readFile("Items/" + item_name + "/" + item_name + ".txt");
        std::string desc = readFile("Items/" + item_name + "/" + item_name + "desc.txt");
        Item i(item_name,desc);
        return i;
    }
    static string strtolower(string input){
        for(int i = 0; i < input.size(); ++i){
            input[i] = tolower(input[i]);
        }
        return input;
    }
    static string readConsoleNoSani(){
        string input;
        getline(cin,input);        
        return input;
    }
};

#endif