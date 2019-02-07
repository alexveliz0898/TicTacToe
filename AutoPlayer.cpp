// Created by Alexis Veliz on 2019-02-07.
#include "AutoPlayer.hpp"
#include <vector>

AutoMove AutoPlayer::minMax(Board& game, char s){
    /* base cases */
    if(game.tie())
        return AutoMove(0);

    char w;
    if(game.threeInARow(w)){
        if(w == 'O')
            return AutoMove(10);
        else
            return AutoMove(-10);
    }

    std::vector<AutoMove> move_set;

    /* iterate through all the slots to find and empty slot */
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(game.isEmpty(i,j)){                               //if an empty slot is found, construct a Move object
                AutoMove move;
                move.x = i;
                move.y = j;
                game.placeMarker(i, j, s);

                if(s == 'O'){                                   //computer just made a move, check the human's best possible move
                    move.score = minMax(game, 'X').score;
                }
                /* human just went, check the AI's best possible move */
                else{
                    move.score = minMax(game, 'O').score;       //computers best possible move
                }

                move_set.push_back(move);
                game.placeMarker(i, j, ' ');                    //end of recursion, reset the board the way it was
            }

        }
    }

    int bestMove = 0;
    if('O' == s){
        int bestScore = -100000;
        for(int i = 0; i < move_set.size(); i++){
            if(move_set[i].score > bestScore){
                bestMove = i;
                bestScore = move_set[i].score;
            }
        }
    }
    else{
        int bestScore= 100000;
        for(int i = 0; i < move_set.size(); i++){
            if(move_set[i].score < bestScore){
                bestMove = i;
                bestScore = move_set[i].score;
            }
        }
    }


    return move_set[bestMove];
}