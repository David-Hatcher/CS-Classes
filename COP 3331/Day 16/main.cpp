#include <iostream>
#include <string>

using namespace std;

class Calculator{
private:
    int result;
public:
    Calculator& multiply(int a, int b){
        this->result = a * b;
        return *this;
    }

    Calculator& square_result(){
        this->result *= this->result;
        return *this;
    }

    int get_result(){
        return this->result;
    }
};

template <class T>
void square(T* val){
    if(val != nullptr){
        *val *= *val;
    }
}


int main(){
    int num = 200;

    int* ptr = &num;

    cout << "ptr " << ptr << endl;
    cout << "*ptr " << *ptr << endl;

    *ptr = 1200;

    cout << "ptr " << ptr << endl;
    cout << "*ptr " << *ptr << endl;

    string s = "hello";

    string* sptr = &s;

    cout << "S length " << sptr->size() << endl;

    /* Pointer Creation Syntax
    type* name [= &object];
    type *name [= &object];
    type * name [= &object];
    */

    /*Null pointers*/

    int* ip1 = nullptr;
    int* ip2 = NULL;
    int* ip3 = 0;

    double d = 4.0;
    double* dptr = &d;

    int i = 5;
    int* iptr = &i;


    square(iptr);
    square(dptr);
    cout << *dptr << endl;
    cout << *iptr << endl;

    Calculator calc;
    Calculator calc2;
    calc.multiply(2,5);
    calc.square_result();

    cout << "Calc " << calc.get_result() << endl;
    cout << "Calc2 " << calc2.multiply(2,5).square_result().get_result() << endl;

    return 0;
    }