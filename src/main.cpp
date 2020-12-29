#include<iostream>
#include<string>
#include "include/tictactoe.h"

int main(){
    char buffer[100];
    TicTacToe game;
    game.initGame();
    int x,y,win,turn = 0;
    game.printBoard();
    
    while(turn <9 ){
        turn++;
        printf("Enter x,y: ");
        fgets(buffer, 100, stdin);
        sscanf(buffer,"%d %d", &x,&y);
        while(game.isValidInput(x,y) != true){
            printf("Invalid Input, Enter again: (x,y)");
            fgets(buffer, 100, stdin);
            printf("%s", buffer);
            sscanf(buffer,"%d,%d", &x,&y);

        }
        win = game.play(x,y);

        if (win != 0){
            switch(win){
                case -1:
                    printf("You Lose!\n");
                    break;
                case 1:
                    printf("You Win!\n");
                    break;
                case 9:
                    printf("You Tied!\n");
                    break;
            }
            break;
        }
    }
    return 0; 
    
}