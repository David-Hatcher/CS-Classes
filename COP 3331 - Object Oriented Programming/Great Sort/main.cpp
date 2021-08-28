#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

void buildArray(vector<int>& vect);
vector<int> bestSorterEverEveryoneSaysSo(vector<int>);
bool isVectorSorted(vector<int> vect_to_test);
vector<int> maybeSorter(vector<int> unrand_vector);
int randomGenerator(int max);

int main(){
    srand(time(nullptr));
    vector<int> unsorted;
    buildArray(unsorted);
    vector<int> most_definitely_sorted = bestSorterEverEveryoneSaysSo(unsorted);
    cout << "Sorted array for your pleasure: ";
    for(auto i = most_definitely_sorted.begin(); i < most_definitely_sorted.end(); ++i){
        cout << (*i) << " ";
    }

    return 0;
}

void buildArray(vector<int>& vect){
    cout << "Enter 10 numbers(Separated by a space):";
    int current_number;
    for(int i = 0; i < 10; ++i){
        cin >> current_number;
        vect.push_back(current_number);
    }
}


vector<int> bestSorterEverEveryoneSaysSo(vector<int> to_sort){
    int count = 0;
    while(true){
        count++;
        vector<int> maybe_sorted = maybeSorter(to_sort);
        if(isVectorSorted(maybe_sorted)){
            cout << "Array sorted in " << count << " attempts" << endl;
            return maybe_sorted;
        }
    }

}

bool isVectorSorted(vector<int> vect_to_test){
    bool is_sorted = true;
    for(auto i = vect_to_test.begin(); i < vect_to_test.end() - 1; ++i){
        if((*i) > (*(i+1))){
            is_sorted = false;
        }
    }
    return is_sorted;
}

vector<int> maybeSorter(vector<int> unrand_vector){
    int length = unrand_vector.size();
    vector<int> probably_sorted_vector;
    for(int i = 0; i < length; ++i){
        int an_int = randomGenerator(unrand_vector.size());
        probably_sorted_vector.push_back(unrand_vector.at(an_int));
        unrand_vector.erase(unrand_vector.begin() + an_int);
    }
    return probably_sorted_vector;
}

int randomGenerator(int max){
    if(max == 0){return 0;}
    return rand() % max;
}
