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
#include <vector>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <array>

using namespace std;

/*
Input file
Johnny Lang 100 100 100 98
Suzie Wang 95 85 75 80
Allie Smith 85 85 80 82 
George Michael 0 100 100 0 
Henry Miller 75 85 82 90
Billie Jeans 100 92 83 85
Hillary Clinton 90 91 93 95
Sally Railey 65 70 75 78
Tom Jerry 85 90 97 98
Bill Kool 65 75 65 66
Alice Wood 44 75 88 99

*/

using namespace std;


struct Student {
    string fname;
    string lname;
    string scores[4];
    int average;
    int *next;
};

//-----Fcn prototypes
//fcns used to prompt user
string promptsourcefile();
string promptdestfile();

//find the number of lines in the files
void findlength(ifstream&, int&);

//will be the parent fcn
void copyfile(Student*, int&, string&);
    //one line at time, copy to stringstream, then copy to heap that is created for each struct.
    void copytobuffer(ifstream&, Student*, int&);
//write to the output file
void writetofile();
//find averages
int calcaveragetestscore(string*, int&);
//iomanip to create a table
void formattable();


void debugprintstruct(Student*, int&);



int main(int argc, char* argv[]) {
    int length=0;
    string sourcefile, destfile;
    ifstream fin;
    ofstream fout;

    sourcefile = "classdata.csv";
    // sourcefile = promptsourcefile();
    // destfile = promptdestfile();

    fin.open(sourcefile);
        findlength(fin, length);
        Student *students = new Student[length];
        copyfile(students, length, sourcefile);
        copytobuffer(fin, students, length);
    fin.close();


    debugprintstruct(students, length);
    cout << "outside of everything" << endl;
    

    delete[] students;
    return 0;
}

//prompt user for file we are copying from
string promptsourcefile() {
    string filesource;
    cout << "enter a source file: ";
    cin >> filesource;
    return filesource;
}    

//prompt user for file that we are copying to
string promptdestfile() {
    string destfile;
    cout << "enter file destination: ";
    cin >> destfile;
    return destfile;
}

void debugprintstruct(Student* student, int& length) {
    for (int i = 0; i < length; i++) {
        cout << "current line: " << student[i].fname << " " << student[i].lname << " " << student[i].scores[0] << " " << student[i].scores[1] 
            << " " << student[i].scores[2]  << " " << student[i].scores[3] << endl;
    }
}

//copy each line to a buffer that will temp store the data
void copyfile(Student* students, int &length, string &sourcefile) {
    // ifstream fin;
    // fin.open(sourcefile);

    // findlength(fin, length);
    // copytobuffer(fin, students, length);

    // fin.close();
}

void findlength(ifstream& fin, int& length) {
    string tmp;
    while (!fin.eof() && getline(fin, tmp)) {
        length ++;
    }
    fin.seekg(0);
}

//will copy the file to structs-- which have their own heap.
void copytobuffer(ifstream& fin, Student* student, int& length) {
    int linecounter=0;
    string currentline;
    while (!fin.eof()){
        while (getline(fin, currentline)) {
            stringstream ss(currentline);
            cout << currentline << endl;
            // debugprintstruct(student, length);

            //The order is fixed so input into struct in the given order.
            ss >> student[linecounter].fname;
            ss >> student[linecounter].lname;
            ss >> student[linecounter].scores[0];
            ss >> student[linecounter].scores[1];
            ss >> student[linecounter].scores[2];
            ss >> student[linecounter].scores[3];

            linecounter ++;
        }
    }
}

//write buffer the output file
void writetofile() {


}

//find averages of test score
int calcavgtestscore(Student* student) {
        int tmpavg, elementvalue;
        string tmpscores[4];
        for (int currstudent = 0; currstudent < 4; currstudent ++){
            //copy all values for the current line to a temp placeholder array
            for (int j = 0; j < 5; j++) {
                tmpscores[j] = student[currstudent].scores[j];
            }
            // int numberoftests = (tmpscores.end() - tmpscores->begin());
            for (int scoreidx = 0; scoreidx < 4; scoreidx++) {
                elementvalue = stoi(tmpscores[scoreidx]);
                tmpavg = tmpavg + elementvalue;
            }
        }
        tmpavg = tmpavg/4;
        return tmpavg;
}

//using iomanip to format the data to a table
void formattable() {


}


