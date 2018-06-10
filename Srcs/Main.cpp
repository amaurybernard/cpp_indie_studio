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
#include "Game/Bomb.hpp"
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
		game.getMap().putMap();
		game.loop(*engine);
	}
	engine->drop();
	return (RT_SUCCESS);
}
