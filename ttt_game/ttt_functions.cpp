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

void testIntInput(int &playerCount)
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
        testIntInput(playerCount);
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

void autoTurnCalc(vector<string> strs,int &turns)
{
    int idx = random(strs.size());
    if (strs[idx] == "")
    {
        strs[idx] = "o";
    }
    else
    {
        autoTurnCalc(strs,turns);
    }
}

void onePlayerInit(vector<string> const nums = intBoard, vector<string> strs = strBoard)
{
    int turnCounter = 0;
}
void twoPlayerInit(vector<string> const nums = intBoard, vector<string> strs = strBoard)
{
    int turnCounter = 0;
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