/*********************************************************************
** Program name: Game.cpp
** Author: Nathan Smith
** Date: 7-13-18
** Description:
* Implimentation file for Game class. Constructor sets pointers to null
* then sets all user inputs to 0. 
*********************************************************************/

#include "Game.hpp"
#include "libraryFunctions.hpp"
#include <iostream>

Game::Game()
{
    totalRounds = 0;
    dieTypePlayer1 = 0;
    dieTypePlayer2 = 0;
    player1Score = 0;
    player2Score = 0;
    player1DieSides = 0;
    player2DieSides = 0;
    
    die1 = NULL;
    die2 = NULL;
    loadedDie1 = NULL;
    loadedDie2 = NULL;
    
}

// gets user input and calls initDie() if user decides to player
bool Game::initGame()
{
    //sets both player 1 and player 2 scores to 0
    player1Score = player2Score = 0;
    
    //returns 0 if quitting, 1 if playing
    int userInput = getValidNumber("Select from the following 2 choices:\n1. Play game\n2. Exit game",
                    "Please enter 1 or 2.",
                    0,
                    3
                    );
                    
    if (userInput == 2)
    {
        return false; // end
    }
    
    totalRounds = getValidNumber("Enter how many rounds will be played:");
    dieTypePlayer1 = getValidNumber("Enter die type for player 1.\n1. Regular\n2. Loaded",
                                    "Please enter 1 or 2",
                                    0,
                                    3
                                    );
    dieTypePlayer2 = getValidNumber("Enter die type for player 2.\n1. Regular\n2. Loaded",
                                    "Please enter 1 or 2",
                                    0,
                                    3
                                    );
    player1DieSides = getValidNumber("Enter a number of sides for dice for player 1:",
                                "Enter a number 2 or greater",
                                1);
    player2DieSides = getValidNumber("Enter a number of sides for dice for player 2:",
                                "Enter a number 2 or greater",
                                1);
    
    initDie();
    
    return true; // start
}


// cretes new memory for Die and LoadedDie classes based on user input
void Game::initDie()
{
        if ( (dieTypePlayer1 == 1) && (dieTypePlayer2 == 1) )
        {
            die1 = new Die(player1DieSides);
            die2 = new Die(player2DieSides);
        }
        else if ( (dieTypePlayer1 == 2) && (dieTypePlayer2 == 2) )
        {
            loadedDie1 = new LoadedDie(player1DieSides);
            loadedDie2 = new LoadedDie(player2DieSides);
        }
        else if ( (dieTypePlayer1 == 1) && (dieTypePlayer2 == 2) )
        {
            die1 = new Die(player1DieSides);
            loadedDie2 = new LoadedDie(player2DieSides);
        }
        else if ( (dieTypePlayer1 == 2) && (dieTypePlayer2 == 1) )
        {
            die2 = new Die(player2DieSides);
            loadedDie1 = new LoadedDie(player1DieSides);
        }
    else
    {
        std::cout << "error in initDie()" << std::endl;
    }
}

// deletes memory for Die and LoadedDie classes based on how game was setup
Game::~Game()
{
    if(die1)
    {
        delete die1;
        die1 = NULL;
    }
    if(die2)
    {
        delete die2;
        die2 = NULL;
    }
    if(loadedDie1)
    {
        delete loadedDie1;
        loadedDie1 = NULL;
    }
    if(loadedDie2)
    {
        delete loadedDie2;
        loadedDie2 = NULL;
    }
}

// returns true of round successfully played
// returns false if at end of game (no rounds left)
bool Game::playRound()
{
    if (totalRounds >= 1)
    {
        int tempPlayer1Score;
        int tempPlayer2Score;
        int roundWinner;
        
        // roll for player 1
        if (dieTypePlayer1 == 1)
        {
            tempPlayer1Score = die1->roll();
        }
        else
        {
            tempPlayer1Score = loadedDie1->roll();
        }
    
        // roll for player 2
        if (dieTypePlayer2 == 1)
        {
            tempPlayer2Score = die2->roll();
        }
        else
        {
            tempPlayer2Score = loadedDie2->roll();
        }
        
        // if player 1 wins
        if (tempPlayer1Score > tempPlayer2Score)
        {
            roundWinner = 1;
            player1Score ++;
        }
        // if player 2 wins  
        else if (tempPlayer2Score > tempPlayer1Score)
        {
            roundWinner = 2;
            player2Score ++;
        }
        else // tie
        {
            roundWinner = 0;
        }
        // output player 1 stats
        
        std::cout << "Player 1 Die Sides: " << player1DieSides << std::endl;
        std::cout << "Player 1 Die Type: " << dieTypePlayer1 << std::endl;
        std::cout << "Player 1 Roll: " << tempPlayer1Score << std::endl;
        std::cout << std::endl;
        
        // output player 2 stats
        std::cout << "Player 2 Die Sides: " << player2DieSides << std::endl;
        std::cout << "Player 2 Die Type: " << dieTypePlayer2 << std::endl;
        std::cout << "Player 2 Roll: " << tempPlayer2Score << std::endl;
        
        // output score result
        if (roundWinner)
        {
            std::cout << "Score Result: Player " << roundWinner << " wins round!" << std::endl;
        }
        else
            std::cout << "Round ends in a tie." << std::endl;
        
        
        //decriment number of rounds remaining
        totalRounds --;
        
        return true;
    }
    
    return false; 

}

// prints end game stats to console
void Game::displayWinner()
{
    std::cout << "Final Score Count Player 1: " << player1Score << std::endl;
    std::cout << "Final Score Count Player 2: " << player2Score << std::endl;
    
    if (player1Score > player2Score)
    {
        std::cout << "Player 1 Won!" << std::endl;
    }
    else if (player2Score > player1Score)
    {
        std::cout << "Player 2 Won!" << std::endl;
    }
    else 
    {
        std::cout << "Game ended in a tie!" << std::endl;
    }
}