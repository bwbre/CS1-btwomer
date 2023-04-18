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
int readNumber();
int checkGuess(int, int, double*, bool&);
int game(double*, bool&);
void printstats(double*);
bool playagain(bool&, double*);
void promptstats(double*);
void testcheckguess(int, int, double*, bool&);


void clearScreen() {
    // use "cls" in windows and "clear" command in Mac and Linux
    #ifdef _WIN32
        system("clS");
    #else
        system("clear");
    #endif
}


int main(int argc, char* argv[]) {
    //start of game, keeprunning is true.. after each time the game is played this will be checked.
    bool keeprunning = true;

    //array to store the stats
    //[0]=# games played, [1]=winrate, [2]=lossrate
    double stats[3] = {0, 0, 0};

    string fullname;

    cout << "Please enter your name: ";
    getline(cin, fullname);
    cout << "\nGreetings " << fullname << "!\n" << endl;
    cout << "This is the number guessing game. You will have 6 tries to guess a random number.\n\nTo begin press ENTER.";
    cin.ignore(100000, '\n');


    //if user passes test argument, test fcn will run.
    if (argc == 2 && string(argv[1]) == "test") {
        cout << "BEEP BOOP BEEP TESTING INITIATED." << endl;
        int voidnum1 = 0;
        int voidnum2 = 0;
        testcheckguess(voidnum1, voidnum2, stats, keeprunning);
        cout << "TESTING SUCCESS!\npress enter to exit." << endl;
        keeprunning = false;
        cin.ignore(1000, '\n');
    }
    
    if (keeprunning == true) {
        game(stats, keeprunning);
    }

    return 0;
}


int game(double stats[], bool &keeprunning) {
    //guessnum will store the number of guesses the user has done.
    //game ends after the 6th incorrect try.
    int guessnum = 1;

    //check will store the return value for checkGuess
    //0 means correct guess,
    //-1 means the guess < the random number
    //2 for guess > random number
    int check = 0;

    //userguess will hold the player's current guess.
    int userguess = 0;


    /*the game takes place in this loop.
        uses bool as the condition for looping.*/
    do {
        //reset current guess number var to 1
        guessnum = 1;
        clearScreen();

        //rnum will store the random number
        int rnum = randomNumber();

        //this will loop until the player wins or loses
        do {
            if (guessnum > 6) {
                clearScreen();
                cout << "\nYou're out of guesses.\nYOU LOSE!\n\n-------\nThe number was: " << rnum << "\n-------\n" << endl;
                
                //[0] # games played, [1] winrate, [2] lossrate
                stats[2]++;
                stats[0]++;

                //passes 0 -- or a correct guess -- to break the do loop.
                check = 0;

            }
            else {
                if (guessnum == 6) {
                cout << "\n\n---\nTHIS IS YOUR FINAL GUESS";
                }

                cout << "\n---\nGuess#: " << guessnum << "\n---" << endl;
                guessnum++;

                userguess = readNumber();
                // cout << "\nuserguess : " << userguess << endl;

                check = checkGuess(rnum, userguess, stats, keeprunning);
                // cout << "Checkguess: " << check << endl;
            }
        }
        while (check != 0);
        promptstats(stats);
        keeprunning = playagain(keeprunning, stats);
        
    }
    while (keeprunning == true);


    cout << "\nThank you for playing!" << endl;
    return 0;
}  



int randomNumber() {
    srand(time(0));
    int rnum = random()%20+1;
    return rnum;
}



int readNumber() {
    int userguess = 0;

    //do loop will run over and over until the user selects a valid input.
    do {
        cout << "\nPlease enter a number between 1 and 20: ";
        cin >> userguess;
        cout << endl;
        //validate the player's input is between 0-20.
        if (userguess > 0 && userguess < 21) {
            return userguess;
        }
        else {
            cout << "\nINVALID userguess.\n" << endl;
            cin.clear();
        }
    }
    while (userguess == 0);

    return userguess;
}



/* --returns: 0 if numbs are =, -1 if the first number is less than the second, 2 otherwise*/
int checkGuess(int rnum, int userguess, double stats[], bool& keeprunning) {

    //check userguess against the random number.
    if (userguess == rnum) { 
        cout << "Correct guess!\n" << endl;
        stats[0] = (stats[0]+1); //[0] # games played, [1] winrate, [2] lossrate
        stats[1] = (stats[1]+1);
        return 0;
    }
    else if (userguess > rnum) {
        cout << "Incorrect. The number is smaller than your guess, " << userguess << endl;
        return 2;
    }
    else if(userguess < rnum) {
        cout << "Incorrect. The number is larger than your guess, " << userguess << endl;
        return -1;
    }

    return 9000;
}


bool playagain(bool& keeprunning, double stats[]) {
    string selection;

    //prompt user if they want to play again
    cout << "\n\nIf you would like to play again enter Y/y: ";
    cin >> selection;

    //check user input
    if (selection == "Y" || selection == "y") {
        keeprunning = true;
    }
    else {
        keeprunning = false;
    }

    return keeprunning;
}

void printstats(double stats[]) {

    double numgames = stats[0];
    double wins = stats[1];
    double losses = stats[2];
    double lossrate = (losses / numgames)*100;
    double winrate = (wins / numgames)*100;
    cout << "STATS\n-------\nGames played: " << numgames << endl;
    cout << "Winrate: " << winrate << endl;
    cout << "Lossrate: " << lossrate << endl;
}

void promptstats(double stats[]) {
    string selection;

    //prompt if user wants to see their stats
    cout << "\n\nWould you like to see your stats? enter Y/y for yes: ";
    cin >> selection;
    cout << "\n" << endl;

    //check user input
    if (selection == "Y" || selection == "y") {
        printstats(stats);
    }
}

void testcheckguess(int rnum, int userguess, double stats[], bool& keeprunning) {
    //if checkguess == 0, the the guess and rnum are the same and it passes
    rnum = 1;
    userguess = 1;
    assert(checkGuess(rnum, userguess,stats, keeprunning) == 0);

    //if guess is == 0, the the guess and rnum are the same and it passes
    rnum = 9;
    userguess = 9;
    assert(checkGuess(rnum, userguess,stats,keeprunning) == 0);

    //if the guess is != 0, meaning the guess != rnum, then assert passes.
    rnum = 5;
    userguess = 1;
    assert(checkGuess(rnum, userguess,stats,keeprunning) != 0);




}