#include <iostream>
#include <string>
#include "Person.h"
#include "Teacher.h"


using namespace std;

int main(){

    string name,course;
    int age, height;


    cout << "Name: ";
    cin >> name;
    cin.ignore(1000,'\n');
    cout << "Age: ";
    cin >> age;
    cin.ignore(1000,'\n');
    cout << "Height: ";
    cin >> height;
    cin.ignore(1000,'\n');
    cout << "Course: ";
    cin >> course;
    cin.ignore(1000,'\n');

    Teacher t;
    t.setName(name);
    t.setAge(age);
    t.setHeight(height);
    t.setCourse(course);

    cout << "Teacher " << t.getName() << " is " << t.getAge() << ", " 
    << t.getHeight() << " and teaches " << t.getCourse() <<  endl;

    t.printHeight();

    ((Person)t).printHeight();
    // Person p;
    // p = t;
    // p.printHeight();

    return 0;
}