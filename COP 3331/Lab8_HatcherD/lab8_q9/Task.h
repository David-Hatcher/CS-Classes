#ifndef TASK_H
#define TASK_H
#include <string>

namespace std{
    class Task{
    private:
        std::string name;
        bool complete;
    public:
        //constructor
        Task(std::string name = "",bool complete = false);
        //getters
        std::string getName() const;
        bool getComplete() const;
        //setters
        void setName(std::string);
        void setComplete(bool);
        friend std::ostream& operator<<(std::ostream& out, const std::Task& t){
            out << t.getName();
            return out;
        };
    };    
}





#endif