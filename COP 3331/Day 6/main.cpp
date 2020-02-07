#include <iostream> 
#include <vector> 
 
using namespace std; 
/** 
 * Chapter 9: How to work with structures and enumerations 
 */ 
struct Movie{ 
    string title = ""; 
    int year = 0; 
    bool equals(const Movie&); 
    bool operator==(const Movie& to_compare){ 
        return (title == to_compare.title && year == to_compare.year); 
    } 
}; 
 
bool Movie::equals(const Movie& to_compare){ 
    return (title == to_compare.title && year == to_compare.year); 
} 
 
 
void updateMovie(Movie& movie); 
bool compareMovies(Movie movie1, Movie movie2); 
//eumerators 
 
enum class Operation{add = 0, subtract, multiply, divide}; 
 
double calc(Operation op, double n1, double n2); 
 
 
int main(){ 
     
    Movie movie; 
    movie.title = "Wonder Woman"; 
    movie.year = 2017; 
    Movie movie2 = {"Casablanca", 1942}; 
 
    Movie movie1; 
    movie1.title = "Wonder Woman"; 
    movie1.year = 2017; 
 
    vector<Movie> movies; 
    movies.push_back(movie); 
    movies.push_back(movie2); 
 
    bool duplicate; 
    duplicate = (movie == movie1); 
    cout << duplicate << endl; 
    if(duplicate){ 
        cout << "true\n"; 
    } 
    for(Movie m : movies){ 
        cout << "Title: " << m.title << endl; 
        cout << "Year: " << m.year << endl; 
    } 
 
    //enum 
    Operation op; 
    op = Operation::add;//op = 0 
 
 
    return 0; 
} 
 
bool compareMovies(Movie movie1, Movie movie2){ 
    if(movie1.title == movie2.title){ 
        if(movie1.year == movie2.year){ 
            return true; 
        } 
    } 
    return false; 
} 
 
double calc(Operation op, double n1, double n2){ 
    if(op < Operation::add || op > Operation::divide){ 
        cout << "Invalid input" << endl; 
        return 0.0; 
    } 
    switch (op){ 
        case Operation::add: 
            return n1 + n2; 
        case Operation::subtract: 
            return n1 - n2; 
        case Operation::multiply: 
            return n1 * n2; 
        case Operation::divide: 
            return n1 / n2; 
        default: 
            return 0.0; 
            break; 
    } 
} 
