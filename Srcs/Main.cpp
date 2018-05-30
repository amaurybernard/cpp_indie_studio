/*
** EPITECH PROJECT, 2017
**  cpp_indie_studio, Main
** File description:
**      Created by Amaury Bernard, the 5/15/18, at 2:13 PM
*/

#include <irrlicht/irrlicht.h>
#include "Engine/Engine.hpp"

int 	main(void)
{
	Engine::Engine	engine;
	engine.setWindowCaption(L"BomberMan");

	//todo: load start menu
	engine.getVideoDriver()->beginScene(true, true, irr::video::SColor(255,255,255,255));
	irr::video::ITexture* images = irr::driver->getTexture("../../media/2ddemo.png");
	engine.getVideoDriver()->makeColorKeyTexture(images,
	irr::core::position2d<irr::s32>(0,0));
	engine.getSceneManager()->drawAll();
	engine.getVideoDriver()->endScene();

	while(engine.getDevice()->run() && engine.getVideoDriver()) {
	}
	return (0);
}
