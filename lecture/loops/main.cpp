/*
name: Brendan Womer

we go round and round.... loopy... looping
*/



#include <iostream>

using namespace std;

/* TESTING for() LOOPS, good for when you know how many time needs to run
*/
// int commentoutforloops () {
//     int i = 0;
//     int j = 0;
    
//     /*  ---initialize for loop everything inside for (blah, blah, blah) is self contained inside the for ()....
//     --- for(declaration ; condition ; expression) as long as condition is true, will continue to run.
//         for(condition ; expression)
//     ---VARIABLES don't leave for loop, BUT values will. -> for (int i); wont leave, but for (i) will. 
//     ---if you cout << i; outside of for loop it wont work. usually use single characters like i or j.. unless prev line
//     ---"short" is an integer that is 16 bit instead of 32 bit. 
//     ---each iteration will wipe out values and run from beginning. if j = 0; inside for(), then each run it will reset back to 0,
//         need to define j = 0 in main()
//     ---if for( ; ;) then it will loop infinitely, no parameters of any kind, will run over and over.
//     ---if for( ; ;i++) will loops i forever


// ----listed increments are == to each other ------- 
//     //notes
//     i++ 
//     == 
//     //note
//     (i = i+1) 
//     == 
//     //
//     (i += 1) 
//     == 
//     //
//     (++i)
//     */
//     /*for (int i = 0, int j = 5; (i < 10) && (j > 0); i++ , j--) {
//         i = 0;
//         j = (j+1);
//     */
//     //will run i loop 10 times, each time will run nested loop 10 times.
//     for (int i = 0, int j = 5; (i < 10) && (j > 0); i++ , j--) {
//         for (int j = 0; (j < 10); j++) {
//             cout << " i: " << i << "j: " << j << endl
//             }
//         }
//         //will run loop and add hello world to EACH iteration
//         cout << i << ": hello world" << endl;
//         cout << "j: " << j << endl;
// }

/*While loops are good when you dont know how many times you want loop to run
    while will run minimum 1 time
    do() loop can run 0 times*/
int main() {
    int counter = 0;
    /* adding ! to the beginning will evaluate as if entire parameter !==
        while(! counter = 50)    while (isnt true)
    */
    while(counter != 50) {
        cout << counter << ": Hello World" << endl;
        counter++;
    }
    
    for (int i= 0; i < 10; i++) {
        cout << i << ": Hello World" << endl;
    }

}
