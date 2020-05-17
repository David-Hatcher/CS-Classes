#ifndef TASKLIST_H
#define TASKLIST_H
#include <vector>
#include "Task.h"

class TaskList{
private:
    std::Task nulltask;
    std::vector<std::Task> tasks;
public:
    //member functions
    TaskList operator+=(std::Task);
    std::Task& operator[](int);
    void printTasks(bool) const;
    bool completeTask(int);
    int getTaskCount() const;
    int getTaskCount(bool) const;

};



#endif