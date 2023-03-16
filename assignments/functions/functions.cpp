/*
Brendan Womer
CS1 - HW3 Functions

1.Define a function that takes two numbers, adds two numbers and returns the sum. The function must be 
2.Define a function that takes two numbers, multiplies the two numbers and returns the product. 
3.Define a function that takes two numbers; divides the first number by the second and returns the quotient. 
4.Define a function that takes two numbers, subtracts the second from the first and returns the difference. 
5.Define a function that takes two numbers, finds and returns the remainder of the first number divided by the second. 
6.Define a function that takes two numbers, finds the first to the power of the second number and returns the result. 
7.Define a function that takes a number and returns the square-root of the number.
8.Prompt the user to enter two numbers
9.Call all the functions passing those two entered numbers and print the calculated results with proper descriptions
10.Write a test function to automatically test each function with at least two different test cases.
*/

#include <iomanip>
#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;



//Template promptuser() and a long series of templated fcns to calculate
void promptuser(float&, float&);
void testfcn();

//calculate sum
template <class T>   
    T calcsum(T n2, T n1) {
        return n2 + n1;
}

//calculate the multiplication
template <class T> 
    T calcmu(T n1, T n2) {
        return (n1 * n2);
}

//calculate division
template <class T> 
    T calcdivision(T n1, T n2) {
        return (n1 / n2);
}

//calculate the difference between n2 and n1
template <class T> 
    T calcdifference(T n1, T n2) {
        return (n2 - n1);
}

//calculate the remainder of n1 divided by n2
template <class T> 
    T calcremainder(T n1, T n2) {
        int remainder;
        remainder = ((n1) % (n2));
        return remainder;
}

//calulate n1 to the power of n2
template <class T, class T2> 
    T calcpower1to2(T n1, T2 n2){
        return pow(n1, n2);
}

//calculate the square root of n1
template <class T> 
    T calcsqrt(T n1) {

        //note: a real square root only exists if the value is equal to or greater than 0
        //here we test to see if n1 meets this criteria
        if (n1 >= 0) {
            return sqrt(n1);
        }
        else {
            return bool(0);
        }

}

//templated fcn to call all the other calculation functions
template <class T>
T callemall(T n1,T n2) {
    cout << n1 << " + " << n2 << " = " << calcsum<float>(n1, n2) << endl;
    cout << n1 << " * " << n2 << " = " << calcmu<float>(n1, n2) << endl;
    cout << n1 << " / " << n2 << " = " << calcdivision<float>(n1, n2) << endl;
    cout << n1 << " - " << n2 << " = " << calcdifference<float>(n2, n1) << endl;
    cout << n1 << " % " << n2 << " = " << calcremainder<int>(n1, n2) << endl;
    cout << n1 << " to the power of " << n2 << " = " << calcpower1to2<float>(n1, n2) << endl;
    cout << n2 << " to the power of " << n1 << " = " << calcpower1to2<float>(n2, n1) << endl;

    //there are two potential outputs for this fcn. If it doesn't exist it will print out that it doesnt exist.
    if ( calcsqrt<float>(n1) != bool(0)) {
        cout << "the square root of n1: " << calcsqrt<float>(n1) << endl;
    }
    else {
        cout << "the square root of n1: Does not exist. \n";
    }

    //do it again for n2
    if ( calcsqrt<float>(n2) != bool(0)) {
        cout << "the square root of n2: " << calcsqrt<float>(n2) << endl;
    }
    else {
        cout << "the square root of n2: Does not exist. \n";
    }

    return 0;
}



int main(int argc,char *argv[]) {
    //n1 and n2 will be the two numbers that the user inputed
    float n1, n2;

    //ptrn1 and ptrn2 will the pointers that point to n1 and n2, respectively.
    float *ptrn1, *ptrn2;

    //set pointers 1 and 2 to the memory address of n1 and n2
    ptrn1 = &n1;
    ptrn2 = &n2;

    //call fnc to promptuser for n1, n2 and print it out 
    promptuser(*ptrn1, *ptrn2);

    //test function that will check all of the calc functions against a known value in relation to known inputs
    testfcn();

    //fcn to call all calculations with the ptr for n1 and n2 -- which is assug
    callemall<float>(*ptrn1, *ptrn2);


    //nothing exploded and this is the end.
    printf("\nthe end\n\n");
    return 0;
}


void promptuser(float &ptrn1,float &ptrn2) { 
    //variable to temporarily hold the floats from the stream.
    float tn1, tn2;

    //prompt user to input 2 numbers that will be used as n1 and n2
    cout << "enter two numbers separated by a spaces: ";
    cin >> tn1 >> tn2; 
    cout << '\n';

    //assign the pointers found in main to these values so that it may be used throughout the scope of main.
    ptrn1 = tn1;
    ptrn2 = tn2;
}

void testfcn() {

    //create result variable that will be the expected result of the calc functions that are called.
    float result;

    // num1 + num2
    result = calcsum<float>(1,2);
    assert(result == 3);
    result = calcsum<float>(1,5);
    assert(result == 6);

    result = calcmu<float>(2, 4);
    assert(result == 8);
    result = calcmu<float>(5.5, 2);
    assert(result == 11);

    // n1/n2
    result = calcdivision<float>(16, 2);
    assert(result == 8);
    result = calcdivision<float>(22, 2);
    assert(result == 11);

    //n2 - n1
    result = calcdifference<float>(10, 5);
    assert(result == (-5));
    result = calcdifference<float>(2, 5);
    assert(result == (3));

    // n1 & n2
    result = calcremainder<int>(25, 7);
    assert(result == 4);
    result = calcremainder<int>(11, 8);
    assert(result == 3);

    //(n1)^n2
    result = calcpower1to2<float, int>(2, 3);
    assert(result == 8);
    result = calcpower1to2<float, int>(1, 5);
    assert(result == 1);

    //sqrt of n1
    result = calcsqrt<float>(100);
    assert(result == (10));
    result = calcsqrt<float>(9);
    assert(result == (3));
}