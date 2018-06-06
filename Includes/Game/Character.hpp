//
// EPITECH PROJECT, 2018
// Indie Studio - Game - Character
// File description:
// Created by Hadrien Mortier on 5 June 2018
//

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <irrlicht/irrlicht.h>

#define DEFAULT_HP 100

namespace Game {
	class Character {

	public:
		Character(unsigned int nb);
		~Character();
		
	protected:
		unsigned int	_x;	// X Position
		unsigned int	_y;	// Y Position
		unsigned int	_nb;	// Player number
		unsigned int	_hp;	// Health Points
		char    _player;	// Player symbol
	};
}

#endif // GAME_HPP
