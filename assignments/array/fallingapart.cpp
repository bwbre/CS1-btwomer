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
5) output in a single line, the sum of Alice's and Bob's selections.
6) ????
7) profit.
*/  

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

void sortArr(int*, int);
void getnums(int*, int);
void printstuff(int*, int);
void calcscore(int*, int, int&, int&);



int main(int argc, char* argv[]) {
    //declare value array size, bob's score, Alice's score.
    int sizen;
    int bobscore = 0;
    int alicescore = 0;


    //arraysize input, kattis will only prompt 1-15
    cin >> sizen;
    cin.clear(); //for funsies

    //declare the array sized n that represents the fragmented big int from problem.
    int intsplit[sizen];

    //input for elements of intsplit array
    getnums(intsplit, sizen);

    //sort the array in descending order.
    sortArr(intsplit, sizen);
    // printstuff(intsplit, sizen);
    calcscore(intsplit, sizen, alicescore, bobscore);

    return 0;
}

void sortArr(int intsplit[], int sizen) {
    int tmpnum;
    for (int i = 0; i < sizen; i++) {
        //if arr[i] < arr[i+1] then swap the values.
        //will loop from the beginning until arr[] is in order
        if (intsplit[i] < intsplit[i+1] && intsplit[i+1] < 101) {
            tmpnum = intsplit[i]; //store in tmpnum
            intsplit[i] = intsplit[i+1]; //over
            intsplit[i+1] = tmpnum;
            i=-1;
        }
    }
}

void getnums(int intsplit[], int sizen) {
    //will loop until all n number elements of intsplit[] are filled.
    for (int i = 0; i < sizen; i++) {
        int tmpnum;
        cin >> tmpnum;
        intsplit[i] = tmpnum;
    }
}

void printstuff(int intsplit[], int sizen) {
    //debug stuff
    for (int i = 0; i < sizen; i++) {
        cout << "-intsplit[" << i << "] : " << intsplit[i] << endl;
    }
}

void calcscore(int intsplit[], int sizen, int &alicescore, int &bobscore) {
    //if i in array[i] is odd or == 0, then it's alice's turn
    for (int i = 0; i < sizen; i++) {
        if (i%2 != 0) {
            bobscore = (bobscore + intsplit[i]);
        }
        else {
            alicescore = (alicescore + intsplit[i]);
        }
    }
    cout << alicescore << " " << bobscore;


}