/*
HW 6 String
Brendan Womer
4/13/2023

Find duplicate characters in a single input, no white space string ranging in size of 1 - 250, and remove them.

1 Write programmer info and briefly describe the program as comments.
2 Write algorithm steps as comments (10 points).
3 Using function(s) design your solution in such a way that it can be tested independently using unit testing with assert statements (40 points).
4 Write a test function that automatically tests (using assert statements)  for at least three different input values other than the ones provided by the problem (20 points).
5 Call the test function in main and execute it when a “test” argument is provided to your program or main(). (10 points)
6 Create and use a Makefile to test kattis sample input files as well as your unit testing (10 points).

*/

#include <iostream>
#include <string>

using namespace std;

void searchname(string);
int dupelength(string, int&, int&);
string removedupe(string, int&, int&);
void printname(string);
int findlength(string);

int main(int argc, char* argv[] ) {
    string name;
 
    cin >> name;

    searchname(name);
    // dupelength(name, cindex, dupelen);
    // removedupe(name, cindex, dupelen);
    // printname(name);



    return 0;
}

void searchname(string name) {
    //current index - this holds the value of index being searched. 
    int cindex = 0;

    //the length of the series of duplicate letters found. local scope only
    int dupelen;



    //begin scanning the name going through each individual element starting from 0.
    for (int i = 0; i <= name.length(); i++) {
        //conditional looking for duplicate letters. by comparing the current index to the following index.

        if (name.at(i+1) != string::npos && name[i+1] == name[i] ) {
            //saves the current position of the index to be used as an argument.
            cout << "found something" << endl;
            cindex = i;


            cout << "DEBUG: cindex = " << cindex << endl;
            //find how many duplicate letters there are
            dupelen = dupelength(name, cindex);
            removedupe(name, cindex, dupelen);
        }
    }
}

//starting from the current index, will find the length of the series of duplicate letters.
int dupelength(string name, int &cindex) {
    //the length of the series of duplicate letters found.
    int dupelen;

    //position of the final duplicate letter found.
    int dupeendi;

    cout << "welcome to dupe length" << endl;
    //starting from the current index, continue iterating through the elements until a new character is found,
    //then declare the position of the final duplicate.
    for (int i = cindex; i <= name.length(); i++) {
        if (name.at(i+1) != string::npos && name[i] != name[i+1]){
        dupeendi = i;

        cout << "DEBUG: dupeendi = " << dupeendi << "   i = " << i << endl; 
        break;
        }

    }

    //will find the difference between the current index and dupeend index AKA.. the dupe length.
    dupelen = (dupeendi - cindex);
    cout << "dupelen: " << dupelen << endl;

    cin.clear();
    cin.ignore(1000, '\n');

}

void removedupe(string &name,int &cindex, int dupelen) {
    

}
