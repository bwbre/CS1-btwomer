/*
    StdIO Lab 1`
    ASCII Art - using literals and variables
    
    Updated By: Brendan Womer
    Date: ... 10/02/2023
    
    This program produces an ASCII art on the console.
    Algorithm steps: 
    1. Use variables to store data/values
    2. Write a series of cout statements to print the data/values
*/

#include <iostream> //library for input and output
#include <string> //library for string data
 
using namespace std; //resolve cout, cin, and endl names
void append();

//main entry point of the program
int main()
{
    //FIXME3: declare a variable to store name *FIXED*
    //FIXME4: prompt user to enter their name and store the value in variable *FIXED*
    string name;
    cout << "Hello, please enter your name: ";
    getline (cin, name); // using getline since there may be two values put in

    //FIXME5: greet the name using the variable as the following output *FIXED*
    //must output: Nice meeting you, <name>! *FIXED*
    cout << "Nice meeting you, " << name << endl;


 /* When making the ASCII art i found that the length of a user's name would affect the strictly 
 defined string in the line after the name is called. To fix this I wanted the distance from the
 end of "by:" to the "*" to be the same. So i added X amount of spaces after the name so that the
  distance is always the same.  */


    int namelength = name.length(); //Storing length of the inputed name to be used later
    int spaces = 19-namelength; //finding the difference between the ideal space and the length of the name
    name.append(spaces, ' ' ); //add ' ' to the end of string name, (spaces) numbers of times
    cout << name;

    cout << "Hope you like my Tom & Jerry ASCII art...\n\n";

    string line1 = "  | \\_/|        *****************************     ( \\_/)\n";
    string line2 = " /  @  @ \\      *         ASCII Lab         *     (='.'=)\n";
    string line3 = "( >  0  < )     *     By:" + name + "*   ( \" )_(  \" )\n";
    string line4 = "   >>x<<        *         CSCI 111          *\n";
    string line5 = " /   O   \\      ***************************** \n";

    cout << line1 << line2 << line3 << line4 << line5 << endl;

    //FIXME6: use variable to print the second line line of the graphic *FIXED*
    //FIXME7: print the third line of the graphics *FIXED*
    //FIXME8: use variable to print the fourth line *FIXED*
    //FIXME9: use variable to print the fifth line*FIXED* 
    //Note: You can add more lines or print more ASCII arts of your choice if you'd like...

    cout << "\nGood bye... hit enter to exit the program: " << '\n';
    cin.ignore( 200 , '\n');
    cout << "Later \n";
    //FIXME10: make the console wait for user input

    return 0; //exit program by returning 0 status to the system
}

void append()
{
}
