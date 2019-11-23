#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;


class ttt_game {
    private :    

    //class-wide private vectors setup

    vector<string> strs = {"", "", "", "", "", "", "", "", ""};
    vector<string> nums = {
    "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    vector<vector<string>> const possSolutions = {
        {"x", "x", "x"},
        {"o", "o", "o"}};
    

    // pre-declared references to the class-wide private vectors declared above - this was done to ensure that references are passed in all of the class functions without errors in passing references to references, etc.;

    // vector<string> &nums = globalNumBoardVars;
    // vector<string> &strs = globalStrBoardVars;
    // vector<vector<string>> &possSolutions = solutionComparisons;
    // vector<vector<string>> &currSolutions = actualSolutions;

    // function variables for access to all class functions

    int playerCount;
    int turnsTakenCounter;
    int currPlayer;
    bool isHuman;
    string activeCharacter;
    int currChoice;


    // references to function variables
    string printResults(int x);
    int random(int max_num);
    void printBoard();
    void checkPlayerNumInput();
    int introduction();
    bool compareSolutions();
    void autoTurn();
    void chooseFirstPlayer();
    void getTurnInput();
    void checkTurnInput();
    void takeTurn(string x);
    void onePlayerInit();
    void twoPlayerInit();

    public:
        void initGame();
};
