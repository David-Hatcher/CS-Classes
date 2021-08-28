#include <iostream>
#include <cmath>
#include <limits>


using namespace std;

const double gallons_per_hour = 8.4;
const int miles_per_hour = 120;
const string CONTINUE_STRING = "Continue? (y/n): ";
const string TITLE = "Aircraft Fuel Calculator";


struct Flight{
    double miles;
    int hours;
    int minutes;
    double fuel;
    void calcFuel();
    void setHoursMinutes();
};

void printTitle(string output);
void getMiles(Flight& flight);
void printFlightTime(const Flight& flight);
void printFuel(const Flight& flight);
bool askContinue(string output);
/**
 * Author: David Hatcher
 * Purpose: This program allows the user to enter a distance in nautical miles
 * of a flight and it determines the required fuel for a 1980 Cessna 172N
*/
int main(){
    printTitle(TITLE);
    bool cont = true;

    while(cont){
        Flight current_flight;
        getMiles(current_flight);
        current_flight.setHoursMinutes();
        printFlightTime(current_flight);
        current_flight.calcFuel();
        printFuel(current_flight);
        cont = askContinue(CONTINUE_STRING);
    }


}

/**
 * setHoursMinutes sets the hours and minutes of a Flight Object
*/
void Flight::setHoursMinutes(){
    double hours_in_dec = (double)miles / (double)miles_per_hour;
    hours = hours_in_dec;
    minutes = ((hours_in_dec - hours)*60);
}

/**
 * calcFuel sets the fuel required for the flight and assigns it to the fuel member
*/
void Flight::calcFuel(){
    fuel = hours*gallons_per_hour;
    fuel += (((double)minutes + 30)/60)*(double)gallons_per_hour;
    fuel = ceil(fuel*10)/10.0;
}

/**
 * printTitle prints the title of the program
*/
void printTitle(string output){
    cout << left << output << endl << endl;
}

/**
 * getMiles takes a Flight object and asks the user for a distance in miles
*/
void getMiles(Flight& flight){
    cout << "Distance in nautical miles: ";
    cin >> flight.miles;
}

/**
 * printFlightTime takes a Flight object and prints the flight time to the console
*/
void printFlightTime(const Flight& flight){
    cout << "Flight time: " << flight.hours << " hour(s) and " << flight.minutes << " minute(s)" << endl;
}

/**
 * printFuel takes a Flight object and prints the required fuel to the console
*/
void printFuel(const Flight& flight){
    cout << "Required fuel: " << flight.fuel << " gallons" << endl;
}

/**
 * askContinue takes a string, outputs it to the console and asks the user for a y or n the returns it
 * it also has cin error handling and handling for incorrect inputs
*/
bool askContinue(string output){
    cout << endl << output;
    char input;
    cin >> input;
    cout << endl;
    if(tolower(input) == 'y'){
        return true;
    }else if(tolower(input) == 'n'){
        return false;
    }else{
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << left << "Invalid Input please enter y or n!" << endl;
        return askContinue(output);
    }
}