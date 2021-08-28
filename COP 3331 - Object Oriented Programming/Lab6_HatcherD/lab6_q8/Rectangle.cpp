#include "Rectangle.h"
#include <string>

//private member functions

/**
 * getHorizontals returns the string for the horizontal sides of the rectangle
*/
std::string Rectangle::getHorizontals()  const{
    std::string horizontal = "";
    for(int i = 0; i < this->width; ++i){
        horizontal += "* ";
    }
    horizontal += '\n';
    return horizontal;

}

/**
 * getVerticals returns the string for the vertical sides of the rectangle
*/
std::string Rectangle::getVerticals() const{
    std::string vertical = "";
    if(this->width == 1){
        for(int i = 0; i < this->height - 2; ++i){
            vertical += "*\n";
        }
    }else{
        for(int i = 0; i < this->height - 2; ++i){
            vertical += "* ";
            for(int j = 0; j < this->width - 2; ++j){
                vertical += "  ";
            }
            vertical += "*\n";
        }
    }
    
    return vertical;
}

//setters

void Rectangle::setHeight(int height){
    this->height = height;
}

void Rectangle::setWidth(int width){
    this->width = width;
}

//getters

int Rectangle::getHeight() const{
    return this->height;
}

int Rectangle::getWidth() const{
    return this->width;
}

/**
 * getPerimeter returns the perimeter of the rectangle
*/
int Rectangle::getPerimeter() const{
    return this->height*2 + this->width*2;
}

/**
 * getArea returns the are of the rectangle
*/
int Rectangle::getArea() const{
    return this->height * this->width;
}

/**
 * getPerimeterString gives the full perimeter string of the rectangle.
*/
std::string Rectangle::getPerimeterString() const{
    if(this->height == 1){
        return this->getHorizontals() + this->getVerticals();
    }
    return this->getHorizontals() + this->getVerticals() + this->getHorizontals();
}
