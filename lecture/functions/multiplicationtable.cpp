/*

*/

#include <iostream>
#include <string>
#include <cstdio>

//io manipulator
#include <iomanip>

using namespace std;

void printtable(int, int);
void promptsize(int&, int&);

int main(int argc, char *argv[]) {
    int height, width;


    promptsize(height, width);
    cout << "debug: width " << width<< endl;
    cout << "debug: height " << height<< endl;
    printtable(height, width);



}




void printtable(int height, int width) {
    for(int i=0; i<height+1; i++) {
        for (int j=1; j<width+1; j++) {
            //setw sets the length of each stream to 5, the length of the numbers.
            cout << setw(5) << j * i;
        }
    cout << endl;
    }


}

void promptsize(int& height, int& width) {
    cout << "how high is your table: ";
    cin >> height;

    cout << "how wide is your table: ";
    cin >> width;

    // cout << "deubug inside promptsize ";
    // cout << "height " << height;
    // cout << "width " << width;
}

