


#include <iostream>
#include <string>

using namespace std;





















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