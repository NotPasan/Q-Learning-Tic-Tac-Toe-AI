#include "include/tictactoe.h"

    void TicTacToe::initGame(){
        player = 1;  // first player = 1, second player = -1
        turn = 0;
        render = true; 
        memset(board, 0, sizeof (board)); 
        memset(horizontalWins, 0, sizeof (horizontalWins)); 
        memset(verticalWins, 0, sizeof (verticalWins)); 
        memset(diangleWins, 0, sizeof (diangleWins)); 
    }

    bool TicTacToe:: isValidInput(int x, int y){
        if(x < 0 || x > 2 || y < 0 || y > 2 || board[x][y] != 0)
            return false;
        return true;    
    }
    int TicTacToe::play(int x, int y){
        turn++;
        board[x][y] = player; 
        if(render == true)
            printBoard();
        
        int winner = getWinner(x,y);
        if(winner != 0){
            return player;
        }
        if(turn == 9){
            return turn;
        }
        player *= -1; //switch player
        return 0;

    }
    int TicTacToe::getWinner(int x , int y){
        horizontalWins[x] += player;
        verticalWins[y] += player;
        if(abs(horizontalWins[x]) == 3 || abs(verticalWins[y]) == 3){
            return player; 
        }
        if(x==y){ //left diangol
            diangleWins[0]+= player; 
            if(abs(diangleWins[0]) == 3)
                return player;
        }
        if(2-x == y){  // right diangols
            diangleWins[1] += player; 
            if(abs(diangleWins[1]) == 3)
                return player;
        }
        return 0; 
 
    }
 
    char valToSymbol (int boardPosVal){
        if(boardPosVal == -1){
            return 'O';
        }else if(boardPosVal == 1 ){
            return 'X';
        }else{
            return '?';
        }

    }
    void TicTacToe::printBoard(){
        printf("---------------\n");
        for (int i = 0 ; i <3; i++){
            printf("%c\t%c\t%c\n", valToSymbol(board[i][0]),valToSymbol(board[i][1]) ,valToSymbol(board[i][2]));
        }
        printf("---------------\n");
    }


