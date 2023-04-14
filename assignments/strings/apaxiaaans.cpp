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

string searchname(string);
int dupelength(string, int, int);
string removedupe(string, int, int);
void printname(string);
int findlength(string);

void printdebug(string, int, int);

int main(int argc, char* argv[] ) {
    string name;
 
    cin >> name;

    name = searchname(name);
    // dupelength(name, cindex, dupelen);
    // removedupe(name, cindex, dupelen);
    printname(name);



    return 0;
}

string searchname(string name) {
    /*current index - this holds the value of the current index being searched.
     When a dupe is found this will act as a placeholder for where the program was scanning--
     so it wont have to start scanning from the beginning */
    int cindex = 0;

    //the length of the series of duplicate letters found. local scope only
    int dupelen;



    //begin scanning the name going through each individual element starting from 0.
    for (int i = 0; i <= name.length(); i++) {
        //conditional looking for duplicate letters. by comparing the current index to the following index.

        if (name[i+1] != string::npos && name[i+1] == name[i] ) {
            //saves the current position of the index to be used as an argument.
            // cout << "found something" << endl;
            cindex = i;

            //find how many duplicate letters there are NOT COUNTING THE CURRENT INDEX. 
            dupelen = dupelength(name, cindex, dupelen);

            // printdebug(name, cindex, dupelen);

            //check to see whether or not there is a dupe
            if (dupelen > 0){
                name = removedupe(name, cindex, dupelen);
            }
        }
    }
    // cout << "wtf " << endl;
    return name;
}

//starting from the current index, will find the length of the series of duplicate letters.
int dupelength(string name, int cindex, int dupelen) {
    //position/index of the final duplicate letter found in char array.
    int dupeendi;

    //starting from the current index, continue iterating through the elements until a new character is found,
    //then declare the position of the final duplicate.
    for (int i = cindex; i < name.length(); i++) {
        if (name[i] != name[i+1]){

        //the index where the duplicate characters end.
        dupeendi = i;
        //the difference between the current index and dupeend index is the dupe length.
        dupelen = (dupeendi - cindex);
        return dupelen;
        }
    }

    //return dupelen of 0 .... there are no more dupes
    return 0;
}

string removedupe(string name,int cindex, int dupelen) {
    //if statement to make sure that
    // if (dupelen > 0) {
        name.erase(cindex+1, dupelen);
    // }

    return name;
}

void printname(string name){
    cout << name;
}
void printdebug(string name, int cindex, int dupelen) {
    cout << "--DEBUG: cindex: " << cindex << "     dupelen: " << dupelen << "   name:" << name << endl;
}