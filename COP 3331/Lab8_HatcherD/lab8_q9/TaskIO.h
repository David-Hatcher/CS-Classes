#ifndef TASKIO_H
#define TASKIO_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "TaskList.h"
#include "Task.h"


class TaskIO{
public:
    static void writeFile(TaskList tasks,std::string fname);
    static TaskList readFile(std::string file_name);
};

#endif 