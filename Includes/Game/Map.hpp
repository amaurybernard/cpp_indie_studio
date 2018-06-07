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

// Map's Size
#define SMALL 9
#define MEDIUM 13 // By default
#define BIG 17

// Density of destructibles Blocks
#define DENSITY_LOW 3
#define DENSITY_MEDIUM 5
#define DENSITY_HIGH 8
#define DENSITY_MAX 11

namespace Game {
	class Map {

	public:
		Map(size_t size);
		~Map();
		void createMap();
		void generateBlocks(size_t density);
		void resetMap();
		std::vector<std::string> getMap();
		void putMap();
		bool breakBlock(size_t x, size_t y);
		bool addPlayer(size_t player_nb);
		bool addPlayer(size_t x, size_t y, size_t player_nb);
	private:
		size_t				_size;
		std::vector<std::string>	_map;
		std::vector<std::string>	_tmp;
	};
}

#endif // GAME_HPP
