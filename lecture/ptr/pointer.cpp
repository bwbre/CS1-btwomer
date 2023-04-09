/*

*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;
void addnum(bool&);

int main(int argc, char* argv[]) {
    //keeprunning baby
    bool keeprunning;
    keeprunning = true;

    while (keeprunning == true) {
    cout << keeprunning << " " << &keeprunning << endl;
    addnum(keeprunning);
    cout << keeprunning << " " << &keeprunning << endl;
    }

    cout << "\n The end" << endl;
    return 0;
}


void addnum(bool &a) { 
    cout << "\nEnter 1 or 0: ";
    cin >> a;

}





























// int addnums(int*, int*);

// //can use & AND *
// void swapnums(int*&, int*&);

// int main(int argc, char* argv[]) {
//     int n1, n2;
//     int *ptr1, *ptr2;

//     n1 = 24;
//     n2 = 10;

//     ptr1 = &n1;
//     ptr2 = &n2;

//     cout << "Please enter two numbers separated by a space: ";
//     cin >> *ptr1 >> *ptr2;

//     cout << "n1: " << n1 << " n2: " << n2 << endl;
//     swapnums(n1, n2);
//     cout << "n1: " << n2 << " n2: " << n2 << endl;

//     result = addnums(ptr1, ptr2);
//     // cout << n1 << " + " << n2 << " = " << result << endl;

//     return 0;
// }

// int addnums(int *num1, int *num2) {
//     return *num1 + *num2;

// }

// /*swap the ptr value / memory address using a variable to temporarily hold the value.
// if you dont pass the memory address along with value it will create a new memory address. by using int*& you pass both the memory address AND the value. 
// */
// void swapnums(int*& num1, int*& num2) {
//     //
//     int *tempnum;
//     tempnum = num1;
//     num1 = num2;
//     num2 = tempnum;

// }

// int largernum(int* num1, int* num2) {
//     //note the return isnt a pointer, its the value that will be passed.
//     if (*num1 > *num2) {
//         return num1;
//     } else {
//         return num2;
//     }

//     //use return NULL as a temporary return value when the actual value isnt ready. ALWAYS CREATE RETURN BEFORE FILLING OUT FUNCTION.
//     return NULL;

// }