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
5] sum
6] product
7] average (using sum)
8] smallestvalue
9] largest value
10] definefloor(array)

---nums[] = {num1, num2, num3, num4, num5, sum, product, avg, smallestvalue, largestvalue, definefloor}

*/
#include <iostream>
#include <iomanip>

using namespace std;

void printarray(double*, int);
void smallestnumber(double*);

//will use first 5 elements of nums[]
template <class T1>
    T1 promptnums(T1 nums[]) {
        //prompt user for 5 numbers, then assign each number to the first 5 positions in the array.
        cout << "Please enter 5 different numbers separated by spaces:  ";
        cin >> nums[0] >> nums[1] >> nums[2] >> nums[3] >> nums[4];
        cout << "\n--Finished storing values." << endl;
        // printarray(nums, 5);
        return 0;
    }

//will calculate the sum and will save the result in the 6th element -- nums[5]
template <class T1>
    T1 sum(T1 nums[]) {
        T1 result = (nums[1] + nums[2] + nums[3] + nums[4] + nums[0]);
        printf("\n%.2f + %.2f + %.2f + %.2f + %.2f = %.2f\n", nums[0], nums[1], nums[2], nums[3], nums[4], result);
        //store the result in element 6 of nums[]
        nums[5] = result;
        cout << "The sum of all 5 numbers is: " << result << " And num[5] = " << nums[5] << endl;
        return 0;
    }

//will calculate the product and will save the result in the 7th element -- nums[6]
template <class T1>
    T1 product(T1 nums[]) {
        T1 result = (nums[1] * nums[2] * nums[3] * nums[4] * nums[0]);
        printf("\n%.2f * %.2f * %.2f * %.2f * %.2f = %.2f\n", nums[0], nums[1], nums[2], nums[3], nums[4], result);
        //store the result in element 7 of nums[]
        nums[6] = result; 
        cout << "The product of all 5 numbers is : " << result << " And num[6] = " << nums[6] << endl;
        return 0;
    }

// will calculate the average and will save the result in the 8th element -- nums[7]
template <class T1>
    T1 avg(T1 nums[]) {
        T1 result = (nums[5] / 5);
        // printf("\n%.2f + %.2f + %.2f + %.2f + %.2f = %.2f\nT", nums[0], nums[1], nums[2], nums[3], nums[4], result);
        nums[7] = result; 
        cout << "\nThe average of all 5 numbers is : " << result << " And num[6] = " << nums[7] << endl;

        return 0;
    }




int main() {
    //create array that will hold all the values that will be used in the program.
    double nums[11] = {0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0, 0, 0};
    //keeprunning will remain true until the user prompts to end the program.
    bool keeprunning;
    keeprunning = true;

    //debug
    cout << "\n--initializing...\n" << endl;

    promptnums(nums);
    sum(nums);
    product(nums);
    avg(nums);
    smallestnumber(nums);
    printarray(nums, 10);

    //debug
    cout << "\nthe end." <<endl;
    return 0;
}






void printarray(double array[], int length) {
    cout << "\nThe array printed : \n";
    for (int n=0; n < length; n++){
        cout << "nums[" << n << "]" << array[n] << endl;
    }
}

void smallestnumber(double nums[]) {
    double smallestnumber;
    cout << "\n";
    if (nums[0] < nums[1] && nums[0] < nums[2] && nums[0] < nums[3] && nums[0] < nums[4]) {
        // cout << "nums[0] < nums[" << n << "]";
        printf("nums[0], or %.2f is the smallest number", nums[0]);
        }
    else if (nums[1] < nums[0] && nums[1] < nums[2] && nums[1] < nums[3] && nums[1] < nums[4]) {
        printf("nums[1], or %.2f is the smallest number", nums[1]);
        }
    else if (nums[2] < nums[0] && nums[2] < nums[1] && nums[2] < nums[3] && nums[2] < nums[4]) {
        printf("nums[2], or %.2f is the smallest number", nums[2]);
    }
    else if (nums[3] < nums[0] && nums[3] < nums[1] && nums[3] < nums[2] && nums[3] < nums[4]) {
        printf("nums[3], or %.2f is the smallest number", nums[3]);
    }
    else if (nums[4] < nums[0] && nums[4] < nums[1] && nums[4] < nums[3] && nums[4] < nums[4]) {
        printf("nums[2], or %.2f is the smallest number", nums[2]);
    }
    else {
        cout << "DEBUG: there is not smallest number.\n";
    }
}