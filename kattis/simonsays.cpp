/*
brendan Womer

kattis: Simon Says

*/


#include <iostream>
#include <string>

using namespace std;

int main(int argc,char* argv[]) {
    int numlines;


    cin >> numlines;
    string inputline[numlines];

    for (int i = 0; i <numlines; i++) {
        cin >> inputlines[i];

    }

    for (i = 0; i < inputline[i]; i++) {
        size_t foundsimon;
        foundsimon = inputlines[i].find("Simon says");
        if (foundsimon != string::npos) {
            cout << inputlines[i].subtr(11) << endl;

        }

    }
    return 0;

}