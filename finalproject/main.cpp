/*
Hangman

Brendan Womer
05/17/2023




Design and develop a single player game of Hangman - https://en.wikipedia.org/wiki/Hangman_(game)  in C++.
Create a folder called finalproject
1.  Write programmer and program information as comments at the top of the program file.
2.  Create a text file called words.txt and include at least 20 English dictionary-based words. (5 points)
3.  The program will read the list of words from the file into an array or vector data structure. (5 points)
4.  Program chooses a random word from the array and starts asking the player to guess the word one character at a time until the player wins or runs out of predefined number of tries. (50 points)
5.  Game continues until the player wants to quit. (10 points)
6.  Include as many "bells and whistles" as possible to make the game entertaining and intuitive to play. (10 points)
7.  Use as many functions as possible to break the problem into many subproblems (5 points)
8.  Use header files and cpp files to break the code into multiple files (5 points)
9.  Create a Makefile inside the finalproject folder (5 points)
10. Submit screenshot showing your program working to D2L. (5 points)

Struct player
    -struct#
    -name
    -previously used words
    -correct guesses
    -incorrect guesses
    -previously used words
    -winrate
    -average number of guesses per wins.
    -previously used file

Start of game----
    -prompt player if they want to create a new user profile or load an old profile
        -IF they want to load ---> Load 
        -Else ---> create new player struct

void launchmenu(); //parent fcn for the menu at launch. Will prompt the player to load a previous save, start a new game, or exit game.
    void printmenu(); // will print the main launch menu
    void printloadmenu(); // will print the menu players see if they decide to load a profile
    void printstats(); // will print out stats

read list of words into vector
    --check for changes to word file
    --find number of words (aka lines) in file to be used later
    --choose a random word
        --record the lines/words that have already been guessed so the player wont see the same words over and over
    --read word to vector
--choose random word and store to array --- namespace?
    -vector<string> word bank in -- namespace?
    --store word into locally scoped "reference word" string
            --get length
            --using length, create a blank "playerknowninfo" string array with the same length that will be populated with letters from correct guesses
                * once this is full, player has guessed all the correct letters
                * will also be used to fill in the spaces at the bottom with their respective position in the playerknowninfo char arr

*************
void readfile(); // the parent fcn for fetching word from file and the related info
    void checkfile(); // compare filesizes - if the current file size is not the exact same as prev used one, will reset prev. used words.
    void countfilelines(); 
    void getword(); //get random word and it's size, then store both into CurrentRound namepspace - also making sure to record the line so it wont be grabbed again later
    void initplayerknowninfo(); //will be the same size as the known word, but will have ' ' filling in the elements. they will be replaced with letters as the player guesses correctly.

************



--ask player to guess the word one character at a time.
    --LOOP count the number of guesses and check whether or not they exceed the allowed
        --check whether the letter has already been guesses
        --search word for letter
            --IF correct guess, save indexes for the locations that contain the letters
                --using indexes, fill in the blank spaces for the guessed wor for the corresponding 
        --delete letter from string array if correct guess
            --using the saved indexes of letters that were guessed correctly
            --clear tmp letter indexes so it can be re used next guess
        --once the string array is empty, player has guessed all the correct letter.
        --re-print the screen

void playerturn();
    void checkremainingguesses(); //check whether or not the player has any remaining guesses
    void checkguess(); // after the player guesses a letter, test to see if it is in the unknown word.
        void scanword(); //scan unknown word for letter that was guesses, and save the indexes for where they are located
    void updateknowninfo(); // using the indexes from checkguess - the locations where the correctly guessed letter is locate - then update playerknowninfo
        void checkforwin(); // if updateknown info is completely populated -- is == to unknown word, then player wins this current round
    void CALL PRINT-------

void printscreen(); // will be called at the end of every turn - will clear, then update the screen
    void clearscreen(); // simple clear screen fcn.
    void printstage();
        void getbodystatus(); // using numberofguesses in currentRound namespace to determine how many body parts should be printed - if any.
    void printblankspaces(); // the spaces below the stage that show the player playerknowninfo. effectively giving player a visualization of the unknown word in reference to what they know.. ex: unknown word is "apple" - blankspaces will look like "_ p p _ E" if the player correctly guesses "p" and "e".
    print prevguessedletters(); // below the blank spaces, print out all of the previously guessed letters. Allows the player to keep track of prev guesses - may help player with formulating guesses.
    



--print screen
    --print stage
        --use a fcn to return what body parts are printed based on incorrect guesses.
    --print blank spaces below stage
        --using length, create a blank spaces matching "playerknowninfo" size
                * once this is full, player has guessed all the correct letters
        --fill spaces for the correct letters that were guessed.
    --print previous guesses below everything to help player track previous guesses.
*/





#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

#define DEBUG(s) cout << s << endl;

using namespace std;


//will store temporary variables that will only be used for this round.
namespace GameData {
    vector<string> unknownword; //current word being guessed
    int numberofwords; // number of words (AKA lines) in the wordbank file
    /* will be the same length as unknown word, but will start blank and each correct 
    letter that is guessed will be passed into it */
    vector<string> playerknowninfo; 

    vector<string> prevguessedletters; // will hold all the previously guessed letters this round.

    int roundnumber; // number of rounds the player has played this session
    int wordlength; //length of the word being actively used
    int numberofguesses; //current number of guesses in the current game - will be referenced when checking number of player's guesses
}

struct Player {
    int playernumber; //will allow multiple "SAVE FILES" by player number
    string playername; 
    vector<int> previouslyusedwords; //the line positions of the words in the file. will be cleared if a new file is used.
    int correctguesses;
    int incorrectguesses;
    float winrate;
    float avgguessesperwin; 
    int previouslyusedfile; //record file size in bits
};

void launchmenu(); //parent fcn for the menu at launch. Will prompt the player to load a previous save, start a new game, or exit game.
    void printmainmenu(); // will print the main launch menu
    void printloadmenu(); // will print the menu players see if they decide to load a profile
    void readsavefile(); // will check to see whether or not an existing save file is present, then grab saved profiles
    void printstats(); // will print out stats

void readfile(); // the parent fcn for fetching word from file and the related info
    void checkfile(); // compare filesizes - if the current file size is not the exact same as prev used one, will reset prev. used words.
    void countfilelines(ifstream&); //count the number of lines/length of file
    void getword(ifstream&); //get random word and it's size, then store both into CurrentRound namepspace - also making sure to record the line so it wont be grabbed again later
    void initplayerknowninfo(); //will be the same size as the known word, but will have ' ' filling in the elements. they will be replaced with letters as the player guesses correctly.

void playerturn();
    void checkremainingguesses(); //check whether or not the player has any remaining guesses
    void checkguess(); // after the player guesses a letter, test to see if it is in the unknown word.
        void scanword(); //scan unknown word for letter that was guesses, and save the indexes for where they are located
    void updateknowninfo(); // using the indexes from checkguess - the locations where the correctly guessed letter is locate - then update playerknowninfo
        void checkforwin(); // if updateknown info is completely populated -- is == to unknown word, then player wins this current round
    // void CALL PRINT-------

void printscreen(); // will be called at the end of every turn - will clear, then update the screen
    void clearscreen(); // simple clear screen fcn.
    void printstage(); //print the gallows and hanging man body parts
        void getbodystatus(); // using numberofguesses in currentRound namespace to determine how many body parts should be printed - if any.
    void printblankspaces(); // the spaces below the stage that show the player playerknowninfo. effectively giving player a visualization of the unknown word in reference to what they know.. ex: unknown word is "apple" - blankspaces will look like "_ p p _ E" if the player correctly guesses "p" and "e".
    void prevguessedletters(); // below the blank spaces, print out all of the previously guessed letters. Allows the player to keep track of prev guesses - may help player with formulating guesses.
    






int main(int argc, char* argv[]) {
    srand(time(0)); //declaring at start of program because it may be used more than once.
    GameData::numberofwords = 0; // start of program, set to 0 so program can iteratively add later when getting a line count.
    GameData::roundnumber = 0; // start of program, set round number to 0
    // launchmenu();
    DEBUG("start of program");


    readfile();
    // delete Player;
    // playerturn();
}

// the parent fcn for fetching word from file and the related info
void readfile() { 
    DEBUG("start of readfile");

    ifstream fin;
    fin.open("../finalproject/files/wordbank.txt");

    // checkfile(); // compare filesizes - if the current file size is not the exact same as prev used one, will reset prev. used words.
    countfilelines(fin); //count the number of lines/length of file
         
    // initplayerknowninfo(); //will be the same size as the known word, but will have ' ' filling in the elements. they will be replaced with letters as the player guesses correctly.
    DEBUG("outside countfilelines");
    // DEBUG(linecounter);
    fin.close();
}


//get random word and it's size, then store both into CurrentRound namepspace - also making sure to record the line so it wont be grabbed again later
void getword(ifstream& fin) {
    if (GameData::roundnumber = 0 ) countfilelines(fin); // if no rounds have been played -- the first round, then find file length.

    int rnum = random()%GameData::numberofwords;
    cout << "rnum: " << rnum << endl;
    string word;
    fin.seekg(0, fin.beg);
    cout << "fin tell" << fin.tellg() << endl;
    
    while (getline(fin, word)) {
        // if (tmp[linecounter == rnum]) 
        cout << word << endl;
    }

    cout << "word " << word << endl;
}

void countfilelines(ifstream& fin, int& linecounter) {
    DEBUG("start of copyfilelines");
    string tmp[linecounter];
    while (getline(fin, tmp))  {
        linecounter++;
        cout << linecounter << endl;
    }
}

// void checkfile(iftstream fin) {
//     fin.open("/finalproject/files/wordbank" ; ios_base::binary);
//     if (tellg() == fin.eof()) {

//     }
//     fin.open()
// }

// void launchmenu() {
//     printmenu();
// }
// void printmainmenu() {
//     cout << "Welcome to Brendan's Hangman Game!" << endl;
//     cout << setfill('=') << setw(60) << endl;
//     cout << setfill(' ') << setw(30) << left << "Please select one of the following options:" << endl;
//     cout << "1. New Game\n"
//         << "2. Load Game\n"
//         << "3. Player Stats\n"
//         << "4. Exit Game" << endl;
// }
// void printloadmenu() {
//     cout << setfill(' ') << setw(30) << left << "Please select one of the following options:" << endl;
//     ifstream fin;
//     stringstream ss;
//     fin.open("/finalproject/files/savefile.txt");
//     while (getline(fin, ss)) {    
//     }
// }
