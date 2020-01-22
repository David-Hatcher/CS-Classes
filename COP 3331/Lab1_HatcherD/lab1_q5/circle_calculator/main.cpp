#include <iostream>
#include <cmath>

using namespace std;
/**
 * Author: M. Delamater
 * Edited by: David Hatcher
 * Purpose: This program allows the user to give a diameter
 *          of a circle and it will tell the user the radius
 *          circumference and area of that circle 
*/

int main()
{
    // print name of program
	cout << "Circle Calculator" << endl << endl;

    // get radius from user
	double diameter;
    cout << "Enter diameter:  ";
    cin >> diameter;

    // make calculations
    double pi = 3.14159;
    double radius = diameter/2;
    double circumference = diameter * pi;
    double area = pi * pow(radius, 2.0);

    // round to 1 decimal place
    circumference = round(circumference * 10) / 10;
    area = round(area * 10) / 10;

    // write output to console
    cout << "Radius:      " << radius << endl
        << "Circumference: " << circumference << endl
        << "Area:          " << area << endl << endl
        << "Bye!" << endl << endl;

    // return value that indicates normal program exit
    return 0;
}