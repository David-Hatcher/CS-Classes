/*
Friend function
    allows you to directly access the private data members.
    must be declared in both
*/

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Product{
    string name;
    public:
    void setName(string name){
        this->name = name;
    }
    string getName(){
        return this->name;
    }
    virtual string get_description() = 0;
};

class Book : public Product{
    string author;

    public:
    Book(string name,string author){
        setName(name);
        this->author = author;
    }
    string get_description(){
        return getName() + " " + this->author + "\n";
    }
};

class Movie : public Product{
    string year;
    public:
    Movie(string name, string year){
        setName(name);
        this->year = year;
    }
    string get_description(){
        return getName() + " " + this->year + '\n';
    }
};

int main(){
    vector<Product*> products;

    Book book("book","author");
    Movie movie("movie","year");    

    products.push_back(&book);
    products.push_back(&movie);

    for_each(products.begin(),products.end(),[](Product *p){cout << (*p).get_description();});
}