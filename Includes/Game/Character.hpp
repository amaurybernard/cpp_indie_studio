//
// EPITECH PROJECT, 2018
// Indie Studio - Game - Character
// File description:
// Created by Hadrien Mortier on 5 June 2018
//

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <irrlicht/irrlicht.h>
#include "Engine/Engine.hpp"
#include "Game/Map.hpp"
#include "Game/Bomb.hpp"

constexpr unsigned DEFAULT_HP = 100;

namespace Game {
	class Character {
	public:
		Character(Game::Map &map, size_t nb, bool human);
		~Character();

		void placeBomb();
		void testBomb();
		//bool loseHP();
		//bool isDead();

		bool move(Engine::Engine &engine);
		bool moveUp();
		bool moveDown();
		bool moveRight();
		bool moveLeft();

		enum Oriented {
			UP ,
			DOWN ,
			RIGHT ,
			LEFT ,
		};
	protected:
		Map		&_map;	// Playing map
		Bomb		_bomb; // Player's Bomb
		size_t		_nb;	// Player number
		size_t		_x;	// X Position
		size_t		_y;	// Y Position
		size_t		_hp;	// Health Points
		Oriented	_direction; // Face direction
		long		_score; // score of the player
		bool		_human; // is a human or an iA ?
	};
}

#endif // GAME_HPP
