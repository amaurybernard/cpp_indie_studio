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
		mBoxNode(nullptr),
		mPlayerNode(nullptr),
		mBombNode(nullptr),
		mFlameNode(nullptr),
		mBackground(nullptr),
		mBombMesh(nullptr),
		mBombTexture(nullptr)
	{
		mSceneMgr.addEmptySceneNode(nullptr, 1);
		mSceneMgr.addEmptySceneNode(nullptr, 2);
		mSceneMgr.addEmptySceneNode(nullptr, 3);
		mSceneMgr.addEmptySceneNode(nullptr, 4);
		mBoxNode = mSceneMgr.getSceneNodeFromId(1, nullptr);
		mPlayerNode = mSceneMgr.getSceneNodeFromId(2, nullptr);
		mBombNode = mSceneMgr.getSceneNodeFromId(3, nullptr);
		mFlameNode = mSceneMgr.getSceneNodeFromId(4, nullptr);
		mBackground = mDriver.getTexture("./textures/background.jpg");
		mBombMesh = mSceneMgr.getMesh("./models/bomb.obj");
		mBombTexture = mDriver.getTexture("./models/bombbody_BaseColor.png");
		//destructor
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
		mPlayerNode->removeAll();
		mBombNode->removeAll();
		RR::Scene::spawnBox(rawMap, size + 2, mBoxNode);
		RR::Scene::spawnPlayer(rawMap, size + 2, mPlayerNode);
		RR::Scene::spawnBomb(rawMap, size + 2, mBombNode);
		RR::Scene::spawnFlame(rawMap, size + 2, mFlameNode);
		mDriver.beginScene(true, true, mBackColor);
		mDriver.draw2DImage(mBackground, irr::core::position2d<irr::s32>(0,0),
			irr::core::rect<irr::s32>(0,0,1920,1080), 0,
			irr::video::SColor(255,255,255,255), true);
		mSceneMgr.drawAll();
		RR::Scene::drawText();
		mDriver.endScene();
	}

	void Renderer::init(Game::Map &map,  size_t mapSize)
	{
		std::vector<std::string> rawMap = map.getMap();
		mDevice.setWindowCaption(L"BomberMan");
		mapSize += 2;
		RR::Scene::setBaseLight();
		RR::Scene::setBaseCamera(mapSize - 2);
		RR::Scene::spawnGround(mapSize);
		RR::Scene::spawnWall(rawMap, mapSize);
		RR::Scene::spawnBox(rawMap, mapSize, mBoxNode);
		RR::Scene::spawnPlayer(rawMap, mapSize, mPlayerNode);
		RR::Scene::spawnBomb(rawMap, mapSize, mBombNode);
		RR::Scene::spawnFlame(rawMap, mapSize, mFlameNode);
	}
}

