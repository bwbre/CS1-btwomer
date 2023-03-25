/* 
Brendan Womer
CS1 - HW 4 Conditionals

Description : This is a program that will return a variety of useful information using 5 numbers that are provided by the user.

Program Steps:
1. Prompt user for 5 numbers and their name.
9. Greet user
2. Define a function that returns the sum for the 5 numbers.
3. Define a function that returns the product for the 5 numbers.
4. Define a function that returns the average for the 5 numbers.
5. Define a function that returns the smallest value out of the 5 numbers (without using a built-in functions).
6. Define a function that returns the smallest value out of the 5 numbers (without using a built-in functions).
7. Define a function that will return whether or not the floor of the sum is odd, even, or zero. (floor of sum is the sum of all 5 numbers rounded down to nearest integer)
8. Create a basic menu interface to prompt user what functions/features they want to call.
9. Define a test function that will verify the accuracy of the previously defined functions. (Call only when test argument is passed to main).
10. Loop as many times as the user wants.

Notes: at least one must be able to accept multiple data types

array for 5 nums
sum
product
average (using sum)
smallestvalue
largest value
definefloor(array)


*/
#include <iostream>
#include <iomanip>

using namespace std;

template <class T1>
    T1 promptnums(T1 nums[]) {
        cout << "Please enter 5 different numbers separated by spaces:  ";
        T1 num1, num2, num3, num4, num5;
        cin >> num1 >> num2 >> num3 >> num4 >> num5 >> endl;
        num1 = nums[1];
        num2 = nums[2];
        num3 = nums[3];
        num4 = nums[4]; 
        num5 = nums[5];
        cout << num1 << " " << num2 << " " << num3 <<endl;
        return 0;

    }


template <class T1>
    T1 sum(T1 nums[]) {

        return (nums[1] + nums[2] + nums[3] + nums[4] + nums[5]);
    }





int main(int argc, char *argv[]) {
    double *nums[5];
    bool keeprunning;
    // bool *keeprunptr;
    // keeprunptr = &keeprunning;
    keeprunning = true;
    cout << "initializing...\n" << endl;
    // if (keeprunning == true) {
    promptnums(nums[]);
    cout << sum<double>(nums[]) << endl;
        
    //  }

     cout << "the end.\n";
    return 0;
}

