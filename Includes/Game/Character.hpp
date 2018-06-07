//
// EPITECH PROJECT, 2018
// Indie Studio - Game - Character
// File description:
// Created by Hadrien Mortier on 5 June 2018
//

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <irrlicht/irrlicht.h>
#include "Game/Map.hpp"

#define DEFAULT_HP 100

namespace Game {
	class Character {

	public:
		Character(Game::Map &map, size_t nb, size_t mapSize);
		~Character();
		bool moveUp();
		bool moveDown();
		bool moveRight();
		bool moveLeft();
	protected:
		Map		&_map;	// Playing map
		size_t		_nb;	// Player number
		size_t		_x;	// X Position
		size_t		_y;	// Y Position
		size_t		_hp;	// Health Points
	};
}

#endif // GAME_HPP
