/*
** EPITECH PROJECT, 2017
**  cpp_indie_studio
** File description:
**      Assets creqtion wrapper
*/

#include <irr/irrlicht.h>

namespace Renderer::Scene {
	irr::scene::IMeshSceneNode *addCube(irr::scene::ISceneManager &sceneMgr)
	{
		irr::scene::IMeshSceneNode *newCube =
			sceneMgr.addCubeSceneNode(
				10.0f,
				0,
				-1,
				irr::core::vector3df(0.0f, 0.0f, 20.0f)
		);

		newCube->setMaterialFlag(irr::video::EMF_WIREFRAME, true);
		return newCube;
	}
}
