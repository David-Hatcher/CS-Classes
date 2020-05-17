#pragma once

//©Amy Smajstrla
//SPC ID 538337

//#include <iostream>
//using namespace std;

//store a value that represents a number of work hours and convert it to a number of days 
//8 hours = 1 work day
//12 hours = 1.5 work days
//18 = 2.25 work days

class NumDays {

private:

	double hours;
	double days;

public:
	//(p.845)

	//constructor
	NumDays(double h = 0) {
		hours = h;
		days = h / 8;
	}

	//mutator functions
	void setHours(double h) {
		hours = h;
		days = h / 8;
	}

	void setDays(double d) {
		days = d;
		hours = d * 8;
	}

	//accessor functions
	double getHours()const {
		return hours;
	}

	double getDays() const {
		return days;
	}



	//overloaded operators
	//overloaded +
	NumDays operator+ (const NumDays& right) {
		NumDays temp;
		temp.setHours(hours + right.getHours());
		return temp;
	}
	//overloaded -
	NumDays operator- (const NumDays& right) {
		NumDays temp;
		temp.setHours(hours - right.getHours());
		return temp;
	}

	//overloaded prefix ++
	NumDays operator++ () {
		++hours;
		days = hours / 8;
		return *this; //returning *this (instead of temp) because of empty parameter
	}

	//overloaded prefix --
	NumDays operator--() {
		--hours;
		days = hours / 8;
		return *this; // returning *this (instead of temp) because of empty parameter
	}

	//overloaded postfix ++
	NumDays operator++(int) {
		hours++;
		NumDays temp(hours);
		days = hours / 8;
		return temp;
	}

	//overloaded operator postfix--
	NumDays operator--(int) {
		hours--;
		NumDays temp(hours);
		days = hours / 8;
		return temp;
	}

};


