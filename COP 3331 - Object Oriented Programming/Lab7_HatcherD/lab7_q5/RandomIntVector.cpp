#include <string>
#include <ctime>
#include <algorithm>
#include <numeric>
#include "RandomIntVector.h"

/**
 * gen_random creates a random number between the classes min and max values
 */
int RandomIntVector::gen_random(){
    int range = this->max - this->min;
    return (rand() % (range + 1)) + this->min;
}


/**
 * Constructor, creates the RandomIntVector filled with random integers
*/
RandomIntVector::RandomIntVector(int count){
    srand(time(nullptr));
    for(int i = 0; i < count; ++i){
        push_back(gen_random());
    }
}

/**\
 * get_str returns a string of all of the numbers in the vector, comma separated
*/
std::string RandomIntVector::get_str() const{
    std::string numbers = "";
    auto first = begin();
    auto last = end();
    for_each(first,--last,[&](int num){numbers += std::to_string(num) + ", ";});
    numbers += std::to_string(*(last));
    return numbers;
}

/**
 * get_sum returns the sum of all values in the vector
*/
int RandomIntVector::get_sum() const{
    auto b = begin();
    auto e = end();
    int sum = std::accumulate(b,e,0);
    return sum;
}

/**
 * get_avg returns the average of all the numbers in the vector
*/
double RandomIntVector::get_avg() const{
    int sum = get_sum();
    double average = ((double)sum)/((double)size());
    return average;
}