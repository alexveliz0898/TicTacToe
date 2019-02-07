// Created by Alexis Veliz on 2019-02-07.
#ifndef TICTACTOE_AUTOPLAYER_HPP
#define TICTACTOE_AUTOPLAYER_HPP
#endif //TICTACTOE_AUTOPLAYER_HPP
#include "Board.hpp"
#include <string>
//#include "Player.hpp"

struct AutoMove{
    AutoMove():score(0){}

    AutoMove(int Score): score(Score){}

    int x;
    int y;
    int score;
};

class AutoPlayer{
public:
    AutoPlayer(){
        name = "Computer";
    }

    void getBestMove(Board& game){
        AutoMove best;
        best = minMax(game, 'O');
        game.placeMarker(best.x, best.y, 'O');
    }



private:
    AutoMove minMax(Board& game, char s);

    std::string name;
    char symbol = 'O';
};