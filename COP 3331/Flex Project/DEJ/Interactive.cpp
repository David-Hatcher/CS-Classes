#include "Interactive.h" 
 
 
void Interactive::setName(std::string name){
    this->name = name;
}
void Interactive::setDescription(std::string description){
    this->description = description;
}

Interactive::Interactive(){}

Interactive::Interactive(std::string file_path, std::string file_name){
    setName(Helper::readFile("Interactives/" + file_path + '/' + file_name + ".txt"));
    setDescription(Helper::readFile("Interactives/" + file_path + '/' + file_name + "desc.txt"));
}
std::string Interactive::getName() const{
    return this->name;
}
std::string Interactive::getDescription() const{
    return this->description;
}
