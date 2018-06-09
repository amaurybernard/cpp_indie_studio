/*
** EPITECH PROJECT, 2017
**  cpp_indie_studio, Main
** File description:
**      Created by Amaury Bernard, the 5/15/18, at 2:13 PM
*/

#include <vector>
#include <string>
#include <irrlicht/irrlicht.h>
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
	size_t			mapSize = MEDIUM;
	Game::Map		map(mapSize);
	Game::Character		player1(map, 1, mapSize);
	Game::Character		player2(map, 2, mapSize);
	Game::Character		player3(map, 3, mapSize);
	Game::Character		player4(map, 4, mapSize);

	renderer.init(map, mapSize);
	while(engine->getDevice()->run() && engine->getDriver()) {
		if (engine->getDevice()->isWindowActive()) {
			engine->update();
			renderer.render(map, mapSize);
		}
		map.putMap();
		if (engine->getEventReceiver()->isKeyDown(irr::KEY_UP))
			player1.moveUp();
		else if (engine->getEventReceiver()->isKeyDown(irr::KEY_DOWN))
			player1.moveDown();
		else if (engine->getEventReceiver()->isKeyDown(irr::KEY_RIGHT))
			player1.moveRight();
		else if (engine->getEventReceiver()->isKeyDown(irr::KEY_LEFT))
			player1.moveLeft();
	}
	engine->drop();
	return (RT_SUCCESS);
}
