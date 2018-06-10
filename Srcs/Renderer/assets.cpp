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
#include <locale>
#include <codecvt>

namespace RR {
	irr::core::vector3df m3df(float x, float y, float z)
	{
		return irr::core::vector3df(x,y,z);
	}

	void printScore(char *player, int score, irr::core::rect<irr::s32> rec)
	{
		irr::core::stringw str("player ");
		irr::core::stringw num(std::to_string(score).c_str());
		auto device = Engine::Engine::instance()->getDevice();
		irr::gui::IGUIFont* font =
			device->getGUIEnvironment()->getFont(
				"./textures/myfont.xml");
		str += player;
		str += " score: ";
		str += num;

		font->draw(str,
			rec,
			irr::video::SColor(255,255,255,255));
	}

	void printLife(char *player, int life, irr::core::rect<irr::s32> rec)
	{
		irr::core::stringw str("player ");
		irr::core::stringw num(std::to_string(life).c_str());
		auto device = Engine::Engine::instance()->getDevice();
		irr::gui::IGUIFont* font =
			device->getGUIEnvironment()->getFont(
				"./textures/myfont.xml");
		str += player;
		str += " life: ";
		str += num;

		font->draw(str,
			rec,
			irr::video::SColor(255,255,255,255));
	}
	namespace Scene {
		void setBaseLight() {
			auto sceneMgr =
				Engine::Engine::instance()->getSceneManager();
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
			//sceneMgr->getMeshManipulator()->makePlanarTextureMapping(newPlayer->getMesh(0),0.004f);
			node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
			return newPlayer;
		}

		irr::scene::IAnimatedMesh *addBomb(
			irr::core::vector3df &pos,
			irr::scene::ISceneNode *bombNode
		)
		{
			auto sceneMgr =
				Engine::Engine::instance()->getSceneManager();
			auto driver =
				Engine::Engine::instance()->getDriver();
			irr::scene::IAnimatedMesh* newBomb =
				sceneMgr->getMesh("./models/bomb.obj");
			irr::scene::ISceneNode* node =
				sceneMgr->addAnimatedMeshSceneNode(newBomb,
					bombNode);
			node->setPosition(RR::m3df(0.0f, -5.0f, 0.0f) + pos);
			node->setScale(RR::m3df(5.0f, 5.0f, 5.0f));
			node->setMaterialTexture(0,
				driver->getTexture("./models/bombbody_BaseColor.png"));
			//sceneMgr->getMeshManipulator()->makePlanarTextureMapping(newBomb->getMesh(0),0.004f);
			node->setMaterialFlag(irr::video::EMF_LIGHTING,false);
			return newBomb;
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

		void spawnBomb(std::vector<std::string> &rawMap, size_t size,
			irr::scene::ISceneNode *bombNode)
		{
			for (int j = 0; j < size; ++j) {
				float z = 0.0f + (j * 10.0f);
				for (int i = 0; i < size; ++i) {
					float x = 0.0f + (i * 10.0f);
					irr::core::vector3df pos(x,10.0f,z);
					if (rawMap[j][i] == 'o')
						Scene::addBomb(pos, bombNode);
				}
			}
		}

		void spawnFlame(std::vector<std::string> &rawMap, size_t size,
			irr::scene::ISceneNode *FlameNode)
		{
			for (int j = 0; j < size; ++j) {
				float z = 0.0f + (j * 10.0f);
				for (int i = 0; i < size; ++i) {
					float x = 0.0f + (i * 10.0f);
					irr::core::vector3df pos(x,10.0f,z);
					if (rawMap[j][i] == 'f')
						Scene::addWallCube(pos);
				}
			}
		}

		void drawText()
		{
			RR::printScore("1", 23, irr::core::rect<irr::s32>(1600,10,300,50));
			RR::printScore("2", 44, irr::core::rect<irr::s32>(40,10,300,50));
			RR::printScore("3", 67, irr::core::rect<irr::s32>(40,950,300,50));
			RR::printScore("4", 38, irr::core::rect<irr::s32>(1600,950,300,50));
			RR::printLife("1", 23, irr::core::rect<irr::s32>(1600,40,300,50));
			RR::printLife("2", 44, irr::core::rect<irr::s32>(40,40,300,50));
			RR::printLife("3", 67, irr::core::rect<irr::s32>(40,910,300,50));
			RR::printLife("4", 38, irr::core::rect<irr::s32>(1600,910,300,50));
		}
	}
}
