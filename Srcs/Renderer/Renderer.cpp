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
		mSceneMgr(*engine.getSceneManager()),
		mBackColor(irr::video::SColor(255,86,126,255)),
		mBoxNode(nullptr)
	{
		mSceneMgr.addEmptySceneNode(nullptr, 1);
		mBoxNode = mSceneMgr.getSceneNodeFromId(1, nullptr);
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
		mDriver.beginScene(true, true, mBackColor);
		mSceneMgr.drawAll();
		mDriver.endScene();
	}

	void Renderer::render(Game::Map &map, size_t size)
	{
		std::vector<std::string> rawMap = map.getMap();

		mBoxNode->removeAll();
		RR::Scene::spawnBox(rawMap, size + 2, mBoxNode);
		mDriver.beginScene(true, true, mBackColor);
		mSceneMgr.drawAll();
		mDriver.endScene();
	}

	void Renderer::init(Game::Map &map,  size_t mapSize)
	{
		std::vector<std::string> rawMap = map.getMap();
		mDevice.setWindowCaption(L"BomberMan");
		RR::Scene::setBaseLight();
		RR::Scene::setBaseCamera();
		RR::Scene::spawnGround(mapSize + 2);
		RR::Scene::spawnWall(rawMap, mapSize + 2);
		RR::Scene::spawnBox(rawMap, mapSize + 2, mBoxNode);
	}
}

