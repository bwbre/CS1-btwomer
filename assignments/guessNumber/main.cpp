/*
Brendan Womer
4/2/2023
HW-5 Guess the Number

1.ask player name then greet.
2. define function randomNumber (between 1 and 20)
3.define function readNumber to read player inputs (validate its between 1 and 20)
4.Define a function called checkGuess (returns: 0 if numbs are =, -1 if the first number is lass than the second, 2 otherwise)
5.3 test cases for checkGuess
6.define function called game
    -- user randomNumber to define a number for each game
    -- until game is over program will ask the player to guess using readNumber
    -- use checkGuess to compare user numbers with the random number
    -- player only wins if they guess the number in 6 tries.
    -- for every wrong guess, program will inform player whether their guess was too high or too low.
7.when game is over, program will inform whether win or lost and reveal secret number.
8.will continue to run until user wants to quit(when game is over)
Bonus: when user quits, program will provide stats of player
    -- # games played
    -- % of times won
    -- % of losses
*/


#include <iostream>
#include <cmath>
#include <cassert>
#include <random>

using namespace std;

int randomNumber();
int readNumber(int*);
int checkGuess(int, int);
int game(int*);

int main(int argc, char* argv[]) {
    //array to store the stats
    //[0] # games played, [1] winrate, [2] lossrate
    int stats[3] = {0, 0, 0};
    string fullname;
    srand(time(0));
    // cout << "Please enter your name: ";
    // getline(cin, fullname);
    // cout << "Greetings " << fullname << "!\n" << endl;

    

    game(stats);


    return 0;
}


int game(int *stats) {
    //guessnum will store the number of guesses the user has done.
    //game ends after the 6th incorrect try.
    int guessnum = 0;


    //check will store the return value for checkGuess
    //0 means correct guess,
    //-1 means the guess < the random number
    //2 for guess > random number
    int check = 0;


    //selection will hold the player's current guess.
    int selection=0;


    //will add one to the number of games played.
    // cout << "\nstats[0]: " << stats[0] << endl;
    stats[0] = (stats[0]+1);
    // cout << "\nstats[0]: " << stats[0] << endl;

    //rnum will store the random number
    int rnum = randomNumber();
    cout << "\nrnum: " << rnum << endl;

    //the game takes place in this loop.
    //will continue to loop until a correct guess.
    do {
        cout << "\nGuess#: " << guessnum << "\n" << endl;
        
        if (guessnum ==7) {
            cout << "Sorry, you're out of guesses. The number was: " << rnum << "\n" << endl;
            break;
        }

        guessnum++;

        selection = readNumber(stats);
        // cout << "\nselection : " << selection << endl;

        check = checkGuess(rnum, selection);
        // cout << "Checkguess: " << check << endl;
    }
    while (check != 0);

    cout << "game has ended." << endl;

    return 0;
}  

int randomNumber() {
    int rnum = random()%20+1;
    cout << "rnum: " << rnum << endl;

    return rnum;
}

int readNumber(int *stats) {
    int selection = 0;

    //do loop will run over and over until the user selects a valid input.
    do {
        cout << "Please enter a number between 1 and 20: ";
        cin >> selection; 
        cout << endl;

        //validate the player's input is between 0-20.
        if (selection > 0 && selection < 21) {
            // cout << "\nDEBUG: valid\n";
            // cout << "DEBUG: SELECTION: " << selection << endl;
            return selection;
        }
        else {
            cout << "\nINVALID SELECTION.\n" << endl;
            selection = 0;
            cin.clear();
        }
    }
    while (selection == 0);

    return 2020;
}


//returns: 0 if numbs are =, -1 if the first number is less than the second, 2 otherwise
int checkGuess(int rnum, int selection) {

    //check selection against the random number.
    if (selection == rnum) { 
        cout << "Correct guess!\n" << endl;
        return 0;
    }
    else if (selection > rnum) {
        cout << "Incorrect. The number is smaller than your guess, " << selection << endl;
        return 2;
    }
    else if(selection < rnum) {
        cout << "Incorrect. The number is larger than your guess, " << selection << endl;
        return -1;
    }


    return 9000;
}