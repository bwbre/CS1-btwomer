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

/* used in lecture as well as previous labs.*/
#ifdef _WIN32
#define clearScreen() system ("cls") // not secure!
#else
#define clearScreen() system ("clear") // not secure!
#endif


//will store temporary variables that will only be used for this round.
namespace GameData {
    string unknownword; //current word being guessed
    int numberofwords; // number of words (AKA lines) in the wordbank file
    vector<int> previouslyusedwords; //the line positions of the words in the file. will be cleared if a new file is used.

    int roundnumber; // number of rounds the player has played this session

    int wins;
    int numberofguessesstats;
    float avgguessesperwin; 
}

struct Player {
    int playernumber; //will allow multiple "SAVE FILES" by player number
    /* will be the same length as unknown word, but will start blank and each correct 
    letter that is guessed will be passed into it */
    vector<string> playerknowninfo; 
    int wordlength; // length of unknown word
    vector<string> prevguessedletters; // will hold all the previously guessed letters this round.
    int numberofincorrectguesses;
        int numberofguesses; //current number of guesses in the current game - will be referenced when checking number of player's guesses


    string playername; 
    int correctguesses;
    int incorrectguesses;

    int previouslyusedfile; //record file size in bits
};

void launchmenu(); //parent fcn for the menu at launch. Will prompt the player to load a previous save, start a new game, or exit game.
    void printmainmenu(); // will print the main launch menu
    void printloadmenu(); // will print the menu players see if they decide to load a profile
    void readsavefile(); // will check to see whether or not an existing save file is present, then grab saved profiles
    void printstats(); // will print out stats

void readfile(Player*); // the parent fcn for fetching word from file and the related info
    void checkfile(); // compare filesizes - if the current file size is not the exact same as prev used one, will reset prev. used words.
    void countfilelines(ifstream&, int&); //count the number of lines/length of file
    void getword(ifstream&); //get random word and it's size, then store both into CurrentRound namepspace - also making sure to record the line so it wont be grabbed again later
    void initplayerknowninfo(Player*); //will be the same size as the known word, but will have ' ' filling in the elements. they will be replaced with letters as the player guesses correctly.

void game(Player*);
char playerturn(Player*);
    bool checkremainingguesses(Player*); //check whether or not the player has any remaining guesses
    void checkguess(Player*); // after the player guesses a letter, test to see if it is in the unknown word.
        void scanword(Player*, char); //scan unknown word for letter that was guesses, and save the indexes for where they are located
    void updateknowninfo(Player*); // using the indexes from checkguess - the locations where the correctly guessed letter is locate - then update playerknowninfo
        bool checkforwin(Player*); // if updateknown info is completely populated -- is == to unknown word, then player wins this current round
    // void CALL PRINT-------
bool playagainprompt();

void printscreen(Player*); // will be called at the end of every turn - will clear, then update the screen
    void printstage(Player*); //print the gallows and hanging man body parts
        void getbodystatus(); // using numberofguesses in currentRound namespace to determine how many body parts should be printed - if any.
    void printblankspaces(Player*); // the spaces below the stage that show the player playerknowninfo. effectively giving player a visualization of the unknown word in reference to what they know.. ex: unknown word is "apple" - blankspaces will look like "_ p p _ E" if the player correctly guesses "p" and "e".
    void prevguessedletters(Player*); // below the blank spaces, print out all of the previously guessed letters. Allows the player to keep track of prev guesses - may help player with formulating guesses.
    
void initgamedata(Player*);
void stats();






int main(int argc, char* argv[]) {
    bool keeprunning=true;
    srand(time(0)); //declaring at start of program because it may be used more than once.
    GameData::numberofwords = 0; // start of program, set to 0 so program can iteratively add later when getting a line count.
    GameData::roundnumber = 0; // start of program, set round number to 0

    // launchmenu();
    DEBUG("start of program");
    Player *player = new Player;
    do {
    readfile(player);

    printscreen(player);
    
    
    game(player);
    keeprunning = playagainprompt();
    // DEBUG("BEFORE INIT");
    initgamedata(player);
    }
    while (keeprunning == true);

    stats();
    delete player;
    // playerturn();
}

void stats() {
    clearScreen();
    cout << "\nFun Stats: \n" << endl; 
    cout << setfill(' ') << setw(24) << "Rounds played" << GameData::roundnumber+1 << endl;
    cout << setw(24) << "Total # of Guesses" << GameData::numberofguessesstats << endl;
    cout << setw(24) << "Winrate" << float(GameData::wins)/float(GameData::roundnumber+1) << endl;
}

void initgamedata(Player* player) {
    player->numberofincorrectguesses = 0;
    // for (int i = 0; i < player->wordlength; i++){
    //     cout << "test cout bef [" << "i]: " <<  player->playerknowninfo[i] << endl;
    // }
    for (int i = player->wordlength-1; i >= 0; i--) {
        player->playerknowninfo.pop_back();
        
    }
    for (int i = 0; i < player->numberofguesses; i++) {
        player->prevguessedletters.pop_back();
    }
    // for (int i = 0; i < player->wordlength; i++){
    //     cout << "test cout afte [" << "i]: " <<  player->playerknowninfo[i] << endl;
    // }
    
    player->numberofincorrectguesses = 0;
    player->wordlength = 0;
    player->numberofguesses = 0;

}

char playerturn(Player* player) {
    string guesstmp;
    bool validinput = false;
    do {
        cout << "Enter your guess: ";
        cin >> guesstmp;
        if (guesstmp.length() > 1) {
            cout << "invalid input.. please only enter a single letter that you haven't previously guessed." << endl;
            validinput = false;
            cin.clear();
            continue;
        } 
        for (int i = 0; i < GameData::roundnumber; i++) {
            if (guesstmp == player->playerknowninfo[i] || guesstmp == player->prevguessedletters[i]){
                continue;
            }
        }
        validinput = true;
    }
    while (validinput == false);
    // cout << "Player input: " << guesstmp;
    player->numberofguesses++; //add to counter
    GameData::numberofguessesstats++;
    player->prevguessedletters.push_back(guesstmp); //save to player struct vector
    char guess = guesstmp[0];
    return guess;
} 

//after a round is finished, prompt a player whether or not they want to keep playing
bool playagainprompt() {
    string choice;
    cout << "If you would you like to play again enter Y/y";
    cin >> choice;
    if (choice == "Y" || choice == "y")
        return true; //if they prompted Y then it will return true to keeprunning bool in main()
    return false;
}

//the actual gameplay takes place here
void game(Player* player) {
    player->numberofguesses = 0;
    char guess;
    bool keeprunning = true;
    do {
        // cout << "start of turn" << endl;
        guess = playerturn(player);

        scanword(player, guess);     
        // checkforwin(); 
        printscreen(player);
        keeprunning = checkforwin(player);
    }
    while (keeprunning == true);
    cout << "end of game.." << endl;
}

// if updateknown info is completely populated -- is == to unknown word, then player wins this current round
bool checkforwin(Player* player) {
    bool win = true;
    string tmpunknown;
    string tmpplayerknown;
    bool remainingguesses;
    remainingguesses = checkremainingguesses(player);
    for (int i=0; i < player->wordlength; i++) {
        tmpunknown = GameData::unknownword[i];
        tmpplayerknown = player->playerknowninfo[i];
        if (tmpunknown != tmpplayerknown) {
            // cout << "GameData::unknownword[i] != player->playerknowninfo[i] at: " << i << " --> " << GameData::unknownword[i] << " != " << player->playerknowninfo[i] << endl;
            win = false;
        }
    }
    if (win == true) {
        cout << "\nCongratulations! you correctly guessed the word!" << endl;
        GameData::wins++;
        GameData::roundnumber++;
        return false;
    }
    if (win != true && remainingguesses !=true) {
        cout << "\nYou ran out of guesses.. better luck next time." << endl;
        GameData::roundnumber++;
        return false;
    }
    return true;
}

//scan unknown word for letter that was guesses, and update the playerknowninfo
void scanword(Player* player, char guess) {
    bool isfound = false;
    // cout << "start of scanword  " << player->wordlength << endl;
    
    for (int i=0; i < player->wordlength; i++) {
        // cout << "GameData::unknownword[" << i << "]: " << GameData::unknownword[i] << endl; 
        // cout << "test: player->playerknowninfo[i] : " << player->playerknowninfo[i] << endl;
        if (GameData::unknownword[i] == guess) {
            // cout << "correct guess here, saved to player->playerknowninfo[" << i << "]: " << player->playerknowninfo[i] << endl;
            player->playerknowninfo[i] = guess;
            // cout << "Playerknown info[" << i <<"]: " << player->playerknowninfo[i] << endl;
            isfound = true;
        }
    }
    if (isfound == false) 
        player->numberofincorrectguesses++;
}

//if player has remaining guesses returns true
bool checkremainingguesses(Player* player) {
    if (player->numberofincorrectguesses > 5) {
        return false;
    }
    return true;
}

// will be called at the end of every turn - will clear, then update the screen
void printscreen(Player* player){
    clearScreen();
    printstage(player); //print the gallows, hanging man body parts, and the number of guesses
    printblankspaces(player); // the spaces below the stage that show the player playerknowninfo. effectively giving player a visualization of the unknown word in reference to what they know.. ex: unknown word is "apple" - blankspaces will look like "_ p p _ E" if the player correctly guesses "p" and "e".
    prevguessedletters(player); // below the blank spaces, print out all of the previously guessed letters. Allows the player to keep track of prev guesses - may help player with formulating guesses.
    // DEBUG("END OF")
}

void printstage(Player* player) {
    // GameData::numberofguesses = 5;
    cout << left << "Round number: " << GameData::roundnumber+1 << endl;
    cout << setw(15) << "\nIncorrect Guesses: " << player->numberofincorrectguesses << " / 6\n" << endl;
    cout << "    ---------" << endl;
    cout << setfill(' ') << "    ||/    |" << endl;
    cout << "    ||     ";
    if (player->numberofincorrectguesses >= 1){
            cout << '0';
    }
    cout << "\n    ||    ";
    if (player->numberofincorrectguesses >= 4){
        cout << "/|\\";
    }
    else if(player->numberofincorrectguesses == 2) {
        cout << " |";
    } else if(player->numberofincorrectguesses == 3){
        cout << "/|";
    }
    cout << "\n    ||    ";
    if (player->numberofincorrectguesses == 5) {
        cout << "/";
    }
    else if (player->numberofincorrectguesses >= 6) {
        cout << "/ \\" ;
    }
    cout << "\n    ||\n    ||\n" << endl;
}

void printblankspaces(Player* player) {
    for (int i = 0; i < player->wordlength; i++) { 
        if (player->playerknowninfo[i] != " ") {
            cout << ' ' << player->playerknowninfo[i]; 
        } else {
            cout << " ?";
        }    
    }
    cout << setfill('-') << setw(15) << "\n\n" << endl;

}

void prevguessedletters(Player* player) {
    cout << "previously Guessed Letters:\n    ";
    
    for (int i=0; i < player->numberofguesses && player->numberofguesses != 0; i++ ) { 
        // cout << "num guess: " << GameData::numberofguesses << endl;
        cout << ' ' << player->prevguessedletters[i]; 
    }
    cout << endl;
}

// the parent fcn for fetching word from file and the related info
void readfile(Player* player) { 
    int filelength;
    DEBUG("start of readfile");

    ifstream fin;
    fin.open("../finalproject/files/wordbank.txt");

    // if no rounds have been played, then find file length.
    if (GameData::roundnumber == 0 ) 
        countfilelines(fin, filelength); 
    
    // checkfile(); // compare filesizes - if the current file size is not the exact same as prev used one, will reset prev. used words.
    getword(fin);     
    // DEBUG("outside countfilelines");
    initplayerknowninfo(player);     
    fin.close();
}

//will be the same size as the known word, but will have ' ' filling in the elements. they will be replaced with letters as the player guesses correctly.
void initplayerknowninfo(Player* player) {
    int wordlen = 0;
    for (int i=0; i < GameData::unknownword.length(); i++) {
        wordlen++;
        player->playerknowninfo.push_back(" ");
    }
    player->wordlength = wordlen;
}

//get random word and it's size, then store both into CurrentRound namepspace - also making sure to record the line so it wont be grabbed again later
void getword(ifstream& fin) {
    int filelength=0;

    int rnum = random()%GameData::numberofwords; // generate random number
    //if the random number line chosen is the same as any previously chosen lines and all of the words havent been used, then generate a new one.
    for (int i=0; i < GameData::roundnumber && GameData::roundnumber <= GameData::numberofwords; i++) {  
        if (rnum == GameData::previouslyusedwords[i]) {
            int rnum = random()%GameData::numberofwords;
            i=0;
        }
    }
    cout << "rnum: " << rnum << endl;
    string word;

    fin.seekg(0, fin.beg);
    for (int i = 0; i <= rnum; i++) {
        getline(fin, word);
    }
    GameData::unknownword = word;
    cout << "unknownword: " << GameData::unknownword << endl;
    GameData::previouslyusedwords.push_back(rnum);
}

//count the number of lines/length of file
void countfilelines(ifstream& fin, int& linecounter) {
    DEBUG("start of copyfilelines");
    string tmp;
    while (!fin.eof())  {
        getline(fin, tmp);
        linecounter++;
        // cout << linecounter << endl;
    }
    GameData::numberofwords = linecounter;
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
