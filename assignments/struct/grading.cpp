/*
HW - 8 - Structs
Brendan Womer

1. Your program will prompt the user for input file name to read the data from.
2. Your program will read an arbitrary number of student records into an array/vector.
3. Your program will prompt the user for the output file to write the output report to.
4. Write function(s) to find students’ average test scores and the corresponding letter grade using the following criteria: 
        A (90% and above) 
        B (80% - 89%) 
        C (70% - 79%) 
        D (60% - 69%) 
        F (59% and less) 
    and write the values to the output text file using the tabular format as shown in the provided sample file called cs112.out.
5.Write a function and use it to sort the array of students' records in descending order based on average test score. You can write your own bubble sort function or use the <algorithm> library’s sort function.

classdata.csv format -> fname lname Test1 Test2 Test3 Test4

*/

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

struct Student {
    string fname;
    string lname;
    int testscore1;
    int testscore2;
    int testscore3;
    int testscore4;
    int average;
    char grade;

};


ifstream classin.open("classdata.csv");


//open, define size, and lines
void examinefile();
    void getfilelines();
    void getsize();

//create a  struct for each student and save to a buffer
//  -each line is a student so it will iterate through each line
void copyfile();
    

//write to the output file
void writetofile();

//find averages
void calcavgtestscore();




int main(int argc, char* argv[]) {
    



    classin.close();
    return 0;
}