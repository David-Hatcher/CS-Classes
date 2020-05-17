//�Amy Smajstrla
//SPC ID 538337

#include <iostream>
#include "TimeOff.h"
//#include "NumDays.h"

using namespace std;

int main() {

	double months;

	cout << "Please enter the number of months the employee has worked for the company: " << endl;
	cin >> months;

	//should then use the TimeOff Object to calculate and display the employee's max num of sick leave and vacation days.
	//employees can earn 12 hours of vacation leave and 8 hours of sick leave per month

	TimeOff timeoff;
	
	timeoff.setMaxSickDays(months);
	timeoff.setMaxVacation(months);

	cout << "max sick days: " << endl;
	cout <<  timeoff.getMaxSickDays()<< endl;
	cout << "max vacation days: " << endl;
	cout<< timeoff.getMaxVacation() << endl;


	return 0;
}