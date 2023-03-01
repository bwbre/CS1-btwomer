/*
created by: Brendan Womer

HW 3: Area and Perimeter of a Triangle
not a moment after 2/27/2023

notes: Will prompti user for three sides, then will calculate and print the output of
the triangles area and perim
*/

//any include's and namespaces used
#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

//template fcns
float calcarea(float, float, float, float);
float calcperim(float, float, float);
float promptside(float, float, float);


//main fcn
int main() {
    float side1, side2, side3, area, perim;

    cout << "please enter three sides of a triangle: ";

    cin >> side1 >> side2 >> side3;

    cout << "this is cout before calc perim in main()-- side1: " << side1 << " side2: " << side2 << " side3: " << side3 << endl;

    cout << "in main(), result of calcperim() is: " << calcperim(side1, side2, side3) << endl;
    perim = calcperim(side1, side2, side3);
    cout << "in main(), result of calcarea() is: " << calcarea(side1, side2, side3, perim) << endl;


    // calcarea(side1, side2, side3, perim);
    return 0;

}

float calcperim(float s1, float s2, float s3) {
    // cout << "\ninside of calc perim" << endl; //works well

    //assigning float perim to the formula of triangle perim, with the sides that were given in main()
    float perim = (.5*(s1+s2+s3));
    // cout << "in calcperim -- calculating.... perim = " << perim << endl; // Works well

    return perim;
}

float calcarea(float s1, float s2, float s3, float p) {
    cout << "\ninside calcarea" << endl;

    float area = sqrt(p*(p-s1)*(p-s2)*(p-s3));

    cout << s1 << s2 << s3 << "area of a triangle with the given sides: ";

    return area;
}

// float promptside(float side1, float side2, float side3) {
//     cout << "Please input 3 sides of a given triangle: ";
//     getline(cin, side1, side2, side3);
//     cout << endl << "you inputted: \n" << "Side 1: " << side1 << endl << "Side 2: " << side2 << endl << "side 3: " << side3 << endl;

//     return side1, side2, side3;
// }