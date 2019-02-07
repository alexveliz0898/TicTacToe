#include <iostream>
#include "AutoPlayer.hpp"
#include "Player.hpp"
//#include "Board.hpp"
using namespace std;

void singlePlayer();
void multiPlayer();

int main() {
    char input;
    cout<<"Type m for multiplayer, s for solo (s/m)";
    cin>>input;

    if(input == 'm')
        multiPlayer();


    if(input == 's')
        singlePlayer();

    return 0;
}

void singlePlayer(){
    int x, y;
    string playerName;
    bool gameover = false;
    char choice;

    Player P1 = Player("Player 1");
    Board playingField;
    AutoPlayer ai;
    //ai = AutoPlayer();

    while(1) {
        while (!gameover) {

            while (1) {
                playingField.printBoard();
                P1.getDst(x, y);

                if (playingField.isEmpty(x, y)) {
                    playingField.placeMarker(x, y, P1.getSymbol());
                    break;
                } else
                    cout << "Enter a valid move" << endl;
            }
            if (playingField.threeInARow() || playingField.tie()) {
                gameover = true;
                //break;
            }

            ai.getBestMove(playingField);

            if (playingField.threeInARow() || playingField.tie())
                gameover = true;
        }

        cout<<"Do you want to play again? (y/n)"<<endl;

        cin>>choice;

        if(choice == 'n')
            break;

    }
    playingField.printBoard();
}

void multiPlayer(){
    Player P1 = Player("Player 1");
    Player P2 = Player("Player 2");
    Board playingField;
    int x, y;
    char choice;
    bool gameover = false;

    while(1){
        while(!gameover){
            while(1){
                playingField.printBoard();
                P1.getDst(x, y);

                if(playingField.isEmpty(x, y)) {
                    playingField.placeMarker(x, y, P1.getSymbol());
                    break;
                }

                else
                    cout<<"Enter a valid move"<<endl;
            }

            if(playingField.threeInARow() || playingField.tie()) {
                gameover = true;
            }


            while(1){
                playingField.printBoard();
                P2.getDst(x, y);

                if(playingField.isEmpty(x, y)) {
                    playingField.placeMarker(x, y, P2.getSymbol());
                    break;
                }

                else
                    cout<<"Enter a valid move"<<endl;
            }

            if(playingField.threeInARow() || playingField.tie())
                gameover = true;

        }

        cout<<"Do you want to play again? (y/n)"<<endl;

        cin>>choice;

        if(choice == 'n')
            break;

    }
}
