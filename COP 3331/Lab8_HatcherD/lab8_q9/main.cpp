#include "TaskIO.h"
#include "Task.h"
#include "TaskList.h"
#include <iostream>

std::string file_name = "task_list.txt";

using namespace std;

void printCommands();
void runCommand(char a, TaskList& tasks);
void addTask(TaskList& tasks);
void viewPendingTasks(TaskList& tasks);
void completeTask(TaskList& tasks);
void showHistory(TaskList& tasks);
void saveTasks(TaskList& tasks,string fname);
void showTasks(TaskList& tasks, bool complete);

int main(){
    printCommands();
    TaskList tasks = TaskIO::readFile(file_name);
    while(true){
        cout << "Command: ";
        char p;
        cin >> p;
        cin.ignore(1000,'\n');
        runCommand(p,tasks);
        if(p == 'x'){
            break;
        }
    }
    saveTasks(tasks,file_name);
    return 0;
}

/**
 * printCommands prints the commands
*/
void printCommands(){
    cout << "Task List" << endl << endl;
    cout << "COMMANDS" << endl 
    << "\'v\' to view current tasks" << endl 
    << "\'h\' to view completed tasks" << endl 
    << "\'a\' to add a current task" << endl 
    << "\'x\' to quit" << endl;
}

/**
 * runCommand takes a character and a TaskList object and 
 * determines which command to run on it
*/
void runCommand(char a, TaskList& list){
    switch (a)
    {
    case 'a':
        addTask(list);
        break;
    case 'v':
        showTasks(list,false);
        break;
    case 'c':
        completeTask(list);
        break;
    case 'h':
        showTasks(list,true);
        break;    
    case 'x':
        cout << "Bye!";
        break;    
    default:
        cout << "Incorrect input, please try again!" << endl;
        break;
    }
}

/**
 * addTask takes a task list and asks the user a description 
 * for a task then adds it to the list with default of not complete
*/
void addTask(TaskList& tasks){
    string task_name;
    cout << "Description: ";
    getline(cin,task_name,'\n');
    Task current_task(task_name);
    tasks += current_task;
}

/**
 * completeTask ask the user which task to complete
 * then completes that task
*/
void completeTask(TaskList& tasks){
    int num = 0;
    cout << "Number: ";
    cin >> num;
    if(cin.fail()){
        cin.clear();
    }
    if(!tasks.completeTask(num)){
        cout << "Incorrect value" << endl;
    }
    cin.ignore(1000,'\n');
}

/**
 * saveTasks takes a TaskList object and a string fname
 * and saves the TaskList to that file
*/
void saveTasks(TaskList& tasks,string fname){
    TaskIO::writeFile(tasks,fname);
}

/**
 * showTasks takes a TaskList object and a boolean
 * and shows the tasks with that boolean as their
 * complete value.
*/
void showTasks(TaskList& tasks, bool complete){
    tasks.printTasks(complete);
}