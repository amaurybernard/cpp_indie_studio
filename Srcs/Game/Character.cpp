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
	: _map(map), _bomb(map), _nb(nb), _hp(DEFAULT_HP)
{
	switch (nb) {
        case 1: _x = 1;
		_y = 1;
		_direction = Game::Character::Oriented::DOWN;
	        break;
        case 2: _x = mapSize;
		_y = 1;
		_direction = Game::Character::Oriented::LEFT;
                break;
        case 3: _x = 1;
		_y = mapSize;
		_direction = Game::Character::Oriented::UP;
		break;
        case 4: _x = mapSize;
		_y = mapSize;
		_direction = Game::Character::Oriented::RIGHT;
                break;
        }
	_map.addPlayer(_x, _y, nb);
}

Game::Character::~Character()
{
}

void Game::Character::placeBomb()
{
	size_t x = _x;
	size_t y = _y;
	switch (_direction) {
        case Game::Character::Oriented::UP :
		y -= 1;
                break;
        case Game::Character::Oriented::DOWN :
                y += 1;
		break;
	case Game::Character::Oriented::RIGHT :
		x += 1;
		break;
	case Game::Character::Oriented::LEFT :
		x -= 1;
		break;
	}
	if (!_bomb.isActivated())
		_bomb.placeBomb(x, y);
}

void Game::Character::testBomb()
{
	if (_bomb.isActivated())
		_bomb.explodes();
}

bool Game::Character::move(Engine::Engine &engine)
{
	if (engine.getEventReceiver()->isKeyDown(irr::KEY_UP))
		return moveUp();
	else if (engine.getEventReceiver()->isKeyDown(irr::KEY_DOWN))
		return moveDown();
	else if (engine.getEventReceiver()->isKeyDown(irr::KEY_LEFT))
		return moveRight();
	else if (engine.getEventReceiver()->isKeyDown(irr::KEY_RIGHT))
		return moveLeft();
	return false;
}

bool Game::Character::moveUp()
{
	if (_direction == Game::Character::Oriented::UP)
		if (_map.moveCharacter(_nb, _x, _y, _x, (_y - 1))) {
			_y -= 1;
			return true;
		}
	_direction = Game::Character::Oriented::UP;
	return false;
}

bool Game::Character::moveDown()
{
	if (_direction == Game::Character::Oriented::DOWN)
		if (_map.moveCharacter(_nb, _x, _y, _x, (_y + 1))) {
			_y += 1;
			return true;
		}
	_direction = Game::Character::Oriented::DOWN;
	return false;
}

bool Game::Character::moveRight()
{
	if (_direction == Game::Character::Oriented::RIGHT)
		if (_map.moveCharacter(_nb, _x, _y, (_x + 1), _y)) {
			_x += 1;
			return true;
		}
	_direction = Game::Character::Oriented::RIGHT;
	return false;
}

bool Game::Character::moveLeft()
{
	if (_direction == Game::Character::Oriented::LEFT)
		if (_map.moveCharacter(_nb, _x, _y, (_x - 1), _y)) {
			_x -= 1;
			return true;
		}
	_direction = Game::Character::Oriented::LEFT;
	return false;
}
