#include "ttt_functions.h"

using namespace std;

vector<string> globalStrBoardVars = {"", "", "", "", "", "", "", "", ""};
vector<string> const globalNumBoardVars = {
    "1", "2", "3", "4", "5", "6", "7", "8", "9"
};

vector<string> const &intBoard = globalNumBoardVars;
vector<string> &strBoard = globalStrBoardVars;

vector<vector<string>> const solutionComparisons = {
    {"x", "x", "x"}, 
    {"o", "o", "o"}
};

vector<vector<string>> const actualSolutions = {
    {strBoard[0], strBoard[1], strBoard[2]}, 
    {strBoard[3], strBoard[4], strBoard[5]}, 
    {strBoard[6], strBoard[7], strBoard[8]}, 
    {strBoard[0], strBoard[3], strBoard[6]}, 
    {strBoard[1], strBoard[4], strBoard[7]}, 
    {strBoard[2], strBoard[5], strBoard[8]}, 
    {strBoard[0], strBoard[4], strBoard[8]}, 
    {strBoard[2], strBoard[4], strBoard[6]}
};

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

void printBoard(vector<string> const nums, vector<string> const strs)
{

    std::cout << "     |     |      \n";
    std::cout << "  " << printResults(0, nums, strs) << "  |  " << printResults(1, nums, strs) << "  |  " << printResults(2, nums, strs) << "   \n";
    std::cout << "_____|_____|_____ \n";
    std::cout << "     |     |      \n";
    std::cout << "  " << printResults(3, nums, strs) << "  |  " << printResults(4, nums, strs) << "  |  " << printResults(5, nums, strs) << "   \n";
    std::cout << "_____|_____|_____ \n";
    std::cout << "     |     |      \n";
    std::cout << "  " << printResults(6, nums, strs) << "  |  " << printResults(7, nums, strs) << "  |  " << printResults(8, nums, strs) << "   \n";
    std::cout << "     |     |      \n\n";
}

void introduction(vector<string> const nums = intBoard, vector<string> strs = strBoard)
{
    strs = {"","","","","","","","",""};

    std::cout
        << "Press [Enter] to begin: ";
    std::cin.ignore();

    std::cout << "\n";

    std::cout << "===========\n";
    std::cout << "Tic-Tac-Toe\n";
    std::cout << "===========\n\n";

    std::cout << "Player 1) X\n";
    std::cout << "Player 2) O\n\n";

    std::cout << "Here's the 3 x 3 grid:\n\n";

    printBoard(nums, strs);
}

// parameter [1] solutions should hold solutionComparisons vector, parameter [2] actual should hold actualSolutions vector, which refers to the globalStrBoardVars which are the live guesses

// bool compareSolutions(vector<vector<string>> const &solutions, vector<vector<string>> const &actual)
// {
//     for (int i = 0; i < actual.size();i++){
//         if (actual[i] == solutions[0] || actual[i] == solutions[1]){
//             return true;
//         }
//     };
//     return false;
// };
