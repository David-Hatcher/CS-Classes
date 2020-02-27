#include "book.h"
#include <string>


//setters
void Book::setYear(int year){
    this->year = year;
}

void Book::setPages(int pages){
    this->pages = pages;
}

void Book::setAuthor(std::string author){
    this->author = author;
}

void Book::setTitle(std::string title){
    this->title = title;
}

//getters
int Book::getYear() const{
    return this->year;
}

int Book::getPages() const{
    return this->pages;
}

std::string Book::getAuthor() const{
    return this->author;
}

std::string Book::getTitle() const{
    return this->title;
}
