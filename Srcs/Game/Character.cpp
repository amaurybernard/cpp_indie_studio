//
// EPITECH PROJECT, 2018
// Indie Studio - Game - Character
// File description:
// Created by Hadrien Mortier, on 5 June 2018
//

#include <vector>
#include <string>
#include <irrlicht/irrlicht.h>
#include "Game/Character.hpp"
#include "Bomberman.hpp"

Game::Character::Character(Game::Map &map, size_t nb, size_t mapSize)
	: _map(map), _nb(nb), _hp(DEFAULT_HP)
{
	switch (nb) {
        case 1: _x = 1;
		_y = 1;
	        break;
        case 2: _x = mapSize;
		_y = 1;
                break;
        case 3: _x = 1;
		_y = mapSize;
		break;
        case 4: _x = mapSize;
		_y = mapSize;
                break;
        }
	map.addPlayer(_x, _y, nb);
}

Game::Character::~Character()
{
}
