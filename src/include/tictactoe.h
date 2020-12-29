#include <cmath>       
#include <cstdio>
#include <cstring>
class TicTacToe{    
    private:
        int player;
        int turn;
        int board[3][3];
        int horizontalWins[3];
        int verticalWins[3];
        int diangleWins[2];
    public:
        bool render; 
        bool  isValidInput(int x,int y);
        void initGame();
        int play(int x, int y);
        int getWinner(int x , int y);
        void printBoard();

};