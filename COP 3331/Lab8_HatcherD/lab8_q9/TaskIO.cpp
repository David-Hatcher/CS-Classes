#include "TaskIO.h"
#include <iostream>
/**
 * writeFile writes the current task list to a file
*/
void TaskIO::writeFile(TaskList tasks, std::string fname){
    std::string file_name = fname;
    std::ofstream output_file;
    output_file.open(file_name);
    
    for(int i = 0; i < tasks.getTaskCount(); ++i){
        std::string name = tasks[i].getName();
        std::string comp = (tasks[i].getComplete() ? "1" : "0");            
        output_file << name << '\t';
        output_file << comp << std::endl;;
    }
    output_file.close();
}
/**
 * readFile reads the tasks from the file
*/
TaskList TaskIO::readFile(std::string file_name){
    int i = 0;
    TaskList tasks;
    std::ifstream input_file;
    std::string line;
    input_file.open(file_name);
    while(std::getline(input_file,line)){
        std::stringstream ss(line);
        std::string task_name;
        std::string task_comp;
        getline(ss,task_name,'\t');
        ss >> task_comp;
        bool task_bool = task_comp == "1" ? true : false;
        std::Task current_task(task_name,task_bool);
        tasks += current_task;
    }
    input_file.close();
    return tasks;
}