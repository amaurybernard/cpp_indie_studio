//
// EPITECH PROJECT, 2018
// Indie Studio - Game - Character
// File description:
// Created by Hadrien Mortier, on 5 June 2018
//

#include <irrlicht/irrlicht.h>
#include "Game/Character.hpp"
#include "Bomberman.hpp"

Game::Character::Character(unsigned int nb)
	: _nb(nb), _hp(DEFAULT_HP)
{
	_player = (nb + 48);
	if (nb == 1) {
		this->_x = 1;
		this->_y = 1;
	}
}

Game::Character::~Character()
{
}
