/*
** EPITECH PROJECT, 2017
**  cpp_indie_studio, Main
** File description:
**      Created by Amaury Bernard, the 5/15/18, at 2:13 PM
*/

#include <irrlicht/irrlicht.h>
#include "Engine/EventReceiver.hpp"
#include "Engine/Engine.hpp"
#include "Bomberman.hpp"

#include "Game/Character.hpp"
#include "Game/Map.hpp"

int 	main(void)
{
	Engine::Engine		engine;
	size_t			mapSize = MEDIUM;
	Game::Map		map(mapSize);
	Game::Character		player1(map, 1, mapSize);
	Game::Character		player2(map, 2, mapSize);
	Game::Character		player3(map, 3, mapSize);
	Game::Character		player4(map, 4, mapSize);

	engine.getDevice()->setWindowCaption(L"BomberMan");
	while(engine.getDevice()->run() && engine.getDriver()) {
		if (engine.getEventReceiver()->isKeyDown(irr::KEY_SPACE)) {
			puts("main: space is true");
			//return (RT_FAILURE);
		}

		
		map.putMap();
		if (engine.getEventReceiver()->isKeyDown(irr::KEY_UP))
			player1.moveUp();
		else if (engine.getEventReceiver()->isKeyDown(irr::KEY_DOWN))
			player1.moveDown();
		else if (engine.getEventReceiver()->isKeyDown(irr::KEY_RIGHT))
			player1.moveRight();
		else if (engine.getEventReceiver()->isKeyDown(irr::KEY_LEFT))
			player1.moveLeft();


		if (engine.getDevice()->isWindowActive()) {
			engine.update();
		}
	}
	return (RT_SUCCESS);
}
