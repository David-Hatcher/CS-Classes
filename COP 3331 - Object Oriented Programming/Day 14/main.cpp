#include <string>



class Product{
private:
    std::string name;
    double price;
    int discount_percent;
    static int object_count;

public:
    Product(std::string name_param = " ",double price = 0.0, int discount_pct = 0.0){
        name = name_param;
        this->price = price;
        discount_percent = discount_pct;
        object_count++;
    }

    static int getCount(){
        return object_count;
    }

};

int Product::object_count = 0;

using namespace std;

int main(){

    Product p();
    int count = p.getCount();

    //friend functions
    //friend void pour(FuelTank& tank, FuelCan& can);

    //can implement with save and load methods

    //overloading operators

    //FuelTank FuelTank::operator+(const FuelTank& right){
    //  FuelTank t;
    //  t.set_gallons(gallons + right.gallons);
    //  return t;   
    //}

    //Inventory Inventory::operator+(const Item& right){
    //  push_back(right);    
    //}

}