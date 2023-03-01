/*
    Hw 3: Triangles   
    Updated By: Brendan Womer
    Date: 03/27/2023
    
    steps:
    1: Will prompt the user for the length of three sides of a triangle
    2: Call the function to calculate the perimeter, the the function to calculate the area
    3: will out the area and perimeter.
*/

//any include's and namespaces used
#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

//template fcns
float calcarea(float, float, float, float);
float calcperim(float, float, float);
string testtriangle(float, float, float);


//main fcn
int main() {
    float side1, side2, side3, area, perim;

    //prompt user for 3 values of the sides of the triangle and store the inputs to side1 - 3.
    cout << "please enter three sides of a triangle: ";
    cin >> side1 >> side2 >> side3;

    /*call the function that calculates the perimeter of the triangle.
     *this must be done first since the perimeter is used in calculating the area* */
    perim = calcperim(side1, side2, side3);
    cout << "Perimeter of the triangle is: " << perim << endl;

    /*call the function that calculates the area of the triangle *note: it uses the output from calcperim() 
    as an argument since its used in the function* */
    area = calcarea(side1, side2, side3, perim);
    cout << "Area of the triangle is: " << area << endl;

    string result = testtriangle(side1, side2, side3);
    cout << result << endl;

    return 0;
}

float calcperim(float s1, float s2, float s3) {
    //assigning float perim to the formula of triangle perimeter, with the sides acting as parameters that were given in main()
    float perim = (.5*(s1+s2+s3));
    return perim;
}


float calcarea(float s1, float s2, float s3, float p) {
    // create float that will store area and define it using the formula for finding area of a triangle.
    float area; 
    area = sqrt(p*(p-s1)*(p-s2)*(p-s3));

    return area;
}

string testtriangle(float side1, float side2, float side3) {
    string result;
    //Triangle Inequality Theorem says that if two sides of a triangle are greater than the third, the the triangle exists. 
    //using if else statements to test the combinations of sides.
    if (((side1 + side2) > side3) && ((side2 + side3) > side1) && ((side3 + side1) > side2) ) {
        result = "The triangle exists. \n";

        }

        // else if ((side2 + side3) > side1) {
        // cout << "The triangle exists.";
        // }

        // else if ((side3 + side1) > side2) {
        // cout << "The triangle exists.";
        // }

        else {
        result = "The triangle doesn't exists. \n";
    }

    return result;
}