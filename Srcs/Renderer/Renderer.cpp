//
// Created by artha on 02.06.18.
//

#include "Renderer/Renderer.hpp"
#include <irrlicht/irrlicht.h>

namespace Renderer {
	Renderer::Renderer(Engine::Engine &engine) : mEngine(engine)
	{

	}

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
		irr::video::IVideoDriver *driver;
		irr::scene::ISceneManager *sceneMgr;
		irr::video::SColor whiteColor(255,255,255,255);

		driver = mEngine.getDriver();
		sceneMgr = mEngine.getSceneManager();

		driver->beginScene(true, true, whiteColor);
	}

	void Renderer::init()
	{
		irr::IrrlichtDevice *device;

		device = mEngine.getDevice();
		device->setWindowCaption(L"BomberMan");
		device->getCursorControl()->setVisible(false);
	}
}

