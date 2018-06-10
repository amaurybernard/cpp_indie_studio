/*
** EPITECH PROJECT, 2017
**  cpp_indie_studio, Main
** File description:
**      Created by Amaury Bernard, the 5/15/18, at 2:13 PM
*/

#include <vector>
#include <string>
#include <irrlicht/irrlicht.h>
#include <Game/Game.hpp>
#include <Menu/Menu.hpp>
#include "Engine/EventReceiver.hpp"
#include "Engine/Engine.hpp"
#include "Renderer/Renderer.hpp"
#include "Bomberman.hpp"

#include "Game/Character.hpp"
#include "Game/Map.hpp"

int 	main(void)
{
	Engine::Engine		*engine = Engine::Engine::instance();
	RR::Renderer		renderer(*engine);
	size_t			mapSize = BIG;
	Game::Map		map(mapSize);
	Game::Character		player1(map, 1, mapSize);
	Game::Character		player2(map, 2, mapSize);
	Game::Character		player3(map, 3, mapSize);
	Game::Character		player4(map, 4, mapSize);
	Game::Game		*game = nullptr;
	Menu::Menu			menu;

	renderer.init(map, mapSize);
	while(engine->keepLooping()) {
		if (game) {
			if (engine->getDevice()->isWindowActive()) {
				renderer.render(map, mapSize);
			}
			player1.move(*engine);
			player1.testBomb();
			if (engine->getEventReceiver()->isKeyDown(
				irr::KEY_SPACE))
				player1.placeBomb();
		} else {
			game = menu.getSelectedGame();
		}
	}
	engine->drop();
	return (RT_SUCCESS);
}
