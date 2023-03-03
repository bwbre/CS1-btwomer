/*
Functions Lab
Updated By: Brendan Womer
CSCI 111
Date: 03/02/2023

Program prompts the user to enter two points in the form (x1, y1) and (x2, y2) and finds the distance between the two points using a function.
Algorithm steps:
   1. Define a function called findDistance(…) that takes four parameters x1, y1 and x2, y2 as two points
       a. finds the distance between them using the equation: √((x2-x1)^2 + (y2-y1)^2)
       b. returns the calculated distance value
   2. Prompt user to enter two points in (x, y) format
   3. Store them into 4 individual variables
   4. Call function getDistance by passing 4 entered numbers as arguments
   5. Display results with proper description. Format output numbers to 2 decimal points.
   6. Test and validate that program output is correct for a given set of input points.
   7. BONUS - (10 points) Using a loop repeat step 2-6 until the user wants to quit.
*/

#include <iostream>
#include <cstdio>
#include <cassert>
#include <cmath>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const float epsilon = 1e-5; // 0.00001 accuracy upto 5 decimal points; error of margin

// function prototypes

// Function that calculates the distance between two points
// x1, y1 and x2, y2 and returns the calculated value
double findDistance(float, float, float, float);

// test function that runs automated testing
void test();



// function clears the screen system call
// NOTE: system call is not a security best pracice!
void clearScreen() {
    // use "cls" in windows and "clear" command in Mac and Linux
    #ifdef _WIN32
        system("clS");
    #else
        system("clear");
    #endif
}

int main()
{
    int x1, y1, x2, y2; // variables to store two points (x1, y1) and (x2, y2)
    char ch;
    // using pointers for funsies.
    string *promptend;

    //FIXME-bonus - 10 bonus points - add loop until user wants to quit                              ----*fixed-----
    // the loop will execute the following block of code

    clearScreen();
    cout << "Program calculates distance between 2 points on a 2D coordinate." << endl;

    while (*promptend != string("n") && *promptend != string("N")) 
    {

        cout << "\nEnter a point in the form (x, y): ";
        // parse the input stream
        cin >> ch >> x1 >> ch >> y1 >> ch; // value stored in ch is ignored
        printf("(x1, y1) = (%d, %d)\n", x1, y1);


        //FIXME3 - Read/parse the second point and store data into variables x2 and y2              ---*fixed*---
        cout << "Enter a second point in the form (x, y): ";
        cin >> ch >> x2 >> ch >> y2 >> ch;
        printf("(x2, y2) = (%d, %d)\n", x1, x2);


        //FIXME4 - Call test function                                                               ----*fixed*-----
        test();

        //FIXME5 - call findDistance function passing proper arguments                                ----*FIXED*----
        double distance;
        distance = findDistance(x1, y1, x2, y2);


        //FIXME6 – Using printf function display the returned distance with proper description        ----*FIXED*----
        
        printf("The distance between the two sets of points is: %.2lf \n", distance);

        //prompt if user wants to loop
        cout << "Would you like to calculate another set of points? enter 'Y' for yes: ";

        string prompt;
        cin >> prompt;
        *promptend = prompt;

    } 


    cin.ignore(1000, '\n');
    cout << "Press enter to quit the program: ";
    cin.get();
    cout << "Good bye..." << endl;
    return 0;
}

double findDistance(float x1, float y1, float x2, float y2)
{
    // FIXME7 - Find the distance between (x1, y1) and (x2, y2)                                     ------*FIXED*------
    double distance = (sqrt(((y2-y1)*(y2-y1))+(((x2-x1)*(x2-x1)))));        
    return distance;
}

// test function that test findDistance function with 3 test cases
void test() 
{
    float result; 
    float expected; 

    //test case 1
    result = findDistance(4, 3, 5, 1);
    expected = 2.236067f; 
    assert( fabs(result - expected) <= epsilon); //accept the result if it's less than the error of margin

    //test case 2
    result = findDistance(3, 4, 5, 6);
    expected = 2.8284271247462;
    assert( fabs(result - expected) <= epsilon); //accept the result if it's less than the error of margin

    //test case 3
    result = findDistance(7, 8, 10, 11);
    expected = 4.2426406871193;
    assert( fabs(result - expected) <= epsilon); //accept the result if it's less than the error of margin

    // FIXME8 - add at least two more test cases                                            -------*FIXED*-------

    cerr << "all tests passed..." << endl;
}

