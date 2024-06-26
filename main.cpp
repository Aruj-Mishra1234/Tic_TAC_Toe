#include <iostream>
#include <string>
using namespace std;

#include "Board.hpp"
#include "Player.hpp"
#include "Game.hpp"

int main()
{
    cout << "\t\t\t\t\t\t\t\t*** WELCOME TO TIC - TAC - TOE ***\n";
    cout << "Press 1 to continue and 0 to escape:\n";
    bool option;
    cin >> option;
    if (!option) return 0;
    cout << '\n';
    Game currGame;
    currGame.play();
    return 0;
}