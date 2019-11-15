#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;



string printResults(int x, vector<string> const nums, vector<string> const strs);
void printBoard(vector<string> const nums, vector<string> const strs);
void testIntInput(int &playerCount);
int introduction(vector<string> const nums, vector<string> strs);
void autoTurnCalc(vector<string> const nums, vector<string> const strs);
void onePlayerInit(vector<string> const &nums, vector<string> &strs);
void twoPlayerInit(vector<string> const &nums, vector<string> &strs);
bool compareSolutions(vector<vector<string>> const &solutions, vector<vector<string>> const &actual);