/*
** EPITECH PROJECT, 2017
**  cpp_indie_studio, Main
** File description:
**      Created by Amaury Bernard, the 5/15/18, at 2:13 PM
*/

#include <irrlicht/irrlicht.h>
#include "Core/Engine.hpp"

int 	main(void)
{
	Engine::Engine	engine;
	engine.getDevice()->setWindowCaption(L"Hello World!");

	// load and show quake2 .md2 model
	irr::scene::ISceneNode* node = engine.getSceneManager()->addAnimatedMeshSceneNode(
		engine.getSceneManager()->getMesh("quake2model.md2"));

	// if everything worked, add a texture and disable lighting
	if (node)
	{
		node->setMaterialTexture(0, engine.getDriver()->getTexture("texture.bmp"));
		node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	}

	// add a first person shooter style user controlled camera
	engine.getSceneManager()->addCameraSceneNodeFPS();

	// draw everything
	while(engine.getDevice()->run() && engine.getDriver())
	{
		engine.getDriver()->beginScene(true, true, irr::video::SColor(255,255,255,255));
		engine.getSceneManager()->drawAll();
		engine.getDriver()->endScene();
	}

	// delete device
	engine.getDevice()->drop();
	return 0;
}
