/*********************************************************************
** Program name: LoadedDie.hpp
** Author: Nathan Smith
** Date: 7-13-18
** Description:
* Implimenation file for LoadedDie class (inherits from Die class).
* Contains 1 public method to return
* random roll skewed high (40% of time it returns max side #)
*********************************************************************/

#include "LoadedDie.hpp"
#include "Die.hpp"
#include <iostream>
#include "libraryFunctions.hpp"
#include <cstdlib>
#include <ctime>

// calls Die constructor and also uses time to seed srand
LoadedDie::LoadedDie(int sidesIn) : Die(sidesIn){
    
    //used for function that gets random number
    srand(time(NULL));
}

// calling this function returns random number except ~40% of time
// when it will simply return largest number in range
int LoadedDie::roll()
{
    int randomRoll = getRandIntInRange(1,N+1);
    
    if (getRandIntInRange(0,11) > 4)
    {
        return N;
    }
    return randomRoll;
}