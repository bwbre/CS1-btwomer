/*

*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct Student {
    string fname;
    string lname;
    int gpa;    
    string criminal;
    string favclass;
};

void readdata(ifstream&, Student*, int&);

int main (int argc, char* argv[]) {
    int linenumber = 0;
    Student *students = new Student[10];
    ifstream fin("file/student.csv");

    readdata(fin, students, linenumber); 




    fin.close();
    delete[] students;
    return 0;
}

void readdata(fstream& fin, Student* Students, int& linenumber) {
    string currentline;
    string token;
        int counter=0;

    while (!fin.eof()) {

        getline(fin, currentline)

        stringstream ss(currentline, token, ',');
        cout << "DEBUG: TOKEN " << token << endl;

        while ()
    }

}



/*too complicated method*/
// void readdata(ifstream& fin, Student* students, int& linenumber) {
//     string currentline;
//     int commaIndex[5];
//     int currentcomma = 0;
//     while (getline(fin, currentline)) {
//         cout << "DEBUG: current line " << currentline << endl;
//         int commaidx = 0;
//         for (int i=0; i < currentline.size(); i++) {
//             commaidx = currentline.find(',', i);
//             commaIndex[currentline] = commaidx;
//             currentcomma++;
//             if (commaidx == string::npos) {
//                 students[linenumber].favclass = currentline.substr(i);
//             }
//             else {
//                 if (i==0) {
//                     students[linenumber].
//                 }
//             }
//             cout << "DEBUG: commaidx " << commaidx << endl;
//             if (commaidx = string::npos) {
//                 break;
//             }
//             cout << "DEBUG: currentline.substr(): " << currentline.substr(commaidx, currentline) << endl;
//             i = commaidx;
//         }
//         students[linenumber].fname = currentline.substr(0, commaidx[0]);
//         students[linenumber].lname = currentline.substr(commaidx[0]+1, commaidx[1]-commaidx[0]-1);
//         students[linenumber].gpa = currentline.substr(commaidx[1]+1, commaidx[3]-commaidx[1]-1);
//         students[linenumber].chistory = currentline.substr(commaidx[3]+1, commaidx[4]-commaidx[3]-1);
//         students[linenumber].favclass = currentline.substr(commaidx[4]+1);
//         linenumber++;
//     }
//  }
