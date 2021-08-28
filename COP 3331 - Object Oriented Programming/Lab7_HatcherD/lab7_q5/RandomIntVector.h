#ifndef RANDOMINTVECTOR_H
#define RANDOMINTVECTOR_H

#include <vector>
#include <string>

class RandomIntVector : public std::vector<int>{

private:
    int min = 1;
    int max = 100;
    int gen_random();

    
public:
    RandomIntVector(int count);
    std::string get_str() const;
    double get_avg() const;
    int get_sum() const;

};


#endif