/*
brendan woemr
rectangle 

step 1: prompt for name
step 2: greet name
step 3: prompt for sides
step 4: calc area
step 5: calc perim
step 6: print area and perim

*/

#include <iostream>
#include <string>
#include <stdlib>
using namespace std;

string promptName() {
    string name1;
    cout << "wassup whats your name? ";
    getline(cin, name1);

    return name1;
}

void greetperson(string name1) {
    cout << "welcome " << name1 << " to my rectangle calculator." << endl;
}

int promptSides() {
    int rectSide;
    cout << "Please enter one side of the rectangle: ";
    cin >> rectSide;
    sqrt():
    return rectSide;

}

// float calcArea(float s1, float s2) {
//     cout << "debug inside area()" << endl;
//     float area;
//     area = s1 * s2;
//     return area;
// }

float calcArea(float s1, float s2) {
    cout << "debug stringinside area()" << endl;
    float area;
    area = atof(s1.c_str()) * atof(s2.c_str());
    return area;
}

int calcPerim(int s1, int s2) {
    cout << "debug inside calcperim()" << endl;
    int perim;
    perim = (2*s1) + (2 * s2);
    return perim;
}

void printValue(int area, int perim, int s1, int s2) {
    printf("The rectangle with sides %d and %d\n has an area of %d and a perimeter is %d\n", s1, s2, area, perim);
    /*
    ^same as:
    cout << "rectangle with sides " << s1 << " and " << s2 << endl;
    cout << "Area with sides " << s1 << " and " << s2 << endl;
    */
}


int main() {
    string side1, side2;
    string name;
    side1 = 40.5;
    side2 = 12.3;
    printValue(rectangleArea, rectanglePerim, side1, side2);


    return 0;
}

// int main() {
//     int side1, side2;
//     string name;
//     //prompt name
//     name = promptName();
//     //greet name
//     greetperson(name);

//     //input for sides
//     side1 = promptSides();
//     side2 = promptSides();
//     cout << "debug: " << side1 << endl;
//     cout << "Debug: " << side2 << endl;

//     //calc area
//     int rectangleArea = calcArea(side1, side2);

//     //calc perim
//     int rectanglePerim = calcPerim(side1, side2);

//     //test
//     cout << "area: " << rectangleArea << endl;
//     cout << "perim: " << rectanglePerim << endl;

//     printValue(rectangleArea, rectanglePerim, side1, side2);


//     return 0;
// }




// //int calcArea(int s1, int s2) {
//     int area;
//     area = s1 * s2;
//     return area;
// }