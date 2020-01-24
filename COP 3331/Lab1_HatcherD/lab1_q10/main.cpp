#include <iostream>
#include <cmath>


using namespace std;

double findAverage(double nums[], int count);
double findSum(double nums[],int count);
double findProduct(double nums[],int count);
void printAbsValue(double nums[], int count);
/*
 *Author: David Hatcher
 *Purpose:  This program will ask the user to enter five numbers
 *          after given these numbers it will find the average,
 *          sum, product, and each numbers absolute value of the
 *          set of numbers given. It will then display all of these
 *          values in the console.
 */
int main(){
    //ask user for 5 values and create an array to hold them
    cout << "Enter Five Numbers: ";
    int nums_count = 5;
    double nums[5];
    
    //populating array with values
    for(int i = 0;i < 5;i++){
        cin >> nums[i];
    }

    //firing methods to determine important values
    double sum = findSum(nums,nums_count);
    double average = findAverage(nums,nums_count);
    double prod = findProduct(nums,nums_count);

    //printing out values and final string
    cout << "Sum: " << sum << endl;
    cout << "Average: " << average << endl;
    cout << "Product: " << prod << endl;
    printAbsValue(nums,nums_count);
    cout << "Done" << endl;

    return 0;
}

/*
 *printAbsValue takes an array of doubles and a count
 *it will then print out the absolute value of each of
 *those values on a single line
 */
void printAbsValue(double nums[], int count){
    cout << "Absolute Values:";
    for(int i = 0; i < count; i++){
        cout << ' ' << abs(nums[i]);
    }
    cout << endl;
}

/*
 *findAverage takes an array of doubles and a count
 *and will return the average of that array
 */
double findAverage(double nums[], int count){
    double sum = 0;
    for(int i = 0; i < count; i++){
        sum += nums[i];
    }
    return (double)(sum/count);
}

/*
 *findSum takes an array of doubles and a count
 *and returns the sum of those numbers
 */
double findSum(double nums[],int count){
    double sum = 0.0;
    for(int i = 0; i < count; i++){
        sum+=nums[i];
    }
    return sum;
}

/*
 *findProduct takes an array of doubles and count
 *and returns the product of those numbers
 */
double findProduct(double nums[],int count){
    double prod = 1;
    for(int i = 0;i < count;i++){
        prod *= nums[i];
    }
    return prod;
}