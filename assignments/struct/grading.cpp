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
    float average;
    string lettergrade;
};

struct Class {
    float average;
    int max;
    int min;
    float letterGradeProportions[5];
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
void writetofile(ofstream&, Student*, Class*, int&);
void calclettergrade(Student*, int&);
void calcAverageTestScore(Student*, int&); //find averages for each student and save each student's struct
//find the students letter grade


void calcClassStats(Student*, Class*, int&);
void copyClassDataFromBuffer(Student*, int&, float*, string*);
void calcClassAveragesStats(Student*, Class*, int&);
void calcClassLetterGradesStats(Class*, int&, string*);

//iomanip to create a table
void printtable(Student*, Class*, int&);
void debugprintstruct(Student*, int&);



int main(int argc, char* argv[]) {
    int length=0;
    string sourcefile, destfile;
    ifstream fin;
    ofstream fout;

    // sourcefile = "classdata.csv";
    // destfile = "output.txt";
    sourcefile = promptsourcefile();
    destfile = promptdestfile();

    fin.open(sourcefile);
    Class *currentclass = new Class;
    findlength(fin, length);
    Student *students = new Student[length];
    copytobuffer(fin, students, length);
    fin.close();

    calcAverageTestScore(students, length);
    calclettergrade(students, length);
    calcClassStats(students, currentclass, length);
    printtable(students, currentclass, length);

    fout.open(destfile);
    writetofile(fout, students, currentclass, length);
    fout.close(); 

    delete[] students;
    delete currentclass;
    return 0;
}

//copy data from buffer to be used in calcClassStats() 
//  -which runs the bulk of operations to find and store class statistics.
void copyClassDataFromBuffer(Student* students, int& length, float* averages, string* lettergrades) {
    for (int currstudent = 0; currstudent < length; currstudent++) {
        averages[currstudent] = students[currstudent].average;
        lettergrades[currstudent] = students[currstudent].lettergrade;    }
}

//parent statistics fcn. runs the bulk of operations to find and store class statistics.
void calcClassStats(Student* students, Class* currentclass, int& length) {
    float averages[length]; //array will temporarily hold the averages from each student
    float tmpavg=0;
    string lettergrades[length]; //temp array to hold the letter grades for each student.
    float gradeproportions[5] = {0,0,0,0,0}; //temp arr to hold {% of A, %B, %C, %D, %F}

    copyClassDataFromBuffer(students, length, averages, lettergrades);
    // currentclass->average = 0;
    for (int i = 0; i < length; i++)  {
        tmpavg += averages[i];
    }
    currentclass->average = (tmpavg / float(length)); //the class's overall average
    sort(averages, (averages+(length-1))); //sort the class averages array
    
    currentclass->min = averages[length-1]; //MAX
    currentclass->max = averages[0]; //MIN
    calcClassLetterGradesStats(currentclass, length, lettergrades); //will calc and grab the %proportion for each letter grade
}

//count all the letter grades, calc % proportions, store into class struct
void calcClassLetterGradesStats(Class* currentclass, int& length, string* lettergrades) {
    float tmpavg=0;
    int counter[5] = {0,0,0,0,0}; //{A, B, C, D, F}
    //counts the frequency of each letter grade
    for (int i = 0; i < length; i++) {
        // cout << "\n----lettergrades[" << i << "]: " << lettergrades[i] << endl;
        if (lettergrades[i] == "A") {
            counter[0] ++;
        } else 
        if (lettergrades[i] == "B") {
            counter[1] ++;
        } else 
        if (lettergrades[i] == "C") {
            counter[2] ++;
        } else 
        if (lettergrades[i] == "D") {
            counter[3] ++;
        } else 
        if (lettergrades[i] == "F") {
            counter[4] ++;
        }
    }
    //divides the frequency with class length and stores in their own respective element.
    for (int j = 0; j < 5; j++) {
        // cout << "counter[" << j << "]: " << counter[j] << "    length: " << length << endl;
        tmpavg += counter[j];
        // cout << "tmpavg: " << tmpavg << endl;
        currentclass->letterGradeProportions[j] = 100*(tmpavg/length);
        // cout << "currclass->lettergradeprop[" << j << "]: " << currentclass->letterGradeProportions[j] << endl;
        tmpavg = 0;
        }
            
}

//calc letter grade from average score for each individual student.
void calclettergrade(Student* students, int& length) {
    int tmpavg;
    for (int currstudent = 0; currstudent < length; currstudent++) {
        tmpavg = students[currstudent].average;
        if (tmpavg < 60) {
            students[currstudent].lettergrade = "F";
        } else
        if (tmpavg >= 60 && tmpavg < 70 ) {
            students[currstudent].lettergrade = "D";
        } else
        if (tmpavg >= 70 && tmpavg < 80 ) {
            students[currstudent].lettergrade = "C";
        } else
        if (tmpavg >= 80 && tmpavg < 90 ) {
            students[currstudent].lettergrade = "B";
        } else
        if (tmpavg >= 90) {
            students[currstudent].lettergrade = "A";
        }
    }
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

//get length of source file
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
            // cout << currentline << endl;
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


//find average of test score for each individual student
void calcAverageTestScore(Student* students, int &length) {
    float tmpavg=0;
    //for each student
    for (int currstudent = 0; currstudent < length; currstudent ++){
        //add each of their test scores
        for (int j = 0; j < 4; j++) {
           tmpavg += stoi(students[currstudent].scores[j]);
        }
        //then divide the sum by 4 and save it to current student's struct
        students[currstudent].average = tmpavg/4;
        tmpavg = 0;
    }
}

//using iomanip to format the data to a table
void printtable(Student* students,Class* currentclass, int &length) {
    cout << setfill('=') << setw(93) << '\n';
    cout << setfill(' ') << "fname" << setw(15) <<  "lname" << setw(20) <<  "test1" << setw(10)  << "test2" << setw(10) << "test3" << setw(11) <<  "test4" << setw(9) << "avg" << setw(11) << "grade" << endl;
    cout << setfill('=') << setw(93) << '\n';
    for (int currstudent = 0; currstudent < length; currstudent++) {
        // cout << "yoyoyoyo  : " << students[currstudent].lettergrade << endl;
        cout << left << setfill(' ') <<
            setw(15) << students[currstudent].fname << 
            setw(15) << students[currstudent].lname << 
            setw(10) << right << students[currstudent].scores[0] <<
            setw(10) << students[currstudent].scores[1] << 
            setw(10) << students[currstudent].scores[2] << 
            setw(10) << students[currstudent].scores[3];
            cout << fixed << setw(11) << setprecision(2) << students[currstudent].average << 
            setw(8) << students[currstudent].lettergrade <<
            '\n';
    }
    cout << setfill('*') << setw(93) << '\n';
    cout << left << setfill(' ') 
        << setw(15) << "Class Average: " 
        << fixed << setw(15) << right << setprecision(2)
        << currentclass->average << endl;
    cout << setw(15) << left << "Class Max:" 
        << setw(15) << right << currentclass->max << '\n'
        << setw(15) << left << "Class Min:" 
        << setw(15) << right << currentclass->min << '\n';
    cout << setfill('=') << setw(93) << "\n";
    cout << left  << setfill(' ')
        << setw(10) << "Total As: " << setw(19) <<right << int(currentclass->letterGradeProportions[0]) << "%\n"
        << setw(10) << "Total Bs: " << setw(19) <<right << int(currentclass->letterGradeProportions[1]) << "%\n"
        << setw(10) << "Total Cs: " << setw(19) <<right << int(currentclass->letterGradeProportions[2]) << "%\n"
        << setw(10) << "Total Ds: " << setw(19) <<right << int(currentclass->letterGradeProportions[3]) << "%\n"
        << setw(10) << "Total Fs: " << setw(19) <<right << int(currentclass->letterGradeProportions[4]) << "%" << endl;
    cout << right << setfill('=') << setw(93) << ' ' << endl;

}

//write buffer the output file
void writetofile(ofstream& fout,Student* students, Class* currentclass, int& length) {
    fout << setfill('=') << setw(93) << '\n';
    fout << setfill(' ') << "fname" << setw(15) <<  "lname" << setw(20) <<  "test1" << setw(10)  << "test2" << setw(10) << "test3" << setw(11) <<  "test4" << setw(9) << "avg" << setw(11) << "grade" << endl;
    fout << setfill('=') << setw(93) << '\n';
    for (int currstudent = 0; currstudent < length; currstudent++) {
        // cout << "yoyoyoyo  : " << students[currstudent].lettergrade << endl;
        fout << left << setfill(' ') <<
            setw(15) << students[currstudent].fname << 
            setw(15) << students[currstudent].lname << 
            setw(10) << right << students[currstudent].scores[0] <<
            setw(10) << students[currstudent].scores[1] << 
            setw(10) << students[currstudent].scores[2] << 
            setw(10) << students[currstudent].scores[3];
            fout << fixed << setw(11) << setprecision(2) << students[currstudent].average << 
            setw(8) << students[currstudent].lettergrade <<
            '\n';
    }
    fout << setfill('*') << setw(93) << '\n';
    fout << left << setfill(' ') 
        << setw(15) << "Class Average: " 
        << fixed << setw(15) << right << setprecision(2)
        << currentclass->average << endl;
    fout << setw(15) << left << "Class Max:" 
        << setw(15) << right << currentclass->max << '\n'
        << setw(15) << left << "Class Min:" 
        << setw(15) << right << currentclass->min << '\n';
    fout << setfill('=') << setw(93) << "\n";
    fout << left  << setfill(' ')
        << setw(10) << "Total As: " << setw(19) <<right << int(currentclass->letterGradeProportions[0]) << "%\n"
        << setw(10) << "Total Bs: " << setw(19) <<right << int(currentclass->letterGradeProportions[1]) << "%\n"
        << setw(10) << "Total Cs: " << setw(19) <<right << int(currentclass->letterGradeProportions[2]) << "%\n"
        << setw(10) << "Total Ds: " << setw(19) <<right << int(currentclass->letterGradeProportions[3]) << "%\n"
        << setw(10) << "Total Fs: " << setw(19) <<right << int(currentclass->letterGradeProportions[4]) << "%" << endl;
    fout << right << setfill('=') << setw(93) << ' ' << endl;
}
