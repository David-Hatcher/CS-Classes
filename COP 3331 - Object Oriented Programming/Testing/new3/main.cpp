//©Amy Smajstrla
//SPC ID 538337
//Ch13 Assignment, page 808, #2 Employee Class
//extra instructions: please submit just one file for the class and main to test the class
#include <iostream>
using namespace std;
class Employee
{
public:
	//constructor
	Employee() {																//default constructor, p771
		//initialize all the private members
		name = "";
		idNumber = 0;
		department = "";
		position = "";
	}
	Employee(string aName, int aidNumber, string adepartment, string aposition) {
		name = aName;
		idNumber = aidNumber;
		department = adepartment;
		position = aposition;
	}
	Employee(string aName, int aidNumber) {
		name = aName;
		idNumber = aidNumber;
		department = "";
		position = "";
	}
	//mutator functions p.772
	void setname(string aName) {
		name = aName;
	}
	void setidNumber(int aidNumber) {
		idNumber = aidNumber;
	}
	void setdepartment(string adepartment) {
		department = adepartment;
	}
	void setposition(string aposition) {
		position = aposition;
	}
	//accessor functions p772
	string getname() const {
		return name;
	}
	int getidNumber() const {
		return idNumber;
	}
	string getdepartment() const {
		return department;
	}
	string getposition() const {
		return position;
	}
	//deconstructor
	~Employee(){
        free(this);
    }	//deconstructor
private:
	string name;
	int idNumber;
	string department;
	string position;
};
//automatically generated, but since the member function body's were small and only one line, 
//I instead made them p.751 inline comments shown above, instead of p.730-732
//Employee::Employee()								
//{
//}
//Employee::~Employee()
//
//}
int main() {
	//p.778 array of class objects
	const int NUM_ITEMS = 3;
	Employee employee[NUM_ITEMS]{
		Employee("Susan Meyers", 47899, "Accounting", "Vice President"),
		Employee("Mark Jones", 39119, "IT", "Programmer"),
		Employee("Joy Rogers", 81774, "Manufacturing", "Engineer"),
	};
    for(int i = 0; i < NUM_ITEMS; ++i){
        cout << employee[i].getname() << ' ' << employee[i].getidNumber() << ' ' << employee[i].getdepartment() << ' ' << employee[i].getposition() << endl;
    }
	return 0;
}