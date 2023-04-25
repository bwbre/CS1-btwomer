/*

*/


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main (int argc, char *argv[]) {
    int nums[];
    int linecounter 0;
    ifstream fin; //file input
    ofstream fout; //file output
    
    /*../files/input.txt is valid.
    c:\user\...\files\input.txt is an example of a global address
    ALWAYS USED AS PASS BY REFERENCE*/
    fin.open("files/input.txt");
    fout.open("files/output.txt"); //will create a txt file if it doesn't exist.

    //iterating through a whole file.
    //while (!fin.eof()){
    //     if (fin >> nums[linecounter]) {
    //     linecounter++;
    //     }
    // }

    //Iterating through every line of a file- including blank spaces because get line gets spaces too.

    
    // fin >> num1 >> num2 >> num3 >> num4 >> num5;
    // fout << num1 << num2 << num3 << num4 << num5;

    fin.close();

    return 0;
}

int readdata(ifstream &nums, int nums, int linecounter ) {
        while (!fin.eof()){
        getline(fin, nums[linecounter]);
        linecounter++;
    }
}