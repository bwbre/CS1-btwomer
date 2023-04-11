/*
Kattis - Hissing Microphone Problem

By: Brendan Womer
Date: 04/09/23

Hissing Microphone Problem Statement: https://open.kattis.com/problems/hissingmicrophone
Algorithm steps:
1. Read string
2. find "ss" substring in the string
    - if found, print "hiss"
    - otherwise, print "no hiss"


NOTE: It worked with kattis until the weird requirement at the end that wanted to restrict the string to lowercase with no spaces. 
    The program still works completely fine, but kattis won't work. It worked before I added the requirement.
*/

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

// function prototypes
string answer(const string &line);
void testAnswer();
void solve();

int main(int argc, char* argv[]) {
    if (argc == 2 and string(argv[1]) == "test")
        testAnswer();
    else
        solve();
}

string answer(const string &line) {
    for (size_t i = 0; i < line.length(); i++) {
        i = line.find("ss", i);
        if (i == string::npos) {
            return "no hiss";
        }
        else {
            break;
        }

    }

    // implement algorithm step 2
    // return "hiss" if ss is found in line
    // otherwise, return "no hiss"
    return "hiss";
}

// unit testing answer()
void testAnswer() {
    string line = "sslippery ssnake.";
    assert(answer(line) == "hiss");

    line = "no snakes allowed";
    assert(answer(line) == "no hiss");

    // write at least two test cases to test answer()
    cerr << "All test cases passed!\n";
}

// solving the problem for kattis
void solve() {
    string line;

    // string consists of only lowercase letters (no spaces) upto 30 chars
    // FIXME5 *FIXED*
    // Don't really understand this requirement, i feel like it limits the program for no reason-- plus breaks kattis' results.
    do {
        cout << "\nEnter a string up to 30 characters long, without any spaces: ";
        getline(cin, line);
        if (line.length() > 30 || line.find(" ", 0) != string::npos){
            cout << "\nINVALID: String must be under 30 characters without spaces.\n\n\n";
        }
        else {
            //converts input to lower case as requested.
            for(size_t i = 0; i < line.length(); i++){
                line[i] = tolower(line[i]); 

                /* will print each element of string*/
                // cout << "line[" << i << "]: " << line[i] << endl;          
            }
        }
    }
    while (line.length() > 30 || line.find(" ", 0) != string::npos);



    // read string into line
    cout << answer(line) << "\n" << endl;
}