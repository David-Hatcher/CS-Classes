#include <iostream>
using namespace std;

class Square; // forward declaration

class Box {
    double width;
    double height;

public:
    friend void printArea(Box box);
    friend void is_equal(Box box, Square square);

    Box(double w, double h) {
        width = w;
        height = h;
    }

    void setWidth(double wid) {
        width = wid;
    }
    double getWidth() {
        return width;
    }
    void setHeight(double hei) {
        height = hei;
    }
    double getHeight() {
        return height;
    }
};

class Square {
    double side;

public:
    friend void is_equal(Box box, Square square);

    Square(double s = 5.0) {
        side = s;
    }
    void setSide(double sid) {
        side = sid;
    }
};

// Note: printWidth() is not a member function of any class.
void printArea(Box box) {
    /* Because printWidth() is a friend of Box, it can
    directly access any member of this class */
    cout << "Area of box : " << box.width * box.height << endl;
}

void is_equal(Box box, Square square) {
    if ((box.width == square.side) && (box.height == square.side)) {
        cout << "These boxes have the same area!" << endl;
    }
    else {
        cout << "These boxes do not have the same area!" << endl;
    }
    return;
}

// Main function for the program
int main() {
    Box box(10, 10);   
    Square square1(10);
    Square square2(5);

    // Use friend functions 
    printArea(box);
    is_equal(box, square1);
    is_equal(box, square2);

    return 0;
}