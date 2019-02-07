// Created by Alexis Veliz on 2019-02-06.
#include "Board.hpp"
#include <iostream>
using namespace std;

bool Board::isEmpty(int row, int col){
    if(board[row][col] == ' ')
        return true;
    return false;
}

void Board::printBoard(){
    cout<<" 0   1   2  "<<endl;

    for(int row = 0; row < 3; row ++){
        cout<<" ";
        for(int col = 0; col < 3; col++){
            if(col == 1)
                cout<<" | "<<this->board[row][col]<<" | ";

            else
                cout<< this->board[row][col];
        }
        cout<<"  "<<row<<endl;
        if(row == 2)
            cout<<"   |   |    "<<endl;

        else
            cout<<"___|___|____"<<endl;
    }
}


void Board::placeMarker(int x, int y, char symbol){
    board[x][y] =  symbol;
}

bool Board::threeInARow(char &w){
    char winner;
    /*for row */
    for(int row = 0; row < 3; row++) {
        if (board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
            if (!isEmpty(row, 0), !isEmpty(row, 1), !isEmpty(row, 2)) {
                winner = board[row][0];
                return true;
            }
        }
    }

    /* for column */
    for(int col = 0; col < 3; col++) {
        if (board[0][col] == board[1][col] && board[1][col] == board[2][col]) {
            if (!isEmpty(0, col), !isEmpty(1, col), !isEmpty(2, col)) {
                winner = board[0][col];
                return true;
            }
        }
    }

    /* for diagnonals */
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (!isEmpty(0, 0), !isEmpty(1, 1), !isEmpty(2, 2)) {
            winner = board[0][0];
            return true;
        }
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (!isEmpty(0, 2), !isEmpty(1, 1), !isEmpty(2, 0)) {
            winner = board[0][2];
            return true;
        }
    }
    /* all cases checked */

    return false;               // game not over
}


bool Board::tie(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(this->isEmpty(i, j))        //we found an empty slot, game goes on
                return false;
        }
    }

    if(!this->threeInARow())                //no empty slot, and no three in a row
        return true;                        //there is a tie
}

bool Board::threeInARow(){
    /*for row */
    for(int row = 0; row < 3; row++) {
        if (board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
            if (!isEmpty(row, 0), !isEmpty(row, 1), !isEmpty(row, 2)) {
                return true;
            }
        }
    }

    /* for column */
    for(int col = 0; col < 3; col++) {
        if (board[0][col] == board[1][col] && board[1][col] == board[2][col]) {
            if (!isEmpty(0, col), !isEmpty(1, col), !isEmpty(2, col)) {
                return true;
            }
        }
    }

    /* for diagnonals */
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (!isEmpty(0, 0), !isEmpty(1, 1), !isEmpty(2, 2)) {
            return true;
        }
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (!isEmpty(0, 2), !isEmpty(1, 1), !isEmpty(2, 0)) {
            return true;
        }
    }
    /* all cases checked */

    return false;               // game not over
}