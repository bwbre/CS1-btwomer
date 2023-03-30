


#include <iostream>
#include <string>

using namespace std;


int main(int argc, char* argv[]) {
    string firstname;
    string lastname;
    string fullname;
    char somechar;

    cout << "what is your first name? ";
    getline(cin, firstname);

    cout << "what is your last name? ";
    getline(cin, lastname);

    fullname = firstname + " " + lastname;
    cout << "welcome " << fullname << endl;


    // cout << "The length of your string is: " << fullname.length();
    // for (int i = 0; i < fullname.length(i); i++) {
    //     //will print the array.. 
    //     //using .at() is a SAFER way of calling a position in a string. if not using .at() and exceeding length, then there will be a buffer overflow or similar error. at() helps stop that
    //     cout << "fullname[" << i << "]: " << fullname[i] << endl;
    //     cout << "fullname.at(" << i << "): " << fullname.at(i) << endl;

    //     //takes value, converts to uppercase and store it again.
    //     fullname[i] = toupper(fullname[i]);
    // }

    cout << fullname.append(" is awesome!") << endl;
    cout << "Fullname.begin(): " << *fullname.begin() << endl;

    //printing out indexes and playing with .FCNS() 
    // for (auto i = fullname.begin(); i != fullname.end(); i++) {
    //     cout << *i << endl;
    //     cout << "This character is at index: " << fullname.find(*i) << endl;
    // }
    
    // cout << fullname.begin(i)



    cout << "E at index: " << fullname.find('e') << endl; //find(Char, start)

    for (auto i = fullname.begin(); i != fullname.end();i++) {
        foundindex = fullname.find('e');


    }




    // cout << "Your name uppercase is: " << fullname << endl;

    return 0;
}