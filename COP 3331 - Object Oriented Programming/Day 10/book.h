#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book{

private:
    int year;
    int pages;
    std::string author;
    std:: string title;
    

public:


    //constructor
    Book(int year = 1990);

    //destructor
    ~Book();

    //setters
    void setYear(int);
    void setPages(int);
    void setAuthor(std::string);
    void setTitle(std::string);

    //getters
    int getYear() const;
    int getPages() const;
    std::string getAuthor() const;
    std::string getTitle() const;

};


#endif