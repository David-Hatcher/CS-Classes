#ifndef MODEL_H
#define MODEL_H
#include <fstream>
#include <vector>
#include <string>

class Model{
private:
    std::vector<int> values;
    std::string file_name;
public:
    Model(const std::string &file_name){
        this->file_name = file_name;
    }
    Model(){ }
    std::string getString(){
        return this->file_name;
    }
    void setOnes(){
        for(auto i = values.begin(); i != values.end(); ++i){
            *i = 1;
        }
    }
    void setZeros(){
        for(auto i = values.begin(); i != values.end(); ++i){
            *i = 0;
        }
    }
    void getNumbers(){
        std::ifstream input;
        input.open(this->file_name);
        std::string current_val;
        while(getline(input,current_val,' ')){
            this->values.push_back(stoi(current_val));
        }
        input.close();
    }
    void saveNumbers(){
        std::ofstream output;
        output.open(this->file_name);
        for(auto i = this->values.begin(); i != this->values.end(); ++i){
            output << *i << ' ';
        }
        output.close();
    }

    std::vector<int> Values(){
        return this->values;
    }
};
#endif