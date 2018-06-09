/*
** EPITECH PROJECT, 2017
**  cpp_indie_studio
** File description:
**      Assets creqtion wrapper
*/

#include <irrlicht/irrlicht.h>
#include "Engine/Engine.hpp"
#include "Game/Game.hpp"

namespace RR {
	namespace Scene {
		void setBaseLight() {
			auto sceneMgr =
				Engine::Engine::instance()->getSceneManager();
			//mSceneMgr.addLightSceneNode(0, irr::core::vector3df(50,5,50),
			//irr::video::SColorf(1.0f, 1.0f, 1.0f));
			sceneMgr->setAmbientLight(
				irr::video::SColor(0,60,60,60));
		}

		void setBaseCamera() {
			auto sceneMgr =
				Engine::Engine::instance()->getSceneManager();
			sceneMgr->addCameraSceneNodeMaya();
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
	}
}
