/*********************************************************************
** Program name: loadedDie.hpp
** Author: Nathan Smith
** Date: 7-13-18
** Description:
* Header declaration file for loadedDie class
*********************************************************************/

#ifndef LOADED_DIE_HPP
#define LOADED_DIE_HPP

#include "Die.hpp"

class LoadedDie : public Die
{
    public:
        LoadedDie(int);
        int roll();
};

#endif