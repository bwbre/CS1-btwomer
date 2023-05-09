/*
Name: Jeremy Bergen

Random Presenter
*/
#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <sstream>

using namespace std;

struct Presenter {
    string fName;
    string lName;
};

void countLines(ifstream&, int&);
void readData(ifstream&, Presenter[], int&);
void randPresenter(Presenter[], int&, int&);
void printPresenter(Presenter[], int&);
void writeData(int&, Presenter[], int&, ofstream&);

int main(int argc, char *argv[]) {
    int arrSize = 0;
    int randvictim = 0;
    ifstream fin;
    ofstream fout;
    fin.open("names.csv");
    // cout << "DEBUG: rdstate(): " << fin.rdstate() << endl;
    // cout << boolalpha << "DEBUG: good(): " << fin.good() << endl;
    // cout << boolalpha << "DEBUG: eof(): " << fin.eof() << endl;
    // cout << boolalpha << "DEBUG: fail(): " << fin.fail() << endl;
    // cout << boolalpha << "DEBUG: bad(): " << fin.bad() << endl;

    // cout << "DEBUG: fin.tellg(): " << fin.tellg() << endl;
    countLines(fin, arrSize);
    // cout << "After countLines" << endl;
    // cout << "DEBUG: rdstate(): " << fin.rdstate() << endl;
    // cout << boolalpha << "DEBUG: good(): " << fin.good() << endl;
    // cout << boolalpha << "DEBUG: eof(): " << fin.eof() << endl;
    // cout << boolalpha << "DEBUG: fail(): " << fin.fail() << endl;
    // cout << boolalpha << "DEBUG: bad(): " << fin.bad() << endl;
    // // fin.seekg(0, fin.beg);
    // fin.close();
    // fin.open("names.csv");
    // cout << "DEBUG: fin.tellg(): " << fin.tellg() << endl;
    // cout << "DEBUG: arrSize: " << arrSize << endl;
    // cout << "DEBUG: sizeof(Presenter): " << sizeof(Presenter) << endl;

    Presenter presenters[arrSize];

    readData(fin, presenters, arrSize);

    // for(int i = 0; i < arrSize; i++) {
    //     cout << "DEBUG: " << presenters[i].fName << " " << presenters[i].lName << endl;
    // }
    

    randPresenter(presenters, arrSize, randvictim);
    printPresenter(presenters, arrSize);

    /*
    NOTES:
        --when ofstream opens file, by default it trunkates it-- wiping it
        --If fin has it open, then it won't trunkat it.
    */
    fin.close(); // use before end so itll start from beginning
    fout.open("names.csv"); //use after fin close..
    writeData(randvictim, presenters, arrSize, fout);
    

    fout.close();
    return 0;
}

void writeData(int& randvictim, Presenter presenters[], int& arrsize, ofstream& fout) {
    for (int i=0; i < arrsize; i++) {
        if (i==randvictim){
            continue;
        }
        fout << presenters[i].lName << ", " << presenters[i].fName << endl;
    }

}

void printPresenter(Presenter presenters[], int& randvictim) {
    cout << "The next victim is...\n" << presenters[randvictim].fName << " " << presenters[randvictim].lName << endl;
}

void randPresenter (Presenter presenters[], int& arrcounter, int& randvictim) {
    randvictim = random()%arrcounter;
}

void countLines(ifstream& fin, int& numLines){
    string tmpBuf;
    cout << "DEBUG: fin.tellg(): " << fin.tellg() << endl;
    while(getline(fin, tmpBuf)) {
        numLines++;
    }
    fin.clear();
    fin.seekg(0);
    cout << "DEBUG: fin.tellg(): " << fin.tellg() << endl;
}

void readData(ifstream& fin, Presenter presenters[], int& arrCounter) {
    string inputLine;
    int counter = 0;
    // cout << "DEBUG: fin.tellg(): " << fin.tellg() << endl;
    while(getline(fin, inputLine)) {
        int nameCount = 0;
        string token;
        stringstream iss(inputLine);
        while(getline(iss, token, ',')) {
            if(nameCount == 0) {
                presenters[counter].lName = token;
            } else {
                size_t foundchar = token.find_first_not_of(' ');
                presenters[counter].fName = token.substr(foundchar);
            }
            nameCount++;
        }
        //inputLine = Bergen, Jeremy
        // cout << "DEBUG: inputLine: " << inputLine << endl;
        // size_t found = inputLine.find(", ");
        // presenters[counter].lName = inputLine.substr(0, found);
        // presenters[counter].fName = inputLine.substr(found+2);
        counter++;
    }
}