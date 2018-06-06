//
// EPITECH PROJECT, 2018
// Indie Studio - Game - Map
// File description:
// Created by Hadrien Mortier, on 5 June 2018
//

#include <string>
#include <irrlicht/irrlicht.h>
#include "Game/Map.hpp"
#include "Bomberman.hpp"

Game::Map::Map(size_t size)
	: _size(size)
{
	createMap();
}

Game::Map::~Map()
{
	size_t y = 0;
	for (y = 1 ; y <= _size ; y++) {
		_map[y].clear();
	}
	_map.clear();
}

void Game::Map::createMap()
{
	size_t		x = 0;
	size_t		y = 0;
	_map.resize(_size + 2);
	_map[0].append(_size + 2, '#');
	for (y = 1 ; y <= _size ; y++) {
		_map[y].push_back('#');
		x = 1;
		while (x <= _size) {
			if ((y % 2 == 0) && (x % 2 == 0))
				_map[y].push_back('#');
			else
				_map[y].push_back(' ');
			x++;
		}
		_map[y].push_back('#');
	}
	_map[_size + 1].append(_size + 2, '#');
	for (y = 0 ; y <= _size + 1 ; y++)
		puts(_map[y].c_str());
}
