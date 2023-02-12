/*name: Brendan Womer
This is my HW1 std-io assignment. today we will be drawing the visual stages of the gallows for a hang man game.
*/

#include <iostream>

using namespace std;

int main(){

    string firstName;
    string lastName;

    cout << "Hello and welcome to the early stages of my hangman game.\n\nPlease enter your first and last name separated by spaces: ";
    getline( cin, (firstName, lastName)); /* there has to be a better way of doing this, requiring spaces is awkward*/

    cout << "Hello " << firstName << " " << lastName << "\n\n";

    string stage1 = "Stage 1\n\n     |-----------------\n     |/        |\n     |\n     |\n     |\n     |\n     |\n ===========\n";
    string stage2 = "Stage 2\n\n     |-----------------\n     |/        |\n     |         O\n     |\n     |\n     |\n     |\n ===========\n";
    string stage3 = "stage 3\n\n     |-----------------\n     |/        |\n     |         O\n     |         |\n     |\n     |\n     |\n ===========\n";
    string stage4 = "stage 4\n\n     |-----------------\n     |/        |\n     |         O\n     |        /|\n     |\n     |\n     |\n ===========\n";
    string stage5 = "stage 5\n\n     |-----------------\n     |/        |\n     |         O\n     |        /|\\\n     |\n     |          \n     |\n ===========\n";
    string stage6 = "stage 6\n\n     |-----------------\n     |/        |\n     |         O\n     |        /|\\\n     |        /\n     |          \n     |\n ===========\n";
    string stage7 = "stage 7\n\n     |-----------------\n     |/        |\n     |         O\n     |        /|\\\n     |        / \\\n     |          \n     |\n ===========\n";




    cout << stage1 << endl;
    cout << stage2 << endl;
    cout << stage3 << endl;
    cout << stage4 << endl;
    cout << stage5 << endl;
    cout << stage6 << endl;
    cout << stage7 << endl;





}