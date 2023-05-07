/*
Name: Jeremy Bergen

Student Records
*/
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

struct Student {
    string fName;
    string lName;
    float gpa;
    string criminal;
    string favClass;
};

void readData(ifstream&, Student*, int&);
void printData(Student*, int&);

int main(int argc, char *argv[]) {
    int lineNumber = 0;
    Student *students = new Student[10];
    ifstream fin("student.csv");

    readData(fin, students, lineNumber);
    printData(students, lineNumber);

    fin.close();
    delete[] students;
    return 0;
}

void printData(Student* students, int& lineNumber) {
    cout << left << setw(13) << "First Name:" << setw(13) << "Last Name:" << setw(5) << "GPA:" << setw(10) << "Criminal: " << "  " << "Favorit Class:" << endl;
    for (int i = 0; i < lineNumber; i++) {
        cout << left << setw(13) << students[i].fName 
             << setw(13) << students[i].lName 
             << setw(5) << students[i].gpa 
             << setw(10) << students[i].criminal 
             << "  " << students[i].favClass << endl;
    }
}

void readData(ifstream& fin, Student* students, int& lineNumber) {
    string currentLine;
    while(getline(fin, currentLine)) {
        int counter = 0;
        stringstream ss(currentLine);

        string token;
        while(getline(ss, token, ',')) {
            // cout << "DEBUG: token: " << token << endl;
            if(counter == 0) {
                students[lineNumber].fName = token;
            } else if (counter == 1) {
                students[lineNumber].lName = token;
            } else if (counter == 2) {
                students[lineNumber].gpa = stof(token);
            } else if (counter == 3) {
                students[lineNumber].criminal = token;
            } else {
                students[lineNumber].favClass = token;
            }
            counter++;
        }
        // cout << "DEBUG: currentLine: " << currentLine << endl;
        // cout << "DEBUG: students[" << lineNumber << "].fname: " << students[lineNumber].fName << endl;
        // cout << "DEBUG: students[" << lineNumber << "].lname: " << students[lineNumber].lName << endl;
        // cout << "DEBUG: students[" << lineNumber << "].gpa: " << students[lineNumber].gpa << endl;
        // cout << "DEBUG: students[" << lineNumber << "].criminal: " << students[lineNumber].criminal << endl;
        // cout << "DEBUG: students[" << lineNumber << "].favclass: " << students[lineNumber].favClass << endl;
        lineNumber++;
    }
}

// void readData(ifstream& fin, Student* students, int& lineNumber) {
//     string currentLine;

//     while(getline(fin, currentLine)) {
//         cout << "DEBUG: currentLine: " << currentLine << endl;
//         int commaIdx = 0;
//         int commaIndex[5];
//         int currentComma = 0;

//         for(int i = 0; i < currentLine.size(); i++) {
//             commaIdx = currentLine.find(',', i);
//             commaIndex[currentComma] = commaIdx;
//             currentComma++;
//             // cout << "DEBUG: commaIdx: " << commaIdx << endl;

//             // if (commaIdx == string::npos) {
//             //     students[lineNumber].favClass = currentLine.substr(i);
//             //     // cout << "DEBUG: currentLine.substr(): " << currentLine.substr(i) << endl;
//             // } else {
//                 // if(i == 0) {
//                 //     students[lineNumber].fName = currentLine.substr(i, commaIdx-i);
//                 // } else if
//                 // cout << "DEBUG: currentLine.substr(): " << currentLine.substr(i, commaIdx-i) << endl;
//             // }


//             if (commaIdx == string::npos) {
//                 break;
//             }
//             // cout << "DEBUG: currentLine.substr(): " << currentLine.substr(commaIdx, )
//             i = commaIdx;
//         }
//         // for (int i = 0; i < currentComma; i++) {
//         //     cout << "DEBUG: commaIndexs[" << i << "]: " << commaIndex[i] << endl;
//         // }
//         students[lineNumber].fName = currentLine.substr(0, commaIndex[0]);
//         students[lineNumber].lName = currentLine.substr(commaIndex[0]+1, commaIndex[1]-commaIndex[0]-1);
//         students[lineNumber].gpa = stof(currentLine.substr(commaIndex[1]+1, commaIndex[2]-commaIndex[1]-1));
//         students[lineNumber].criminal = currentLine.substr(commaIndex[2]+1, commaIndex[3]-commaIndex[2]-1);
//         students[lineNumber].favClass = currentLine.substr(commaIndex[3]+1);
//         cout << "DEBUG: students[" << lineNumber << "].fname: " << students[lineNumber].fName << endl;
//         cout << "DEBUG: students[" << lineNumber << "].lname: " << students[lineNumber].lName << endl;
//         cout << "DEBUG: students[" << lineNumber << "].gpa: " << students[lineNumber].gpa << endl;
//         cout << "DEBUG: students[" << lineNumber << "].criminal: " << students[lineNumber].criminal << endl;
//         cout << "DEBUG: students[" << lineNumber << "].favclass: " << students[lineNumber].favClass << endl;
//         lineNumber++;
//     }
// }