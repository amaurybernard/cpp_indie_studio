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
		mPlayerNode(nullptr)
	{
		mSceneMgr.addEmptySceneNode(nullptr, 1);
		mSceneMgr.addEmptySceneNode(nullptr, 2);
		mBoxNode = mSceneMgr.getSceneNodeFromId(1, nullptr);
		mPlayerNode = mSceneMgr.getSceneNodeFromId(2, nullptr);
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
		RR::Scene::spawnBox(rawMap, size + 2, mBoxNode);
		RR::Scene::spawnPlayer(rawMap, size + 2, mPlayerNode);
		mDriver.beginScene(true, true, mBackColor);
		mSceneMgr.drawAll();
		mDriver.endScene();
	}

	void Renderer::init(Game::Map &map,  size_t mapSize)
	{
		std::vector<std::string> rawMap = map.getMap();
		mDevice.setWindowCaption(L"BomberMan");
		RR::Scene::setBaseLight();
		RR::Scene::setBaseCamera(mapSize);
		RR::Scene::spawnGround(mapSize + 2);
		RR::Scene::spawnWall(rawMap, mapSize + 2);
		RR::Scene::spawnBox(rawMap, mapSize + 2, mBoxNode);
		RR::Scene::spawnPlayer(rawMap, mapSize + 2, mPlayerNode);
		/*irr::scene::IAnimatedMesh* mesh = mSceneMgr.getMesh("./models/BomberMan.3ds");
		irr::scene::ISceneNode* node = mSceneMgr.addAnimatedMeshSceneNode(mesh);
		node->setPosition(irr::core::vector3df(10.0f, 5.0f, 10.0f));
		node->setScale(irr::core::vector3df(0.05f, 0.05f, 0.05f));
		node->setRotation(irr::core::vector3df(-90.0f, 180.0f, 0.0f));
		node->setMaterialTexture(0, mDriver.getTexture("./models/Bombermap.tga"));
		mSceneMgr.getMeshManipulator()->makePlanarTextureMapping(mesh->getMesh(0),0.004f);
		node->setMaterialFlag(irr::video::EMF_LIGHTING,false);*/
	}
}

