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

#include "Game/Game.hpp"
#include "Game/Character.hpp"
#include "Game/Map.hpp"

int 	main(void)
{
	Engine::Engine		*engine = Engine::Engine::instance();
	RR::Renderer		renderer(*engine);
	Game::Game		game(1, SMALL, DENSITY_MEDIUM);

	renderer.init(game.getMap(), game.getMapSize());
	while(engine->keepLooping()) {
		if (engine->getDevice()->isWindowActive()) {
			renderer.render(game.getMap(), game.getMapSize());
		}
//		map.putMap();
//		player1.move(*engine);
//		player1.testBomb();
//		if (engine->getEventReceiver()->isKeyDown(irr::KEY_SPACE))
//			player1.placeBomb();
	}
	engine->drop();
	return (RT_SUCCESS);
}
