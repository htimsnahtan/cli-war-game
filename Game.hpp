/*********************************************************************
** Program name: Die.cpp
** Author: Nathan Smith
** Date: 7-13-18
** Description:
* Header declaration file for Die class. Declares several integers which
* keep track of userInput which is setup in initGame. If user decides to 
* play game, initDie is run to create new memory for dice. Also includes
* method to player a single round (which returns true if success and 
* prints current stats of round to console) and 
* displayWinner to displayer final stats. Destructor frees dynamic memory.
*********************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "Die.hpp"
#include "LoadedDie.hpp"

class Game
{
    private:
        int totalRounds;
        int dieTypePlayer1;
        int dieTypePlayer2;
        int player1Score;
        int player2Score;
        int player1DieSides;
        int player2DieSides;
        
        // Wrote whole program assuming both player 1 & 2 would use
        // dice that both had the same number of sides. Then changed
        // program to allow each player to use a die whose number of 
        // is independant from the number of sides of their opponents
        // die. Should probably refactor this later.
        Die *die1;
        LoadedDie *loadedDie1;
        Die *die2;
        LoadedDie *loadedDie2;
        
    public:
        Game();
        ~Game();
        void initDie();
        bool initGame();
        bool playRound();
        void displayWinner();
};

#endif