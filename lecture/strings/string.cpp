


#include <iostream>
#include <string>

using namespace std;



/*-----search for strings*/
int main (int argc, char* argv[]) {
    string phrase;
    string wood[4];
    int woodidx = 0;
    string searchstr;

    string substrwords[phrase.length()];

    phrase = "how much wood could a wood chuck chuck if a wood chuck could chuck wood.";
    cout << "what to search for ";
    getline(cin, searchstr);


    for (size_t i = 0; i < phrase.length(); i++) {
        i = phrase.find(searchstr, i);
        if (i != string::npos) {
            cout << "Found phrase at index: " << i << endl;
            substrwords[woodidx] = phrase.substr(i, searchstr.length());
            woodidx++;
        } else {
            break;
        }

         for (int i = 0; i < 4; i++) {
             cout << "wood[" << i << "]: " << wood[i] << endl;
         }
     }




 }

















// int main(int argc, char* argv[]) {
//     string firstname;
//     string lastname;
//     string fullname;
//     string searchstr;
//     string lowerfullname;
//     char somechar;

//     cout << "what is your first name? ";
//     getline(cin, firstname);

//     cout << "what is your last name? ";
//     getline(cin, lastname);

//     fullname = firstname + " " + lastname;
//     lowerfullname = fullname;
//     cout << "welcome " << fullname << endl;



//     cout << fullname.append(" is awesome!") << endl;

//     // cout << "Enter a character to search for: " << endl;
//     // getline(cin, searchstr);

//     for (size_t i = 0; i < searchstr.size(); i++) {
//         searchstr.at(i) = tolower(searchstr.at(i));

//     }

//     //for (parameter; conditional; increment) ---- call parameter, check conditional, run the loop, THEN increment.
//     // for (auto i = fullname.begin(); i != fullname.end(); i++) {?
//     for (size_t i = 0; i < fullname.length(); i++) {
//         i = fullname.find(searchstr, i);
//         if (i != string::npos) {
//             // cout << "Found character at index: " << i << endl;
//         } 
//         else { 
//             i = string::npos - 1;
//         }
//     }

//     string tmpstr = fullname.substr(3/*start at 3*/, 8 /*will grab 8*/);
//     cout << "tmpstr: " << tmpstr << endl;
 

//     // fullname

//         // cout << "The length of your string is: " << fullname.length();
//     // for (int i = 0; i < fullname.length(i); i++) {
//     //     //will print the array.. 
//     //     //using .at() is a SAFER way of calling a position in a string. if not using .at() and exceeding length, then there will be a buffer overflow or similar error. at() helps stop that
//     //     cout << "fullname[" << i << "]: " << fullname[i] << endl;
//     //     cout << "fullname.at(" << i << "): " << fullname.at(i) << endl;

//     //     //takes value, converts to uppercase and store it again.
//     //     fullname[i] = toupper(fullname[i]);
//     // }



//     // cout << "Fullname.begin(): " << *fullname.begin() << endl;

//     //printing out indexes and playing with .FCNS() 
//     // for (auto i = fullname.begin(); i != fullname.end(); i++) {
//     //     cout << *i << endl;
//     //     cout << "This character is at index: " << fullname.find(*i) << endl;
//     // }
    
//     // cout << fullname.begin(i)



//     // cout << "E at index: " << fullname.find('e') << endl; //find(Char, start searching from)
    

//     // cout << "Your name uppercase is: " << fullname << endl;

//     return 0;
// }





void printFlippedTriangle(int height) {
    cout << "\n";
    int row = 1;
    int *rowTotal = 0;
    int *colTotal = 0;
    // row
    while (row <= height) {
        // column
        for(int col = height; col>=row; col--)
            cout << "* ";
                        colTotal++;
        row += 1;
        rowTotal++;
        cout << endl;
    }
        cout << "Row total: " << rowTotal << "Coltotal: " << colTotal<< endl;
}





/*  
FIXME4          *FIXED*
Design and implement a function that takes an integer as height and
prints square of the given height with *.
Square of height 5, e.g., would look like the following.

*  *  *  *  *  
*  *  *  *  *   
*  *  *  *  *   
*  *  *  *  *   
*  *  *  *  *   

*/
void printSquare(int height) {
    cout << "\n";
    int row = 1;
    // (var)Total can be used to run test functions. a square's area is always its length (columns) times it's width (rows)
    // int rowTotal=0;
    // int colTotal = 0;

    while (row <= height) {
        for (int col = 1; col <= height; col++) {
            cout << "* ";
            if (col == height) {
                // colTotal++;
            }
        } 
    rowTotal++;
    row++;
    cout << endl;
    }
    //
    // cout << "Row total: " << rowTotal << "Coltotal: " << colTotal<< endl;
}