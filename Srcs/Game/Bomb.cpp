//
// EPITECH PROJECT, 2018
// Indie Studio - Game - Bomb
// File description:
// Created by Hadrien Mortier on 7 June 2018
//

#include <irrlicht/irrlicht.h>
#include "Game/Bomb.hpp"
#include "Bomberman.hpp"

#include <iostream>

Game::Bomb::Bomb(Game::Map &map)
	: _map(map), _activated(false)
{
}

Game::Bomb::~Bomb()
{
}

bool	Game::Bomb::placeBomb(size_t x, size_t y)
{
	if (_map.placeBomb(x, y)) {
		_x = x;
		_y = y;
		_time = std::time(nullptr);
		_activated = true;
		return true;
	}
	return false;
}

void	Game::Bomb::replaceFlames(char c)
{
	size_t i = 1;
	for (i = 1 ; i <= DEFAULT_RANGE ; i++) {
		if (_map.getCase(_x, _y - i) == '#')
			break;
		_map.changeCase(_x, _y - i, c);
	}
	for (i = 1 ; i <= DEFAULT_RANGE ; i++) {
		if (_map.getCase(_x, _y + i) == '#')
			break;
		_map.changeCase(_x, _y + i, c);
	}
	for (i = 1 ; i <= DEFAULT_RANGE ; i++) {
		if (_map.getCase(_x - i, _y) == '#')
			break;
		_map.changeCase(_x - i, _y, c);
	}
	for (i = 1 ; i <= DEFAULT_RANGE ; i++) {
		if (_map.getCase(_x + i, _y) == '#')
			break;
		_map.changeCase(_x + i, _y, c);
	}
}

void	Game::Bomb::explodes()
{
	if (_time + 3 < std::time(nullptr)) {
		_map.changeCase(_x, _y, 'O');
		replaceFlames('O');
	}
	if (_time + 4 < std::time(nullptr)) {
		_map.changeCase(_x, _y, ' ');
		replaceFlames(' ');
		_activated = false;
	}
}

bool	Game::Bomb::isActivated()
{
	return _activated;
}
