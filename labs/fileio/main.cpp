/*
    CS1 - File IO Lab

    Updated by: Brendan Womer
    Date: 05/1/23

    The program reads numbers from a file and finds statistical values from those numbers.
    Lab demonstrates the file io and vector application. 
    Statistical value's definitions for mean, median, mode, etc. can be found here: https://www.purplemath.com/modules/meanmode.htm
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define DEBUG(s, n) cout << s <<  n << endl;

const float EPSILON = 1e-4; //accuracy upto 4 decimal points

// function prototypes
void readData(vector<int> &, const string);
int findMax(const vector<int> &);
int findMin(const vector<int> &);
float findMean(const vector<int> &); // average
int findRange(const vector<int> &);
float findMedian(vector<int>);
// bonus implement findMode function
int findMode(const vector<int> &);

void writeData(const vector<int> & numbers);
void test();

int main(int argc, char* argv[]) {
    if (argc == 2 && string(argv[1]) == "test") {
        test();
        return 0;
    }
    vector<int> numbers;
    string inFile;
    cout << "Enter input file name: ";
    getline(cin, inFile);
    readData(numbers, inFile);
    writeData(numbers);
    cout << "All done. Enter to exit...";
    cin.get();
    return 0;
}

void readData(vector<int> & numbers, const string inputFileName) {
    // FIXME3: Open inputFileName for reading data  ***FIXED***

    int tmpnum, vectorsize, idk;
    ifstream fin;
    fin.open(inputFileName);
    int linecounter = 0;
    string currline;
    // cout << "init " << endl;
    //copies file to tmp[]
    while (!fin.eof()) { 
        fin >> idk;
        linecounter++;
        // cout << "here" << endl;
    }
    // cout << "outside: " << linecounter << endl;

    int tmp[linecounter];
    vectorsize = linecounter;
    linecounter = 0;
    fin.seekg(0);
    while (!fin.eof()) {
        while (getline(fin, currline)) {
            tmp[linecounter] = stoi(currline);
            // cout << "tmp[" << linecounter << "]: " << tmp[linecounter] << endl;
            linecounter++;
        }
    }

    // cout << "\nafter copy\n";
    // for (int j = 0; j < vectorsize; j++) {
    //     cout << "tmp[" << j << "]: " << tmp[j] << endl;
    // }
    // cout << "\n before sort" << endl;

    for (int i = 0; i < vectorsize; i++) {
        if (tmp[i] > tmp[i+1] && (i+1) < vectorsize) {
            tmpnum = tmp[i];
            tmp[i] = tmp[i+1];
            tmp[i+1] = tmpnum;
            // for (int j = 0; j < vectorsize; j++) {
            //     cout << tmp[j] << ", ";
            // }
            // cout << endl;
            i = -1;
        }
    }


    for (int m=0; m < vectorsize; m++) {
        numbers.push_back(tmp[m]);
    }


    fin.close();
}

void writeData(const vector<int> & numbers) {
    // FIXME4   **FIXED**

    ofstream fout;
    string outputfile;
    cout << "Please enter the outputfile: ";
    getline(cin, outputfile);
    fout.open(outputfile);
    int length = sizeof(numbers)/sizeof(numbers[0]);
    int max = findMax(numbers);
    int min = findMin(numbers);
    int median = findMedian(numbers);
    int range = findRange(numbers);

    
    fout << '\n' << setw(40) << setfill('=') << right << '\n';
    fout << setw(10) << setfill(' ') << left << "Statistical Results\n"
        << setw(40) << setfill('=') << right << '\n' 
        << setw(8) << setfill(' ') << left << "Max" 
        << setw(8) << "Min" << setw(8) << "Median" \
        << setw(8) << "Range" << endl;
    fout << setw(8) << left << max
        << setw(8) << min
        << setw(8) << median
        << setw(8) << range << endl;

    /*    
    Algorithm steps:
    1. Prompt user to enter output file name
    2. Store and use the file name to open the file in write mode
    3. Write output as shown in output.txt file with proper formatting using iomanip
    */ 
   fout.close();

    /*
    List of Numbers: 100 10 5 0 -99 10 99

    ========================================
              Statistical Results
    ========================================
    Max     Min     Mean     Median    Range
    100     -99     17.86        10      199 
    */
}

int findMax(const vector<int> & nums) {
    int max = nums[0];
    for(int n: nums)
        max = (n>max) ? n : max;
    return max;
}

int findMin(const vector<int> & nums) {
    // FIXME5 - implement function to find and return min value from nums vector     *FIXED*

    //already sorted
    int min = nums[0];


    return nums[0];
} 

float findMean(const vector<int> & nums) {
    // same as average
    long long int sum = 0;
    for(int n: nums)
        sum += n;
    return sum/float(nums.size());
}


int findRange(const vector<int> & nums) {
    // FIXME6 - implement function that finds and returns the range value   *FIXED*
    int range, max, min;
    max = findMax(nums);
    min = findMin(nums);
    range = max - min;
    
    return range;
}

float findMedian(vector<int> nums) {
    float median;
    if (nums.size() % 2 == 0) {  // even set
        median = (nums[nums.size()/2] + nums[nums.size()/2-1])/float(2);
    } else { // odd set
        median = nums[nums.size()/2];
    }
    return median;
}

void test() {
    vector<int> numbers = {100, 10, 5, 0, -99, 10, 99};
    //cout << findMean(numbers) << " " << findMean(numbers)-17.857142 << endl;
    assert(fabs(findMean(numbers)-17.857142) <= EPSILON );
    assert(findMax(numbers) == 100);
    assert(findMedian(numbers) == 10);
    vector<int> numbers1 = {10, 10, 10, 0, -10, -10};
    assert(fabs(findMean(numbers1) -1.6667) <= EPSILON  );
    assert(findMax(numbers1) == 10);
    assert(findMedian(numbers1) == 5);
    // FIXME7: Write at least two test cases for other functions

    cerr << "all test cases passed!\n";
}