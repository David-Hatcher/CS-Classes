#include <iostream>
#include <iomanip>


//sequence containers by index
#include <array>// c
#include <vector> //c (best performing)
#include <list> //nc
#include <forward_list> //nc

//adapters
#include <queue> //fifo
#include <stack> //lifo

//Associative Containers by key
#include <set> //NC
#include <map>//nc
//pair
//multimap //nc
//multiset //nc


using namespace std;
int main(){

    /*
    Vectors:
        random acces iterates forward or backward, r/w repeatedly, access elements in random order
        contiguous: elements are stored in contiguous memory
    */

    vector<int> v{0,1,2,3,4,5};
    // vector<int>::iterator iter_b = v.begin();can be dont this way but it's easier to use auto
    auto iter_b = v.begin(); //iterator that poits to the first element
    auto iter_e = v.end(); //iterator that points past the last element, off-the-end

    //iterating through the vector
    for(unsigned int i = 0; i < v.size(); ++i){
        cout << v[i] << endl;
    }
    cout << endl;
    for(auto i = v.begin(); i != v.end(); ++i){
        cout << *i << endl;
    }
    cout << endl;

    //assign
    vector<int> v2;
    v2 = v;
    for(int number : v2){
        cout << number << endl;
    }
    cout << endl;

    v2.assign(v.begin(),v.begin() + 2);
    for(int element : v2){
        cout << element << endl;
    }
    cout << endl;

    //resize
    v.resize(3);
    for(int element : v){
        cout << element << endl;
    }
    cout << endl;

    //understanding capactiy
    int cap = v.capacity();
    cout << "Capacity: " << cap << endl;
    auto iter = v.begin();
    cout << "Now: " << *iter << endl;
    
    for(unsigned int i = 0; i < 100; ++i){
        v.insert(v.begin() + i, i); //increasing capacity meaing deallocate old memory, can use reserve in advance
    }
    //iter = v.begin();//this will make the correct value show.

    cout << "Then: " << *iter << endl;

    //array:
    /*
        push_back
        pack_back
        insert
        erase
        clear
    */

   cout << "***********************" << endl << setw(15) << "Arrays" << endl << "***********************" << endl;
   array<int,10> grades{0};
   array<int,3> grades2{90,94,91};
   for(int g : grades){
       cout << g << endl;
   }

   cout << endl;
   for(int g : grades2){
       cout << g << endl;
   }


   cout << "***********************" << endl << setw(15) << "Lists" << endl << "***********************" << endl;

   /*
        List
            -non-contiguous memory
            uses pointers to link to element in front and behind
            double linked list
            can traverse forward and backward
        Forward list
            non-contiguous memory
            points only point to element in front
            single linked list
            can only traverse forward

        What does this imply about moving and adding elements and the iterator?

        things to consider
            overhead of pointers
            contiguous memory is faster to acces
   */


    list<int> num{1,2,3,4,5,};
    list<int> x{23,10,1,11,12};
    forward_list<int> num2{6,7,8,9,10};
    x.splice(x.begin(),num,num.begin(), ++num.begin());
    for(int item: x){
        cout << item << endl;
    }

  cout << endl;
    //sort this can also sort strings
    x.sort();
    for(int item : x){
        cout << item << endl;
    }
    cout << endl;

    cout << "x" << endl;
    x.merge(num);// merge removes the values from num and places them in x
    for(int item : x){
        cout << item << endl;
    }
    cout << endl;

    cout << "num" << endl;
    for(int item : num){
        cout << item << endl;
    }
    cout << endl;


    cout << "***********************" << endl << setw(15) << "set" << endl << "***********************" << endl;
        /*
            Set : Stores a set of unique keys in sorted order
            Multiset : allows duplicate keys

            non-contigueous memory
            binary search means faster retrevial
        */

    set<int> numbers{1,2,3};
    numbers.insert(4);
    numbers.insert(4);
    numbers.insert(5);

    for(int i: numbers){
        cout << i << endl;
    }
    cout << endl;
    cout << numbers.count(4);

    cout << "***********************" << endl << setw(15) << "Map" << endl << "***********************" << endl;

    map<string,int> letters{{"a",1}, {"b",2}, {"c",3}};

    for(pair<string,int> l : letters){
        cout << l.first << " " << l.second << endl;
    }

    letters.insert({"d",4});
        for(pair<string,int> l : letters){
        cout << l.first << " " << l.second << endl;
    }
    cout << "***********************" << endl << setw(15) << "queu/stack" << endl << "***********************" << endl;
    queue<int> q;
    q.push(1);
    q.push(2);
    cout << q.front() << endl;
    cout << q.back() << endl;

    stack<int> s;
    s.push(1);
    s.push(2);
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;


    return 0;
}