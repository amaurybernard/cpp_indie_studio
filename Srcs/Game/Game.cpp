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
//	this->_player1 = new Game::Character(_map, 1, mapSize);
//	this->_player2(_map, 2, mapSize);
//	this->_player3(_map, 3, mapSize);
//	this->_player4(_map, 4, mapSize);
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
