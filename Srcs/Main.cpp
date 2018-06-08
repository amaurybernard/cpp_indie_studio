/*
** EPITECH PROJECT, 2017
**  cpp_indie_studio, Main
** File description:
**      Created by Amaury Bernard, the 5/15/18, at 2:13 PM
*/

#include <irrlicht/irrlicht.h>
#include "Engine/EventReceiver.hpp"
#include "Engine/Engine.hpp"
#include "Renderer/Renderer.hpp"
#include "Bomberman.hpp"

int 	main(void)
{
	Engine::Engine		engine;
	RR::Renderer	renderer(engine);

	renderer.init();
	while(engine.getDevice()->run() && engine.getDriver()) {
		if (engine.getEventReceiver()->isKeyDown(irr::KEY_SPACE)) {
			puts("main: space is true");
			//return (RT_FAILURE);
		}
		if (engine.getDevice()->isWindowActive()) {
			//engine.update();
			renderer.render();
		}
	}
	return (RT_SUCCESS);
}
