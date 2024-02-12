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
    int size;
    float average;
    int max[4];
    int min[4];
    vector<int> test1scores;
    vector<int> test2scores;
    vector<int> test3scores;
    vector<int> test4scores;
    float testaverages[4];
    float letterGradeProportions[5];
};


//fcns used to prompt user
string promptsourcefile();
string promptdestfile();
//find the number of lines in the files
void findlength(ifstream&, int&);
//copy file to buffe
void copytobuffer(ifstream&, Student*, int&);
//write to output file in table format
void writetofile(ofstream&, Student*, Class*, int&);
//calc an individual student's letter grade
void calclettergrade(Student*, int&);

//calculate stats and class data
void copyClassDataFromBuffer(Student*, int&, float*, string*);
void calcAverageTestScore(Student*, Class*, int&); //find averages for each student and save each student's struct
void classAverages(Student*, Class*, int&);
void calcClassStats(Student*, Class*, int&);
void calcClassAveragesStats(Student*, Class*, int&);
void calcClassLetterGradesStats(Class*, int&, string*);
void ClassAverages(Student*, Class*, int&);
void testMinMax(Student*, Class*, int&);

//iomanip to print table to consolde -- for debugging and visual aid
void printtable(Student*, Class*, int&);



int main(int argc, char* argv[]) {
    int length=0;
    string sourcefile, destfile;
    ifstream fin;
    ofstream fout;

    //get source and output file
    sourcefile = promptsourcefile();
    destfile = promptdestfile();

    //open and copy data from source file
    fin.open(sourcefile);
    Class *currentclass = new Class;
    findlength(fin, length);
    currentclass->size = length;
    Student *students = new Student[length];
    copytobuffer(fin, students, length);
    cout << "here" << endl;
    fin.close();

    //use data in buffer for calculations
        cout << "here2" << endl;
    calcAverageTestScore(students, currentclass, length);
    calclettergrade(students, length);
    calcClassStats(students, currentclass, length);
        cout << "here3" << endl;
    
    printtable(students, currentclass, length);

    //write the data to the outputfile in the table format
    fout.open(destfile);
    writetofile(fout, students, currentclass, length);
    fout.close(); 

    //delete structs
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
    for (int i = 0; i < length; i++)  {
        tmpavg += averages[i];
    }
    currentclass->average = (tmpavg / float(length)); //the class's overall average
    sort(averages, (averages+(length-1))); //sort the class averages array
    classAverages(students, currentclass, length);
    testMinMax(students, currentclass, length);
    calcClassLetterGradesStats(currentclass, length, lettergrades); //will calc and grab the %proportion for each letter grade
}

//count all the letter grades, calc % proportions, store into class struct
void calcClassLetterGradesStats(Class* currentclass, int& length, string* lettergrades) {
    float tmpavg=0;
    int counter[5] = {0,0,0,0,0}; //{A, B, C, D, F}
    //counts the frequency of each letter grade
    for (int i = 0; i < length; i++) {
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
        tmpavg += counter[j];
        currentclass->letterGradeProportions[j] = 100*(tmpavg/length);
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
void calcAverageTestScore(Student* students, Class* currentclass, int &length) {
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
        << setw(20) << "Class Average: " 
        << fixed << setw(20) << right << setprecision(2)
        << currentclass->testaverages[0] 
        << setw(10) << currentclass->testaverages[1] 
        << setw(10) << currentclass->testaverages[2] 
        << setw(10) << currentclass->testaverages[3] << endl;
    cout << setw(20) << left << "Class Max:" 
        << setw(20) << right << currentclass->max[0]
        << setw(10) << currentclass->max[1]
        << setw(10) << currentclass->max[2]
        << setw(10) << currentclass->max[3] << '\n'
        << setw(20) << left << "Class Min:" 
        << setw(20) << right << currentclass->min[0]
        << setw(10) << currentclass->min[1]
        << setw(10) << currentclass->min[2]
        << setw(10) << currentclass->min[3] << '\n';
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
        << setw(20) << "Class Average: " 
        << fixed << setw(20) << right << setprecision(2)
        << currentclass->testaverages[0] 
        << setw(10) << currentclass->testaverages[1] 
        << setw(10) << currentclass->testaverages[2] 
        << setw(10) << currentclass->testaverages[3] << endl;
    fout << setw(20) << left << "Class Max:" 
        << setw(20) << right << currentclass->max[0]
        << setw(10) << currentclass->max[1]
        << setw(10) << currentclass->max[2]
        << setw(10) << currentclass->max[3] << '\n'
        << setw(20) << left << "Class Min:" 
        << setw(20) << right << currentclass->min[0]
        << setw(10) << currentclass->min[1]
        << setw(10) << currentclass->min[2]
        << setw(10) << currentclass->min[3] << '\n';
    fout << setfill('=') << setw(93) << "\n";
    fout << left  << setfill(' ')
        << setw(10) << "Total As: " << setw(19) <<right << int(currentclass->letterGradeProportions[0]) << "%\n"
        << setw(10) << "Total Bs: " << setw(19) <<right << int(currentclass->letterGradeProportions[1]) << "%\n"
        << setw(10) << "Total Cs: " << setw(19) <<right << int(currentclass->letterGradeProportions[2]) << "%\n"
        << setw(10) << "Total Ds: " << setw(19) <<right << int(currentclass->letterGradeProportions[3]) << "%\n"
        << setw(10) << "Total Fs: " << setw(19) <<right << int(currentclass->letterGradeProportions[4]) << "%" << endl;
    fout << right << setfill('=') << setw(93) << ' ' << endl;
}

void classAverages(Student* students, Class* currentclass, int& length) {
    int testnumber = 0;
    string tmpv; //will copy the string value from the student
    int tmpnum; //will store the value converted from string to int

    //store all the student's tests into class struct testscores vectors
    for (int i = 0; i < length; i++) {
        if (testnumber == 0) {
            tmpv = students[i].scores[testnumber];
            tmpnum = stoi(tmpv);
             currentclass->test1scores.push_back(tmpnum);
        }
        else if (testnumber == 1) {
            tmpv = students[i].scores[testnumber];
            tmpnum = stoi(tmpv);
            currentclass->test2scores.push_back(tmpnum);
        }
        else if (testnumber == 2) {
            tmpv = students[i].scores[testnumber];
            tmpnum = stoi(tmpv);
            currentclass->test3scores.push_back(tmpnum);
        }
        else {
            tmpv = students[i].scores[testnumber];
            tmpnum = stoi(tmpv);
            currentclass->test4scores.push_back(tmpnum);
        }
        if (i == (length-1) && testnumber == 3) {
            break;
        }
        /*once the final student has been processed,
         move to next test starting from student[0] */
        if (i == length -1){
            testnumber++;
            i = -1;
        }
    }

    //find each test's  total class avg
    float tmpavg=0;
    //test1 loop
    for (int i = 0; i < length; i++) {
        tmpavg += currentclass->test1scores[i];
    }
    currentclass->testaverages[0] = tmpavg/float(length); //test1 avg
    tmpavg=0;
    //test2 loop
    for (int i = 0; i < length; i++) {
        tmpavg += currentclass->test2scores[i];
    }
    currentclass->testaverages[1] = tmpavg/float(length); //test2 avg
    tmpavg=0;
    //test3 loop
    for (int i = 0; i < length; i++) {
        tmpavg += currentclass->test3scores[i];
    }
    currentclass->testaverages[2] = tmpavg/float(length); //test3avg
    tmpavg=0;
    //test4 loop
    for (int i = 0; i < length; i++) {
        tmpavg += currentclass->test4scores[i]; 
     }
    currentclass->testaverages[3] = tmpavg/float(length); //test4 avg
}

void testMinMax(Student* students, Class* currentclass, int& length){
    //sort all the vectors that store test scores for whole class
    sort(currentclass->test1scores.begin(), currentclass->test1scores.end());
    sort(currentclass->test2scores.begin(), currentclass->test2scores.end());
    sort(currentclass->test3scores.begin(), currentclass->test3scores.end());
    sort(currentclass->test4scores.begin(), currentclass->test4scores.end());
    //save first element -- the smallest
    currentclass->min[0] = currentclass->test1scores[0];
    currentclass->min[1] = currentclass->test2scores[0];
    currentclass->min[2] = currentclass->test3scores[0];
    currentclass->min[3] = currentclass->test4scores[0];
    //save final element -- the largest
    currentclass->max[0] = currentclass->test1scores[length-1];
    currentclass->max[1] = currentclass->test2scores[length-1];
    currentclass->max[2] = currentclass->test3scores[length-1];
    currentclass->max[3] = currentclass->test4scores[length-1];
}