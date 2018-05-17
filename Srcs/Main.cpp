/*
** EPITECH PROJECT, 2017
**  cpp_plazza, Main
** File description:
**      Created by Amaury Bernard, the 29/03/18, at 15:22
*/

#include <irrlicht/irrlicht.h>
#include "Core/Core.hpp"
using namespace irr;

int 	main(void)
{
	Core::Core	core;



	video::IVideoDriver* driver = core.getDevice()->getVideoDriver();
	scene::ISceneManager* scenemgr = core.getDevice()->getSceneManager();

	core.getDevice()->setWindowCaption(L"Hello World!");

	// load and show quake2 .md2 model
	scene::ISceneNode* node = scenemgr->addAnimatedMeshSceneNode(
		scenemgr->getMesh("quake2model.md2"));

	// if everything worked, add a texture and disable lighting
	if (node)
	{
		node->setMaterialTexture(0, driver->getTexture("texture.bmp"));
		node->setMaterialFlag(video::EMF_LIGHTING, false);
	}

	// add a first person shooter style user controlled camera
	scenemgr->addCameraSceneNodeFPS();

	// draw everything
	while(core.getDevice()->run() && driver)
	{
		driver->beginScene(true, true, video::SColor(255,0,0,255));
		scenemgr->drawAll();
		driver->endScene();
	}

	// delete device
	core.getDevice()->drop();
	return 0;
}
