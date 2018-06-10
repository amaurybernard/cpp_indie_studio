//
// EPITECH PROJECT, 2018
// Indie Studio - Game - Game
// File description:
// Created by Hadrien Mortier, on 5 June 2018
//

#include <irrlicht/irrlicht.h>
#include "Game/Game.hpp"
#include "Bomberman.hpp"

Game::Game::Game(size_t nbPlayer, size_t mapSize, size_t density)
	: _map(mapSize, density)
{
	bool human2 = true;
	_player.push_back(*(new Character(_map, 1, true)));
	if (nbPlayer == 1)
		human2 = false;
	_player.push_back(*(new Character(_map, 2, human2)));
	_player.push_back(*(new Character(_map, 3, false)));
	_player.push_back(*(new Character(_map, 4, false)));
}

Game::Game::~Game()
{
}

Game::Map &Game::Game::getMap()
{
	return _map;
}

size_t Game::Game::getMapSize()
{
	return _map.getSize();
}
