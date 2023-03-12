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

#include <iostream>
#include <cmath>

using namespace std;

template <class T1>




int main() {
    float *n1, *n2;
    float n1 = *n1;
    float *sum, *multiplication, *division, *difference, *remainder, *pw1to2, *sqrt;


    promptuser<float, float>(n1,n2);
    callemall<float*, float*>(n2,n2);

}



// void promptuser(float *n1, float *n2) { 
//     //variable to temporarily hold the floats from the stream.
//     float tn1, tn2;
//     cout << "enter two numbers separated by spaces: ";
//     cin >> tn1 >> tn2;
//     *n1 = tn1;
//     *n2 = tn2;
//}

void callemall(float *n1,float *n2) {
    //void fcn to call all the other functions
    cout << "n1 + n2 = " << calcsum<float>(*n1, *n2) << endl;
    cout << "n1 * n2 = " << calcm<float>(*n1, *n2) << endl;
    cout << "n1 / n2 = " << calcdivision<float>(*n1, *n2) << endl;
    cout << "n2 - n1 = " << calcdifference<float>(*n1, *n2) << endl;
    cout << "n1 remainder n2: " << calcremainder<float>(*n1, *n2) << endl;
    cout << "n1 to the power of n2: " << calcpower1to2<float>(*n1, *n2) << endl;
    cout << "the square root of n1: " << calcsqrt<float>(*n1) << endl;

}



//below are un templated fcns

// float calcsum(float* n1, float* n2) {
//     return *n2 + *n1;
// }
// float calcmultiplication(float *n1, float *n2) {
//     return (float(*n1 * *n2));
// }
// float calcdivision(float* n1, float* n2) {
//     return (*n1 / *n2) ;
// }
// float calcdifference(float* n1, float* n2){
//     return (*n2 - *n1);
// }
// float calcremainder(float *n1, float* n2){
//     return (*n1 % *n2);
// }
// float calcpower1to2(float* n1, float* n2){
//     return pow(*n1, *n2);
// }
// float calcsqrt(float* n1){
//     return sqrt(*n1);
// }


T1 calcsum(T1 *n2, T1 *n1) {
    return *n2 + *n1;
}

T1 calcmu(T1 *n1, T1 *n2) {
    return (float(*n1 * *n2));
}

T1 calcdivision(T1 *n1, T1 *n2) {
    return (*n1 / *n2);
}

T1 calcdifference(T1 *n2, T1 *n1) {
    return (*n2 - *n1);
}

T1 calcremainder(T1 *n1, T1 *n2) {
    return (*n1 % *n2);
}

T1 calcpower1to2(T1 *n1, T1 *n2){
    return pow(*n1, *n2);
}

T1 calcsqrt(T1 *n1) {
    return sqrt(*n1);
}

void callemall(T1, T1) {
    //variable to temporarily hold the floats from the stream.
    float tn1, tn2;
    cout << "enter two numbers separated by spaces: ";
    cin >> tn1 >> tn2;
    *n1 = tn1;
    *n2 = tn2;

}



//Template class wall copy

// template <class T1> 
// T1 calcsum(T1 *n2, T1 *n1) {
//     return *n2 + *n1;
// }

// template <class T1> 
// T1 calcmu(T1 *n1, T1 *n2) {
//     return (float(*n1 * *n2));
// }

// template <class T1> 
// T1 calcdivision(T1 *n1, T1 *n2) {
//     return (*n1 / *n2);
// }

// template <class T1> 
// T1 calcdifference(T1 *n2, T1 *n1) {
//     return (*n2 - *n1);
// }

// template <class T1> 
// T1 calcremainder(T1 *n1, T1 *n2) {
//     return (*n1 % *n2);
// }

// template <class T1> 
// T1 calcpower1to2(T1 *n1, T1 *n2){
//     return pow(*n1, *n2);
// }

// template <class T1> 
// T1 calcsqrt(T1 *n1) {
//     return sqrt(*n1);
// }

// template <class T1> 
// void callemall(T1 n1, T1 n2) {
//     //variable to temporarily hold the floats from the stream.
//     float tn1, tn2;
//     cout << "enter two numbers separated by spaces: ";
//     cin >> tn1 >> tn2;
//     *n1 = tn1;
//     *n2 = tn2;

// }
// template <class T1> 
// void promptuser(T1, T1);