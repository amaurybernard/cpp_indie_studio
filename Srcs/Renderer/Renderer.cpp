//
// Created by artha on 02.06.18.
//

#include "Renderer/Renderer.hpp"
#include <irrlicht/irrlicht.h>
#include <unistd.h>

namespace Renderer {
	Renderer::Renderer(Engine::Engine &engine) :
		mEngine(engine),
		mDevice(*engine.getDevice()),
		mDriver(*engine.getDriver()),
		mSceneMgr(*engine.getSceneManager())
	{}

	Engine::Engine &Renderer::getEngine() const
	{
		return mEngine;
	}

	void Renderer::setEngine(Engine::Engine &engine)
	{
		mEngine;
		//mEngine = engine; quand amaury aura implementer la forme canonique
	}

	Renderer &Renderer::operator=(const Renderer &renderer)
	{
		return *this;
		//return mEngine = renderer.mEngine; quand amaury aura implementer la forme canonique
	}

	void Renderer::render()
	{
		irr::video::SColor whiteColor(255,255,255,255);
		//sleep(1);
		mDriver.beginScene(true, true, whiteColor);
		mSceneMgr.drawAll();
		mDriver.endScene();
	}

	void Renderer::init()
	{
		mDevice.setWindowCaption(L"BomberMan");
		mSceneMgr.addCameraSceneNodeMaya();
		for (int i = 0; i < 10; ++i) {
			irr::scene::IMeshSceneNode *newCube =
				mSceneMgr.addCubeSceneNode(
					10.0f,
					0,
					-1,
					irr::core::vector3df(0.0f, 0.0f, 20.0f + (10.0f * i))
				);
			newCube->setMaterialFlag(irr::video::EMF_WIREFRAME, true);
		}
		//mDevice.getCursorControl()->setVisible(false);
	}
}

