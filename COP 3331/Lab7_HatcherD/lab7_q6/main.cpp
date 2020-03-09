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

void Flight::setHoursMinutes(){
    double hours_in_dec = (double)miles / (double)miles_per_hour;
    hours = hours_in_dec;
    minutes = ((hours_in_dec - hours)*60);
}

void Flight::calcFuel(){
    fuel = hours*gallons_per_hour;
    fuel += (((double)minutes + 30)/60)*(double)gallons_per_hour;
    fuel = ceil(fuel*10)/10.0;
}

void printTitle(string output){
    cout << left << output << endl << endl;
}

void getMiles(Flight& flight){
    cout << "Distance in nautical miles: ";
    cin >> flight.miles;
}

void printFlightTime(const Flight& flight){
    cout << "Flight time: " << flight.hours << " hour(s) and " << flight.minutes << " minute(s)" << endl;
}

void printFuel(const Flight& flight){
    cout << "Required fuel: " << flight.fuel << " gallons" << endl;
}

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