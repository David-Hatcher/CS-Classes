#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <string>


class Rectangle{

private:
int height;
int width;

//private member functions

std::string getHorizontals()  const;
std::string getVerticals() const;

public:

//setters

void setHeight(int);
void setWidth(int);

//getters

int getHeight() const;
int getWidth() const;
int getPerimeter() const;
int getArea() const;
std::string getPerimeterString() const;

};

#endif