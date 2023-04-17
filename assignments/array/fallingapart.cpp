/*
HW 7 - Arrays
Brendan Womer
4/16/2023

Alice and Bob take turns picking the largest values from an n sized array and output the sum of their values.

Steps:
1) user inputs the size of the array, n, 1 <= n <= 15
2) user inputs the values for each element of the array.
3) The two "players", "alice" and "bob", take turns picking numbers.
    a) because they are playing optimally, they will pick largest number
        -- an array sorted from greatest to least will satisfy this.
4) calculate the sum of each "player's" score after there are no more elements left.
5) output is a single line, the sum of Alice's and Bob's selections.
6) ????
7) profit.

fcns:
main
sort
calcscores

var:
arrsize
alicescore
bobscore

*/  

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

void sortArr(int&, int);



int main(int argc, char* argv[]) {
    //declare value array size, bob's score, Alice's score.
    int sizen, bobscore, alicescore;


    //arraysize input, kattis will only prompt 1-15
    cin >> sizen;
    cin.clear(); //for funsies

    //declare the array sized n that represents the fragmented big int from problem.
    int intsplit[sizen];

    //input for elements of intsplit array
    cin >> intsplit;

    //sort the array in descending order.
    sortArr(intsplit, sizen);
    



}


void sortArr(int &intsplit[], int sizen) {
    int tmpnum; //placeholder number
    for (int i = 0; i > sizen; i++) {
        //if arr[i] < arr[i+1] then swap the values.
        //will loop from the beginning until arr[] is in order
        if (intsplit[i] < intsplit[i+1]) {
            tmpnum = intsplit[i]; //store in tmpnum
            intsplit[i] = intsplit[i+1]; //over
            intsplit[i+1] = tmpnum;
            i = 0; //reset the loop
            for (j = 0; j >= sizen; j++) {
                cout << "intsplit[" << i << "] : " << intsplit[i] << endl;
            }
        }
    }

}





void userinputs(int &intsplit[], int &sizen) {
    //user iu


        for (i = 0; i < sizen; i++) {
            intsplit[i] = 
    }

}