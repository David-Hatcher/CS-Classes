#pragma once

//�Amy Smajstrla
//SPC 538337

//track an employee's sick leave, vacation, and unpaid time off
//it should have as members, the following instances of the NumDays Class

#include "NumDays.h"
#include <string>
using namespace std;

class TimeOff
{
private:
	NumDays maxSickDays;
	NumDays sickTaken;
	NumDays maxVacation;
	NumDays vacTaken;
	NumDays maxUnpaid;
	NumDays unpaidTaken;

	// double maxSickDays;
	// double sickTaken;
	// double maxVacation;
	// double vacTaken;
	// double maxUnpaid;
	// double unpaidTaken;

	string employeeName;
	int employeeIDNumber;

public:
	//(p.845)

	//constructor
	TimeOff(double mths =0.0, double st =0.0, double mth = 0.0, double vt = 0.0, double mu = 0.0, double ut = 0.0, string en ="", int ein = 0) {
		this->maxSickDays.setHours(mths);
		this->sickTaken.setHours(st);
		this->maxVacation.setHours(mth);
		this->vacTaken.setHours(vt);
		this->maxUnpaid.setHours(mu);
		this->unpaidTaken.setHours(ut);
		this->maxSickDays.setHours(mths);
		// sickTaken = st;
		// maxVacation = mth;
		// vacTaken = vt;
		// maxUnpaid = mu;
		// unpaidTaken = ut;
		this->employeeName = en;
		this->employeeIDNumber = ein;

	}


	////mutator functions
	void setMaxSickDays(double mths) {
		this->maxSickDays.setHours(mths*8);
		//maxSickDays = mths *8;
	}
	void setsickTaken(double st) {
		this->sickTaken.setHours(st);
		//sickTaken = st;
	}
	void setMaxVacation(double mth) {
		//maxVacation should not accumulate more than 240 hours of paid vacation
		double maxVaca = mth * 12;
		if (maxVaca <= 240) { this->maxVacation.setHours(maxVaca); }
		else this->maxVacation.setHours(240);
	}
	void setvacTaken(double vt) {
		this->vacTaken.setHours(vt);
		//vacTaken = vt;
	}
	void setMaxUnpaid(double mu) {
		this->maxUnpaid.setHours(mu);
		//maxUnpaid = mu;
	}
	void setUnpaidTaken(double ut) {
		this->unpaidTaken.setHours(ut);
		//unpaidTaken = ut;
	}
	void setEmployeeName(double en) {
		employeeName = en;
	}
	void setMEmployeeIDNumber(double ein) {
		employeeIDNumber = ein;
	}


	//accessor functions
	double getMaxSickDays()const {
		return this->maxSickDays.getDays();
	}
	double getsickTaken()const {
		return this->sickTaken.getDays();
	}
	double getMaxVacation()const {
		return this->maxVacation.getDays();
	}
	double getvacTaken()const {
		return this->vacTaken.getDays();
	}
	double getMaxUnpaid()const {
		return this->maxUnpaid.getDays();
	}
	double getUnpaidTaken()const {
		return this->unpaidTaken.getDays();
	}
	string getEmployeeName()const {
		return employeeName;
	}
	int getMEmployeeIDNumber()const {
		return employeeIDNumber;
	}


};

