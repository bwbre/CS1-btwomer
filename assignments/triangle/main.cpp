/*
    Hw 3: Triangles   
    Updated By: Brendan Womer
    Date: 03/27/2023
    

    notes: Will prompt the user for the length of three sides of a triangle, then will calculate and output the area and 
    perimeter-- each with their own function.

*/

//any include's and namespaces used
#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

//template fcns
float calcarea(float, float, float, float);
float calcperim(float, float, float);


//main fcn
int main() {
    float side1, side2, side3, area, perim;

    //prompt user for 3 values of the sides of the triangle and store the inputs to side1 - 3.
    cout << "please enter three sides of a triangle: ";
    cin >> side1 >> side2 >> side3;

    /*call the function that calculates the perimeter of the triangle.
     *this must be done first since the perimeter is used in calculating the area* */
    perim = calcperim(side1, side2, side3);
    cout << "Perimeter of triangle is: " << perim << endl;

    /*call the function that calculates the area of the triangle *note: it uses the output from calcperim() 
    as an argument since its used in the function* */
    area = calcarea(side1, side2, side3, perim);
    cout << "Area of triangle is: " << area << endl;

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