//
// Created by artha on 02.06.18.
//

#include "Renderer/Renderer.hpp"
#include <irrlicht/irrlicht.h>
#include <unistd.h>

namespace RR {
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
		irr::video::SColor whiteColor(255,86,126,255);
		mDriver.beginScene(true, true, whiteColor);
		mSceneMgr.drawAll();
		mDriver.endScene();
	}

	void Renderer::init()
	{
		mDevice.setWindowCaption(L"BomberMan");
		mSceneMgr.addCameraSceneNodeMaya();
		//mSceneMgr.addLightSceneNode(0, irr::core::vector3df(50,5,50),
			//irr::video::SColorf(1.0f, 1.0f, 1.0f));
		mSceneMgr.setAmbientLight(irr::video::SColor(0,60,60,60));
		for (int j = 0; j < 10; ++j) {
			float z = 0.0f + (j * 10.0f);
			for (int i = 0; i < 10; ++i) {
				float x = 0.0f + (i * 10.0f);
				irr::core::vector3df pos(x,0.0f,z);
				Scene::addMapCube(mSceneMgr, mDriver, pos);
			}
		}
		for (int j = 0; j < 10; ++j) {
			float z = 0.0f + (j * 10.0f);
			for (int i = 0; i < 10; ++i) {
				float x = 0.0f + (i * 10.0f);
				irr::core::vector3df pos(x,10.0f,z);
				if ((i % 2) == 0)
					Scene::addBreakableCube(mSceneMgr,
						mDriver, pos);
			}
		}
		//mDevice.getCursorControl()->setVisible(false);
	}
}

