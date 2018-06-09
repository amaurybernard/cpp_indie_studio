/*
** EPITECH PROJECT, 2017
**  cpp_indie_studio
** File description:
**      Assets creqtion wrapper
*/

#include <irrlicht/irrlicht.h>
#include "Engine/Engine.hpp"
#include "Game/Game.hpp"
#include <unistd.h>
#include <string>

namespace RR {
	irr::core::vector3df m3df(float x, float y, float z)
	{
		return irr::core::vector3df(x,y,z);
	}
	namespace Scene {
		void setBaseLight() {
			auto sceneMgr =
				Engine::Engine::instance()->getSceneManager();
			//mSceneMgr.addLightSceneNode(0, irr::core::vector3df(50,5,50),
			//irr::video::SColorf(1.0f, 1.0f, 1.0f));
			sceneMgr->setAmbientLight(
				irr::video::SColor(0,60,60,60));
		}

		void setBaseCamera(size_t mapSize) {
			auto sceneMgr =
				Engine::Engine::instance()->getSceneManager();
			if (mapSize == BIG)
				sceneMgr->addCameraSceneNode(0, RR::m3df(100.0f,150.0f,190.0f), RR::m3df(100.0f, -180.0f, 0.0f));
			else if (mapSize == MEDIUM)
				sceneMgr->addCameraSceneNode(0, RR::m3df(70.0f,150.0f,160.0f), RR::m3df(70.0f, -180.0f, 0.0f));
			else
				sceneMgr->addCameraSceneNode(0, RR::m3df(60.0f,150.0f,140.0f), RR::m3df(60.0f, -180.0f, 0.0f));

		}

		irr::scene::IMeshSceneNode *addGroundCube(
			irr::core::vector3df &position
		)
		{
			auto sceneMgr =
				Engine::Engine::instance()->getSceneManager();
			auto driver =
				Engine::Engine::instance()->getDriver();
			irr::scene::IMeshSceneNode *newCube =
				sceneMgr->addCubeSceneNode(
					10.0f,
					0,
					-1,
					position
				);
			newCube->setMaterialTexture(0,
				driver->getTexture("./textures/mapBlock.jpg"));
			newCube->setMaterialFlag(irr::video::EMF_LIGHTING,
				false);
			return newCube;
		}

		irr::scene::IMeshSceneNode *addWallCube(
			irr::core::vector3df &position
		)
		{
			auto sceneMgr =
				Engine::Engine::instance()->getSceneManager();
			auto driver =
				Engine::Engine::instance()->getDriver();
			irr::scene::IMeshSceneNode *newCube =
				sceneMgr->addCubeSceneNode(
					10.0f,
					0,
					-1,
					position
				);
			newCube->setMaterialTexture(0,
				driver->getTexture("./textures/wallBlock.jpg"));
			newCube->setMaterialFlag(irr::video::EMF_LIGHTING,
				false);
			return newCube;
		}

		irr::scene::IMeshSceneNode *addBreakableCube(
			irr::core::vector3df &position,
			irr::scene::ISceneNode *boxNode
		)
		{
			auto sceneMgr =
				Engine::Engine::instance()->getSceneManager();
			auto driver =
				Engine::Engine::instance()->getDriver();
			irr::scene::IMeshSceneNode *newCube =
				sceneMgr->addCubeSceneNode(
					10.0f,
					boxNode,
					-1,
					position
				);
			newCube->setMaterialTexture(0,
				driver->getTexture(
					"./textures/breakableBlock.png"));
			newCube->setMaterialFlag(irr::video::EMF_LIGHTING,
				false);
			return newCube;
		}

		irr::scene::IAnimatedMesh *addPlayer(
			irr::core::vector3df &pos,
			irr::scene::ISceneNode *playerNode,
			char id
		)
		{
			auto sceneMgr =
				Engine::Engine::instance()->getSceneManager();
			auto driver =
				Engine::Engine::instance()->getDriver();
			irr::scene::IAnimatedMesh* newPlayer =
				sceneMgr->getMesh("./models/BomberMan.3ds");
			irr::scene::ISceneNode* node =
				sceneMgr->addAnimatedMeshSceneNode(newPlayer,
					playerNode);
			node->setID((int)id - 48);
			node->setPosition(RR::m3df(0.0f, -5.0f, 0.0f) + pos);
			node->setScale(RR::m3df(0.05f, 0.05f, 0.05f));
			node->setRotation(RR::m3df(-90.0f, 180.0f, 0.0f));
			node->setMaterialTexture(0,
				driver->getTexture("./models/Bombermap.tga"));
			sceneMgr->getMeshManipulator()->makePlanarTextureMapping(newPlayer->getMesh(0),0.004f);
			node->setMaterialFlag(irr::video::EMF_LIGHTING,false);
			return newPlayer;
		}

		void spawnGround(size_t mapSize)
		{
			for (int j = 0; j < mapSize; ++j) {
				float z = 0.0f + (j * 10.0f);
				for (int i = 0; i < mapSize; ++i) {
					float x = 0.0f + (i * 10.0f);
					irr::core::vector3df pos(x,0.0f,z);
					Scene::addGroundCube(pos);
				}
			}
		}

		void spawnWall(std::vector<std::string> &rawMap, size_t size)
		{
			for (int j = 0; j < size; ++j) {
				float z = 0.0f + (j * 10.0f);
				for (int i = 0; i < size; ++i) {
					float x = 0.0f + (i * 10.0f);
					irr::core::vector3df pos(x,10.0f,z);
					if (rawMap[j][i] == '#')
						Scene::addWallCube(pos);
				}
			}
		}

		void spawnBox(std::vector<std::string> &rawMap, size_t size,
			irr::scene::ISceneNode *boxNode)
		{
			for (int j = 0; j < size; ++j) {
				float z = 0.0f + (j * 10.0f);
				for (int i = 0; i < size; ++i) {
					float x = 0.0f + (i * 10.0f);
					irr::core::vector3df pos(x,10.0f,z);
					if (rawMap[j][i] == 'X')
						Scene::addBreakableCube(
							pos,
							boxNode);
				}
			}
		}

		void spawnPlayer(std::vector<std::string> &rawMap, size_t size,
			irr::scene::ISceneNode *playerNode)
		{
			for (int j = 0; j < size; ++j) {
				float z = 0.0f + (j * 10.0f);
				for (int i = 0; i < size; ++i) {
					float x = 0.0f + (i * 10.0f);
					irr::core::vector3df pos(x,10.0f,z);
					if (rawMap[j][i] == '1'
						|| rawMap[j][i] == '2'
						|| rawMap[j][i] == '3'
						|| rawMap[j][i] == '4')
						Scene::addPlayer(
							pos,
							playerNode,
							rawMap[j][i]);
				}
			}
		}
	}
}
