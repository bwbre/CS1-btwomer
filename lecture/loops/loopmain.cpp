/* This is practice/ example on how to repeatedly run main. by using another function as a new "main" can make the OG main cleaner and neater
*/



#include <iostream>

using namespace std;

// this will be the arbritarily assigned "new" main that will actually run everything inside the function. while main just manages the running and ending the overall program.
bool program();


int main() {
    bool (keepRunning = true);

    while (keepRunning) {
        if (!program()) {
            keeprunning=false;
            break;
        }


    }

}



//DIDNT FINISH