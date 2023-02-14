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
    return rectSide;

}

int calcArea(int s1, int s2) {
    int area;
    area = s1 * s2;
    return area;
}

int calcPerim(int s1, int s2) {
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
    int side1, side2;
    string name;
    //prompt name
    name = promptName();
    //greet name
    greetperson(name);

    //input for sides
    side1 = promptSides();
    side2 = promptSides();
    cout << "debug: " << side1 << endl;
    cout << "Debug: " << side2 << endl;

    //calc area
    int rectangleArea = calcArea(side1, side2);

    //calc perim
    int rectanglePerim = calcPerim(side1, side2);

    //test
    cout << "area: " << rectangleArea << endl;
    cout << "perim: " << rectanglePerim << endl;

    printValue(rectangleArea, rectanglePerim, side1, side2);


    return 0;
}

