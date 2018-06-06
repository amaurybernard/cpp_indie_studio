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

#include "Game/Map.hpp"

int 	main(void)
{
	Engine::Engine		engine;
	Game::Map		map(MEDIUM);

	map.addPlayer(1);
	map.putMap();

	engine.getDevice()->setWindowCaption(L"BomberMan");
	while(engine.getDevice()->run() && engine.getDriver()) {
		if (engine.getEventReceiver()->isKeyDown(irr::KEY_SPACE)) {
			puts("main: space is true");
			//return (RT_FAILURE);
		}
		if (engine.getDevice()->isWindowActive()) {
			engine.update();
		}
	}
	return (RT_SUCCESS);
}
