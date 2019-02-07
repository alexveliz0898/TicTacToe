// Created by Alexis Veliz on 2019-02-06.
#ifndef TICTACTOE_PLAYER_HPP
#define TICTACTOE_PLAYER_HPP
#endif //TICTACTOE_PLAYER_HPP
#include <iostream>
#include <string>
using namespace std;

class Player{
private:
    string name;
    char symbol = 'X';

public:
    Player(string Name):name(Name){};
    Player(){
        name = "Ai";
    }

    void getDst(int &x, int &y);
    bool parseMove(const string dst, int &x, int &y);
    char getSymbol(){ return this->symbol; }

};

