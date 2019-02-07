// Created by Alexis Veliz on 2019-02-06.
#ifndef TICTACTOE_BOARD_HPP
#define TICTACTOE_BOARD_HPP
#endif //TICTACTOE_BOARD_HPP

class Board{
public:
    Board(){
        for(int row = 0; row < 3; row ++){
            for(int col = 0; col < 3; col++)
                this->board[row][col] = ' ';
        }
    }


    void printBoard();
    bool isEmpty(int row, int col);
    void placeMarker(int x, int y, char s);
    bool threeInARow(char &w);
    bool threeInARow();
    bool tie();

private:
    char board[3][3];
};
