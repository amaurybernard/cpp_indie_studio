/*
** EPITECH PROJECT, 2017
**  cpp_indie_studio
** File description:
**      Assets creqtion wrapper
*/

#include <string>
#include <irr/irrlicht.h>

namespace RR {
	namespace Scene {
		irr::scene::IMeshSceneNode *addMapCube(
			irr::scene::ISceneManager &sceneMgr,
			irr::video::IVideoDriver &driver,
			irr::core::vector3df &position
		)
		{
			irr::scene::IMeshSceneNode *newCube =
				sceneMgr.addCubeSceneNode(
					10.0f,
					0,
					-1,
					position
				);
			//std::string path = irr::io::IFileSystem::getWorkingDirectory();
			newCube->setMaterialTexture(0, driver.getTexture("./mapBlock.jpg"));
			newCube->setMaterialFlag(irr::video::EMF_LIGHTING,
				false);
			return newCube;
		}

		irr::scene::IMeshSceneNode *addBreakableCube(
			irr::scene::ISceneManager &sceneMgr,
			irr::video::IVideoDriver &driver,
			irr::core::vector3df &position
		)
		{
			irr::scene::IMeshSceneNode *newCube =
				sceneMgr.addCubeSceneNode(
					10.0f,
					0,
					-1,
					position
				);
			//std::string path = irr::io::IFileSystem::getWorkingDirectory();
			newCube->setMaterialTexture(0, driver.getTexture("./breakableBlock.png"));
			newCube->setMaterialFlag(irr::video::EMF_LIGHTING,
				false);
			return newCube;
		}
	}
}
