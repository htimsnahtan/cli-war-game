/*********************************************************************
** Program name: main.hpp
** Author: Nathan Smith
** Date: 7-13-18
** Description: 2 player CLI game. Each player rolls a die and whichever
* gets the higher number gains 1 point. If both roll same number a draw
* occurs and no points are awarded.
* 
*********************************************************************/

#include "Game.hpp"
#include "Die.hpp"
#include "LoadedDie.hpp"
#include <iostream>

int main()
{
    //create new memory for game instance
    Game *gameInstance;
    gameInstance = new Game();
    
    if ( gameInstance->initGame() ) { // if user inits game
        while( gameInstance->playRound() ) {} // while play round returns true
        gameInstance->displayWinner(); // after game ends, display stats
    }
    
    //free memory and let user know game has ended
    delete gameInstance;
    std::cout << "Goodbye!" << std::endl;
    
    return 0;
}