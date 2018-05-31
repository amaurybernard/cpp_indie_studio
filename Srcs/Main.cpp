/*
** EPITECH PROJECT, 2017
**  cpp_indie_studio, Main
** File description:
**      Created by Amaury Bernard, the 5/15/18, at 2:13 PM
*/

#include <irrlicht/irrlicht.h>
#include "Engine/Engine.hpp"

//todo: load start menu
int 	main(void)
{
	Engine::Engine	engine;
	engine.getDevice()->setWindowCaption(L"BomberMan");

	while(engine.getDevice()->run() && engine.getDriver()) {
		if (engine.getDevice()->isWindowActive()) {
			engine.getDriver()->beginScene(true, true, irr::video::SColor(255,255,255,255));
			engine.getSceneManager()->drawAll();
			engine.getDriver()->endScene();
		}
	}
	return (0);
}
