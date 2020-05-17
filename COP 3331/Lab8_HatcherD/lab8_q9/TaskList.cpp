#include "TaskList.h"
#include <string>
#include <iostream>

    /**
     * overload the += operator;
    */
    TaskList TaskList::operator+=(std::Task task){
        this->tasks.push_back(task);
        return *this;
    }
    /**
     * overloaded subscript operator
    */
    std::Task& TaskList::operator[](int i){
        if(i < tasks.size()){
            return tasks.at(i);
        }else{
            return this->nulltask;
        }
    }
    /**
     * print task prints the tasks to the console
    */
    void TaskList::printTasks(bool complete) const{
        std::string endAdd = complete ? " (DONE!)\n" : "\n";
        std::string taskListString = "";
        int counter = 1;
        for(int i = 0; i < tasks.size(); ++i){
            if(tasks[i].getComplete() == complete){
                std::cout << std::to_string(counter++) << ". " << tasks.at(i) << endAdd;
                // taskListString += std::to_string(counter++) + ". " + tasks[i].getName() + endAdd;
            }
        }
    }
    /**
     * completeTask changes a pending task to a complete task
    */
    bool TaskList::completeTask(int t){
        int count = 0;
        if(t <= getTaskCount(false) && t >= 1){
            for(int i = 0; i < getTaskCount(); ++i){
                if(tasks[i].getComplete() == false){
                    ++count;
                    if(count == t){
                        tasks[i].setComplete(true);
                        return true;
                    }
                }
            }
        }
        return false;
    }
    /**
     * getTaskCount returns the number of tasks
    */
    int TaskList::getTaskCount() const{
        return this->tasks.size();
    }
    int TaskList::getTaskCount(bool complete) const{
        int count = 0;
        for(int i = 0; i < getTaskCount();++i){
            if(tasks[i].getComplete() == complete){
                count++;
            }
        }
        return count;
    }
