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
    // int testscore1;
    // int testscore2;
    // int testscore3;
    // int testscore4;
    string scores[4];
    // int average = (testscore1 + testscore2 + testscore3 + testscore4)/4;
    // int average = (stoi(scores[0]) + stoi(scores[1]) + stoi(scores[2]) + stoi(scores[3]))/4;
    // int *scores[4] = {&testscore1, &testscore2, &testscore3, &testscore4};

    int *next;

    int calcaveragetestscore(string scores) {
        int average;
        for (int i = 0; i < scores.length(); i++) {
            int elementvalue = int(scores[i]);
            average = average + elementvalue;
        }
        average = average/4;
        return average;
        }

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
int calcaveragetestscore(string*);
//iomanip to create a table
void formattable();


void debugprintstruct(Student*);



int main(int argc, char* argv[]) {
    int length;
    int linecounter = 0;
    string currentline;
    string stuinfo[5];

    string sourcefile, destfile;
    vector<string> classroster;
    

    sourcefile = "input.csv";
    // sourcefile = promptsourcefile();

    // destfile = promptdestfile();

    ifstream fin;
    fin.open(sourcefile);
    length = fin.eof();
            Student *student = new Student;

    string info;
    while (getline(fin, currentline)) {
        int element = 0;
        string tempscorearr[4];
        stringstream ss(currentline);
        // ss >> student->fname >> student->lname >> student->testscore1 >> student->testscore2 
        //    >> student->testscore3  >> student->testscore4;
        ss >> student->fname >> student->lname >> student->scores[0] >> student->scores[1] >> student->scores[2] >> student->scores[3];
        
    }

    debugprintstruct(student);

    // seekg(0, fin);

    // while (!fin.eof) {
    //     while (fin << getline(fin, linecounter)) {
    //         // fin getline
    //     }
    // }

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
    cout << "current line" << student->fname << " " << student->lname << " " << student->scores[0] << " " << student->scores[1] 
        << " " << student->scores[2]  << " " << student->scores[3] << endl;

    for (int i = 0; i < 4; i++) {
            // student->scores[i] = tempscorearr[i];
                cout << "student->score[" << i << "]: " << student->scores[i] << endl;
        }
}