// Created by Alexis Veliz on 2019-02-06.
#include "Player.hpp"

void Player::getDst(int &x, int &y){
    bool validDst = false;
    string in;
    while (!validDst) {
        std::cin >> in;
        if (parseMove(in, x, y))
            validDst = true;
        else
            std::cout << "Invalid input, retry" << std::endl;
    }

}

bool Player::parseMove(const string dst, int &x, int &y) {
    if(!isdigit(dst[0]))
        return false;

    if(!isdigit(dst[1]))
        return false;

    x = dst[0] - 48;
    y = dst[1] - 48;
    cout<< x<<" "<< y<<endl;

    //makes sure the coordinates entered are on the board
    if((0 <= x && x <= 2) && (0 <= y && y <= 2))
        return true;
}
