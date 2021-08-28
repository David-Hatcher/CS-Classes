#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <map>
#include <string>
#include <algorithm>

using namespace std;


//How to work with STL algorithms

//containers, iterators, algorithms

//algorithms work wit iterators not containers

/**
 * count(vec.begin(),vec.end(),'1');
*/

/**
 * Non mod
 * count
 * for_each
 * find
 * search(to_search.begin(),to_search.end(),to_find.begin(),to_find.end());
 * 
Modifying operation
replace
fill
copy
remove - this just moves the values to the end of the container, not actually remove them
        must call erase for the same value

iota(b,e,val) fills an interval with incremented values
accumulate(b,e,val) totals values + val
accumulate(b,e,function)
*/

/**
 * sort(b,e)
 * sort(b,e,func)
 * binary_search(b,e,val) *******Must sort first*******
 * 
 * 
 * count_if(b,e,func or val)
 * 
 * 
 * templating
*/
template<typename T>    
void displayTemp(T value){
    cout << value << ' ';
}

void display(string value){
    cout << value << ' ';
}
void displayPair(pair<string,double> p){
    cout << p.first << " $" << p.second << " ";
}

bool sort_descending(int a, int b){
    return a > b;
}

struct Under{

    double limit;

    Under(double max){
        limit = max;
    }

    bool operator() (pair<string,double> p) const{
        return p.second < limit;
    }
};

//lambda

//[captures] (parameter_list) [->return_type]



int main(){
    vector<int> nums{1,2,3,4,5};
    for_each(nums.begin(),nums.end(),[](int val){cout << val << ' ';});



    map<string,double> products {{"guitar",199.99},
                                 {"piano",799.99}};

    auto num_low = count_if(products.begin(),products.end(),Under(500.00));
    cout << num_low << endl;
    num_low = count_if(products.begin(),products.end(),Under(800.00));
    cout << num_low << endl;

    for_each(products.begin(),products.end(),displayPair);

    vector<char> vec {'h','e','l','l','o'};

    set<string> states {"OR","WA","CA","AK","HI"};

    for_each(states.begin(),states.end(),display);

    int c = count(vec.begin(),vec.end(),'l');
    sort(vec.begin(),vec.end());
    sort(vec.begin(),vec.end(),sort_descending);

    return 0;
}