#include <string>
#include <ctime>
#include <algorithm>
#include <numeric>
#include "RandomIntVector.h"


int RandomIntVector::gen_random(){
    int range = this->max - this->min;
    return (rand() % (range + 1)) + this->min;
}

RandomIntVector::RandomIntVector(int count){
    srand(time(nullptr));
    for(int i = 0; i < count; ++i){
        push_back(gen_random());
    }
}

std::string RandomIntVector::get_str() const{
    std::string numbers = "";
    auto first = begin();
    auto last = end();
    for_each(first,--last,[&](int num){numbers += std::to_string(num) + ", ";});
    numbers += std::to_string(*(last));
    return numbers;
}

int RandomIntVector::get_sum() const{
    auto b = begin();
    auto e = end();
    int sum = std::accumulate(b,e,0);
    return sum;
}

double RandomIntVector::get_avg() const{
    int sum = get_sum();
    double average = ((double)sum)/((double)size());
    return average;
}