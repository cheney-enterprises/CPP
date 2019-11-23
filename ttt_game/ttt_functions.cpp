#include "ttt_functions.h"

using namespace std;

string ttt_game::printResults(int x)
{
    
    if (strs[x] == "")
    {
        return nums[x];
    }
    else
    {
        return strs[x];
    }
}

int ttt_game::random(int max_num)
{
    //srand(time(rand() % 10000));
    return rand() % max_num;
}

void ttt_game::printBoard()
{
    
    cout << "     |     |      \n";
    cout << "  " << printResults(0) << "  |  " << printResults(1) << "  |  " << printResults(2) << "   \n";
    cout << "_____|_____|_____ \n";
    cout << "     |     |      \n";
    cout << "  " << printResults(3) << "  |  " << printResults(4) << "  |  " << printResults(5) << "   \n";
    cout << "_____|_____|_____ \n";
    cout << "     |     |      \n";
    cout << "  " << printResults(6) << "  |  " << printResults(7) << "  |  " << printResults(8) << "   \n";
    cout << "     |     |      \n\n";
}

void ttt_game::checkPlayerNumInput()
{
    int temp;
    cout << "Will there be 1 or 2 players? (1/2) ";
    cin >> temp;
    cout << "\n";
    if (temp == 1 || temp == 2)
    {
        playerCount = temp;

        if(temp == 2){
            isHuman = true;
        }

        cout << "\n";
    }
    else
    {
        cout << "please re-enter your choice, with either a 1 or a 2\n";
        checkPlayerNumInput();
    }
}

int ttt_game::introduction()
{
    strs = {"", "", "", "", "", "", "", "", ""};
    playerCount = 0;
    turnsTakenCounter = 0;
    currPlayer = 0;
    isHuman = false;
    activeCharacter = "";
    currChoice = 0;

    cout
        << "Press [Enter] to begin: ";
    cin.ignore();

    cout << "\n";

    cout << "===========\n";
    cout << "Tic-Tac-Toe\n";
    cout << "===========\n\n";

    cout << "Player 1) X\n";
    cout << "Player 2) O\n\n";

    cout << "Here's the 3 x 3 grid:\n\n";

    printBoard();

    cout << "\n";

    checkPlayerNumInput();

    return playerCount;
}

bool ttt_game::compareSolutions()
{
    vector<vector<string>> currSolutions = {
        {strs[0], strs[1], strs[2]},
        {strs[3], strs[4], strs[5]},
        {strs[6], strs[7], strs[8]},
        {strs[0], strs[3], strs[6]},
        {strs[1], strs[4], strs[7]},
        {strs[2], strs[5], strs[8]},
        {strs[0], strs[4], strs[8]},
        {strs[2], strs[4], strs[6]}};
    for (int i = 0; i < currSolutions.size(); i++)
    {
        if (currSolutions[i] == possSolutions[0] || currSolutions[i] == possSolutions[1])
        {
            return true;
        }
    }
    return false;
}

void ttt_game::autoTurn()
{
    srand(time(0));

    int idx = random(strs.size());
    if (strs[idx] == "")
    {
        if(turnsTakenCounter > 0){
            cout << "Computer is taking turn...\n";
        }
        strs[idx] = "O";
        turnsTakenCounter++;
    }
    else
    {
        autoTurn();
    }
}

void ttt_game::chooseFirstPlayer(){
    int temp = random(2);
    
    if (temp == 0){
        currPlayer = 1;
        cout << "Player 1 goes first!\n\n";
    }
    else
    {
        currPlayer = 2;
        cout << "Player 2 goes first!\n\n";
        if(!isHuman){
            cout << "Computer Taking turn...\n\n";
            
        }
    }

}

void ttt_game::getTurnInput(){
    int temp;

    cout << "Enter the Space Number that you wish to choose: (1-9) ";
    cin >> temp;
    cout << "\n";
    if (temp == 1 || temp == 2 || temp == 3 || temp == 4 || temp == 5 || temp == 6 || temp == 7 || temp == 8 || temp == 9)
    {
        currChoice = temp;
    }
    else
    {
        cout << "Please choose a number between 1 & 9\n";
        getTurnInput();
    }
}

void ttt_game::checkTurnInput(){
    if(strs[currChoice - 1] == ""){
        strs[currChoice - 1] = activeCharacter;
        turnsTakenCounter++;
    } else {
        cout << "Please choose again, and make sure that your choice has not been taken already.\n";
        getTurnInput();
    }
}

void ttt_game::takeTurn(string x)
{
    activeCharacter = x;
    
    printBoard();

    cout << "Player " << currPlayer << " - GO!\n";
    getTurnInput();
    checkTurnInput();

    printBoard();
}

void ttt_game::onePlayerInit()
{

    chooseFirstPlayer();
    
    while(turnsTakenCounter < 9){
        if(currPlayer == 1){
            takeTurn("X");
            if(compareSolutions()){
                printBoard();
                string playAgain;
                cout << "You won!!!\n\nPlayer 1 WINS!!!\n\nDo you want to play again? (y/n) ";
                cin >> playAgain;
                if(playAgain == "y" || playAgain == "Y"){
                    initGame();
                } else { return; }
            }
            currPlayer++;
        cout << "Next Player's Turn! \n";
        autoTurn();
        if(compareSolutions()){
                printBoard();
                string playAgain;
                cout << "Oh No! The Computer won!!!\n\nDo you want to play again? (y/n) ";
                cin >> playAgain;
                if(playAgain == "y" || playAgain == "Y"){
                    initGame();
                } else { return; }
            }
            currPlayer--;
        } else {
            autoTurn();
            if(compareSolutions()){
                printBoard();
                string playAgain;
                cout << "Oh No! The Computer won!!!\n\nDo you want to play again? (y/n) ";
                cin >> playAgain;
                if(playAgain == "y" || playAgain == "Y"){
                    initGame();
                } else { return; }
            }
            currPlayer--;
            takeTurn("X");
            if(compareSolutions()){
                printBoard();
                string playAgain;
                cout << "You won!!!\n\nPlayer 1 WINS!!!\n\nDo you want to play again? (y/n) ";
                cin >> playAgain;
                if(playAgain == "y" || playAgain == "Y"){
                    initGame();
                } else { return; }
            }
            currPlayer++;

        }
    }
    if(turnsTakenCounter == 9){
            string playAgain;
            cout << "It was a DRAW!\nDo you want to play again? (y/n) ";
            cin >> playAgain;
            if(playAgain == "y" || playAgain == "Y"){
                initGame();
            } else {
                return;
            }
        }
}

void ttt_game::twoPlayerInit()
{
    chooseFirstPlayer();
    while(turnsTakenCounter < 9){
    
    if(currPlayer == 1){
        takeTurn("X");
        if(compareSolutions()){
                printBoard();
                string playAgain;
                cout << "You won!!!\n\nPlayer 1 WINS!!!\n\nDo you want to play again? (y/n) ";
                cin >> playAgain;
                if(playAgain == "y" || playAgain == "Y"){
                    initGame();
                } else { return; }
            }
            currPlayer++;
        takeTurn("O");
        if(compareSolutions()){
                printBoard();
                string playAgain;
                cout << "You won!!!\n\nPlayer 2 WINS!!!\n\nDo you want to play again? (y/n) ";
                cin >> playAgain;
                if(playAgain == "y" || playAgain == "Y"){
                    initGame();
                } else { return; }
            }
            currPlayer--;
    } else {
        takeTurn("O");
        if(compareSolutions()){
                printBoard();
                string playAgain;
                cout << "You won!!!\n\nPlayer 2 WINS!!!\n\nDo you want to play again? (y/n) ";
                cin >> playAgain;
                if(playAgain == "y" || playAgain == "Y"){
                    initGame();
                } else { return; }
            }
        currPlayer--;
        takeTurn("X");
        if(compareSolutions()){
                printBoard();
                string playAgain;
                cout << "You won!!!\n\nPlayer 1 WINS!!!\n\nDo you want to play again? (y/n) ";
                cin >> playAgain;
                if(playAgain == "y" || playAgain == "Y"){
                    initGame();
                } else { return; }
            }
        currPlayer++;
    }}
    if(turnsTakenCounter == 9){
            string playAgain;
            cout << "It was a DRAW!\nDo you want to play again? (y/n) ";
            cin >> playAgain;
            if(playAgain == "y" || playAgain == "Y"){
                initGame();
            } 
        
    }
}

void ttt_game::initGame()
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
