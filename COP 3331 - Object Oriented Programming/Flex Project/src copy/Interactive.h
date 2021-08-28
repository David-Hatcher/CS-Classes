#ifndef INTERACTIVE_H
#define INTERACTIVE_H
#include <string>


class Interactive{

private:
    std::string name;
    std::string description;
    void setName(std::string);
    void setDescription(std::string);
public:
    Interactive();
    Interactive(std::string, std::string);
    std::string getName() const;
    std::string getDescription() const;
    std::string readFile(std::string file_path){
        std::ifstream file;
        file.open(file_path);
        std::string file_text = "";
        std::string line;
        while(getline(file,line)){
            file_text += line;
        }
        file.close();
        return file_text;
    }

};

#endif