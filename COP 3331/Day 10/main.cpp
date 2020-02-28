#include <iostream>
#include "book.h"

using namespace std;

/**
 * Flex Project:
 * 
 * need to submit first proposal by 11th
 * 
 * 
 * 
 * 
 * Classes
 *  Classes allow encapsulation, private, public data members structures do not
 * 
 * 
*/

int main(){
    Book book;
    book.setYear(1874);
    book.setPages(322);
    book.setAuthor("John Eoin");
    book.setTitle("The Adventure of the Programming Class");

    cout << book.getTitle() << " was written in " << book.getYear() << " by " << book.getAuthor() << ". It has " << book.getPages()
    << " pages." << endl;

    return 0;
}