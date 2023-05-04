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



#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <fstream>

using namespace std;


struct Student {
    string fname;
    string lname;
    string scores[4];
    int average;
    int *next;
};

struct Files {
    string inputfile;
    string outputfile;
    int inlength;
};

//Fcn prototypes

//fcns used to prompt user
string promptsourcefile();
string promptdestfile();
//open, define size, and lines
void examinefile();
    int getlen();
//create a  struct for each student 
// and save to a buffer
void createstruct();
//  -each line is a student so it will iterate through each line
void copyfile();
    void readdata();
//write to the output file
void writetofile();
//find averages
int calcaveragetestscore(string*, int&);
//iomanip to create a table
void formattable();


void debugprintstruct(Student*);



int main(int argc, char* argv[]) {
    int length, linecounter;
    string currentline, sourcefile, destfile;
    vector<string> classroster;
    
    sourcefile = "input.csv";
    // sourcefile = promptsourcefile();

    // destfile = promptdestfile();

    ifstream fin;
    fin.open(sourcefile);

    length = fin.eof();
    Student *student = new Student[4];
    while (getline(fin, currentline)) {
        stringstream ss(currentline);
        // ss >> student->fname >> student->lname >> student->testscore1 >> student->testscore2 
        //    >> student->testscore3  >> student->testscore4;
        ss >> student[linecounter].fname >> student[linecounter].lname >> student[linecounter].scores[0] 
            >> student[linecounter].scores[1] >> student[linecounter].scores[2] >> student[linecounter].scores[3];
        linecounter ++;
    }

    fin.seekg(0);

    debugprintstruct(student);
    
    
    fin.close();
    delete student;
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

void debugprintstruct(Student* student) {
    int linecounter = 0;
    for (int i = 0; i < 4; i++) {
        linecounter++;
        // student->scores[i] = tempscorearr[i];
        cout << "student->score[" << i << "]: " << student->scores[i] << endl;
        cout << "current line: " << student[i].fname << " " << student[i].lname << " " << student[i].scores[0] << " " << student[i].scores[1] 
            << " " << student[i].scores[2]  << " " << student[i].scores[3] << endl;
    }
}

//will gather information from file.
//uses the getlen fcn.
void examinefile() {


}

//used to find len of file
int getlen() {

    return 0;
    }

//create a struct and save to their own heap
void createstruct(vector<string> classroster) {
    

}

//delete all the struct's heaps
void deletestruct() {


}

//copy each line to a buffer that will temp store the data
void copyfile() {


}

//will read data and 
void readdata() {


}

//write buffer the output file
void writetofile() {


}

//find averages of test score
int calcavgtestscore(Student& student, int& linenumber) {
        int tmpavg, elementvalue;
        while (linenumber < 4; linenumber++){
            for (int j = 0; j < 5; i++) {
                int tmpscores[j] = student[linenumber].scores[j];
            }
            int numberoftests = tmpscores.length();
            for (int i = 0; i < numberoftests-1; i++) {
                elementvalue = int(tmpscores[i]);
                tmpavg = tmpavg + elementvalue;
            }
        }
        tmpavg = tmpavg/4;
        return tmpavg;
}

//using iomanip to format the data to a table
void formattable() {


}


