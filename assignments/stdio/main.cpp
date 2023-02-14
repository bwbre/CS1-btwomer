/*name: Brendan Womer
HW1 std-io assignment.
today we will be drawing the stages of the gallows for a hang man game. I will ask the user for their name, then draw each stage
the stage title/number above.
*/

#include <iostream>

using namespace std;

int main(){

    string firstName;
    string lastName;

    cout << "Hello and welcome to the early stages of my hangman game.\n\nPlease enter your name: ";
    getline( cin, (firstName, lastName)); //greet user and prompt for name

    cout << "Hello " << firstName << " " << lastName << "\n\n"; 


//These are the variables that each stage is saved to.
    string stage1 = "Stage 1\n\n     |-----------------\n     |/        |\n     |\n     |\n     |\n     |\n     |\n ===========\n";
    string stage2 = "Stage 2\n\n     |-----------------\n     |/        |\n     |         O\n     |\n     |\n     |\n     |\n ===========\n";
    string stage3 = "stage 3\n\n     |-----------------\n     |/        |\n     |         O\n     |         |\n     |\n     |\n     |\n ===========\n";
    string stage4 = "stage 4\n\n     |-----------------\n     |/        |\n     |         O\n     |        /|\n     |\n     |\n     |\n ===========\n";
    string stage5 = "stage 5\n\n     |-----------------\n     |/        |\n     |         O\n     |        /|\\\n     |\n     |          \n     |\n ===========\n";
    string stage6 = "stage 6\n\n     |-----------------\n     |/        |\n     |         O\n     |        /|\\\n     |        /\n     |          \n     |\n ===========\n";
    string stage7 = "stage 7\n\n     |-----------------\n     |/        |\n     |         O\n     |        /|\\\n     |        / \\\n     |          \n     |\n ===========\n";

//the stages is then drawn 
    cout << stage1 << endl;
    cout << stage2 << endl;
    cout << stage3 << endl;
    cout << stage4 << endl;
    cout << stage5 << endl;
    cout << stage6 << endl;
    cout << stage7 << endl;

//program wont end until user presses enter to exit the program.
    cout << "please press enter to exit.";
    cin.ignore(0, '\n');

}