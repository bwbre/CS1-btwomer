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
void calcarea();
void calcperim();
int promptside();


//main fcn
void main() {
    int side1, side2, side3;
    int sidetotal;

    promptside(side1, side2, side3);


    return 0;

}

void promptside(double side1, double side2, double side3) {
    cout << "Please input 3 sides of a given triangle: ";
    getline(cin, side1, side2, side3);
    cout << endl << "you inputted: \n" << "Side 1: " << side1 << endl << "Side 2: " << side2 << endl << "side 3: " << side3 << endl;
}