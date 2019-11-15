#include "ttt_functions.h"

using namespace std;

vector<string> globalStrBoardVars = {"", "", "", "", "", "", "", "", ""};
vector<string> const globalNumBoardVars = {
    "1", "2", "3", "4", "5", "6", "7", "8", "9"};

vector<string> const &intBoard = globalNumBoardVars;
vector<string> &strBoard = globalStrBoardVars;

vector<vector<string>> const solutionComparisons = {
    {"x", "x", "x"},
    {"o", "o", "o"}};

vector<vector<string>> const actualSolutions = {
    {strBoard[0], strBoard[1], strBoard[2]},
    {strBoard[3], strBoard[4], strBoard[5]},
    {strBoard[6], strBoard[7], strBoard[8]},
    {strBoard[0], strBoard[3], strBoard[6]},
    {strBoard[1], strBoard[4], strBoard[7]},
    {strBoard[2], strBoard[5], strBoard[8]},
    {strBoard[0], strBoard[4], strBoard[8]},
    {strBoard[2], strBoard[4], strBoard[6]}};

string printResults(int x, vector<string> const nums, vector<string> const strs)
{
    locale loc;
    if (strs[x] == "")
    {
        return nums[x];
    }
    else
    {
        return strs[x];
    }
}

int random(int max_num)
{
    srand(time(NULL));

    return rand() % max_num;
}

void printBoard(vector<string> const nums, vector<string> const strs)
{

    cout << "     |     |      \n";
    cout << "  " << printResults(0, nums, strs) << "  |  " << printResults(1, nums, strs) << "  |  " << printResults(2, nums, strs) << "   \n";
    cout << "_____|_____|_____ \n";
    cout << "     |     |      \n";
    cout << "  " << printResults(3, nums, strs) << "  |  " << printResults(4, nums, strs) << "  |  " << printResults(5, nums, strs) << "   \n";
    cout << "_____|_____|_____ \n";
    cout << "     |     |      \n";
    cout << "  " << printResults(6, nums, strs) << "  |  " << printResults(7, nums, strs) << "  |  " << printResults(8, nums, strs) << "   \n";
    cout << "     |     |      \n\n";
}

void checkPlayerNumInput(int &playerCount)
{
    int test;
    cout << "Will there be 1 or 2 players? (1/2) ";
    cin >> test;
    cout << "\n";
    if (test == 1 || test == 2)
    {
        playerCount = test;
        cout << "\n";
    }
    else
    {
        cout << "please re-enter your choice, with either a 1 or a 2\n";
        checkPlayerNumInput(playerCount);
    }
}

int introduction(vector<string> const nums = intBoard, vector<string> strs = strBoard)
{
    strs = {"", "", "", "", "", "", "", "", ""};

    int players;

    cout
        << "Press [Enter] to begin: ";
    cin.ignore();

    cout << "\n";

    cout << "===========\n";
    cout << "Tic-Tac-Toe\n";
    cout << "===========\n\n";

    cout << "Player 1) x\n";
    cout << "Player 2) o\n\n";

    cout << "Here's the 3 x 3 grid:\n\n";

    printBoard(nums, strs);

    cout << "\n";

    testIntInput(players);

    return players;
}

// parameter [1] solutions should hold solutionComparisons vector, parameter [2] actual should hold actualSolutions vector, which refers to the globalStrBoardVars which are the live guesses

bool compareSolutions(vector<vector<string>> const &solutions = solutionComparisons, vector<vector<string>> const &actual = actualSolutions)
{
    for (int i = 0; i < actual.size(); i++)
    {
        if (actual[i] == solutions[0] || actual[i] == solutions[1])
        {
            return true;
        }
    };
    return false;
}

void autoTurn(vector<string> strs,int &turns)
{
    int idx = random(strs.size());
    if (strs[idx] == "")
    {
        strs[idx] = "o";
        turns++;
    }
    else
    {
        autoTurn(strs,turns);
    }
}

void chooseFirstPlayer(int &player,bool const &human){
    int temp = random(2);
    
    if (temp == 0){
        player = 1;
        cout << "Player 1 goes first!\n";
    }
    else
    {
        player = 2;
        cout << "Player 2 goes first!\n";
        if(!human){
            cout << "Computer Taking turn...\n";
        }
    }
}
void getTurnInput(int &inputChoice){
    int temp;

    cout << "Enter the Space Number that you wish to choose: (1-9) ";
    cin >> temp;
    cout << "\n";
    if (temp == 1 || temp == 2 || temp == 3 || temp == 4 || temp == 5 || temp == 6 || temp == 7 || temp == 8 || temp == 9)
    {
        inputChoice = temp;
    } else {
        cout << "Please choose a number between 1 & 9\n";
        getTurnInput(inputChoice);
    }
}

void checkTurnInput(int const &inputChoice,string const &playerStr,vector<string> strs,int &turns){
    if(strs[choice - 1] == ""){
        strs[choice - 1] = playerStr;
        turns++;
    } else {
        cout << "Please choose again, and make sure that your choice has not been taken already.\n";
        getTurnInput(inputChoice)
    }
}

void takeTurn(int &player,vector<string> strs,int &turns)
{
    int choice;
    string activeCharacter;

    if(player == 1){
        activeCharacter = "x";
    }else {
        activeCharacter = "o";
    }

    cout << "Player " << player << " - GO!\n";
    getTurnInput(choice);
    checkTurnInput(choice,activeCharacter,strs);

    if(player == 1){
        player++;
    } else{
        player--;
    }
}

void onePlayerInit(vector<string> const nums = intBoard, vector<string> strs = strBoard)
{
    int turnCounter = 0;
    bool humanPlayer = false;
    int currPlayerNumber;

    chooseFirstPlayer(currPlayerNumber,humanPlayer);
    takeTurn(currPlayerNumber,strs,turnCounter);
    if(compareSolutions()){
        string playAgain;
        cout << "You won!!!\n\nPlayer "<< currPlayerNumber << " WINS!!!\n\nDo you want to play again? (y/n) ";
        cin >> playAgain;
        if(playAgain == "y" || "Y"){
            initGame();
        }
    }
}
void twoPlayerInit(vector<string> const nums = intBoard, vector<string> strs = strBoard)
{
    int turnCounter = 0;
    bool humanPlayer = true;
    int currPlayerNumber = 1;

    chooseFirstPlayer(currPlayerNumber, humanPlayer);
}

void initGame()
{
    if (introduction() == 1)
    {
        onePlayerInit();
    }
    else
    {
        twoPlayerInit();
    }
}