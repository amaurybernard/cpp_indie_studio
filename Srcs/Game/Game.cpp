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
	_player.push_back(new Character(_map, 1, true));
	if (nbPlayer == 1)
		human2 = false;
	_player.push_back(new Character(_map, 2, human2));
	_player.push_back(new Character(_map, 3, false));
	_player.push_back(new Character(_map, 4, false));
}

Game::Game::~Game()
{
	for (Character *player : _player) {
		delete(player);
	}
}

void Game::Game::loop(Engine::Engine &engine)
{
	_player[0]->move(engine);
	_player[0]->testBomb(_player);
	if (engine.getEventReceiver()->isKeyDown(irr::KEY_SPACE))
		_player[0]->placeBomb();
	if (_player[1]->isHuman()) {
		_player[1]->move(engine, 1);
		_player[1]->testBomb(_player);
		if (engine.getEventReceiver()->isKeyDown(irr::KEY_KEY_X))
			_player[1]->placeBomb();
	}
}

Game::Character Game::Game::getPlayer(size_t nb)
{
	return *_player[nb];
}

std::vector<Game::Character *> Game::Game::getPlayers()
{
	return (_player);
}

Game::Map &Game::Game::getMap()
{
	return _map;
}

size_t Game::Game::getMapSize()
{
	return _map.getSize();
}
