#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <list>
#include <map>
#include <stack>
#include <cmath>


using namespace std;




int main(){
int limit = 0;
for (int i = 10; i >= limit; i -= 2) {
       for (int j = i; j <= 1; ++j) {
             cout << "In inner for loop" << endl;
       }
       cout << "In outer for loop" << endl;
}
}