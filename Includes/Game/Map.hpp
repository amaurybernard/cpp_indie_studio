//
// EPITECH PROJECT, 2018
// Indie Studio - Game - Map
// File description:
// Created by Hadrien Mortier on 5 June 2018
//


#ifndef MAP_HPP
#define MAP_HPP
#include <irrlicht/irrlicht.h>
#include <vector>
#include <string>

#define SMALL 9
#define MEDIUM 13 // By default
#define BIG 17

namespace Game {
	class Map {

	public:
		Map(size_t size);
		~Map();
		void createMap();
		void resetMap();
		
	private:
		size_t				_size;
		std::vector<std::string>	_map;
	};
}

#endif // GAME_HPP
