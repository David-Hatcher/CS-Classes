#include <iostream>
#include <list>
#include <ctime>
#include <algorithm>


using namespace std;

int generateRandom(int min, int max);
list<int> generateRandomList(int count,int min,int max);

int main(){
    srand(time(nullptr));
    
    list<int> randoms = generateRandomList(10,0,100);
    for_each(randoms.begin(),randoms.end(),[](int val){cout << val << " ";});
    return 0;
}

int generateRandom(int min, int max){
    return (rand() % (max - min + 1)) + min;
}

list<int> generateRandomList(int count, int min, int max){
    list<int> random_list(count);
    for_each(random_list.begin(),random_list.end(),[=](int &val){val = generateRandom(min,max);});
    return random_list;
}