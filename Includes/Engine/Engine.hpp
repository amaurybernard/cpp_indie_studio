/*
** EPITECH PROJECT, 2017
**  cpp_indie_studio, Engine
** File description:
**      Created by Amaury Bernard, the 5/15/18, at 2:13 PM
*/

#ifndef CPP_INDIE_STUDIO_CORE_HPP
#define CPP_INDIE_STUDIO_CORE_HPP
#include <irrlicht/irrlicht.h>

/** The Engine class keep all basic object needed by the graphical library */
namespace Engine {
	class Engine: public irr::IrrlichtDevice {
	public:
		Engine(irr::video::E_DRIVER_TYPE videoType
		= irr::video::EDT_OPENGL,
		irr::core::dimension2d<irr::u32> dimension2d
		= (irr::core::dimension2d<irr::u32>(1920, 1080)));
		~Engine(void);

	/* Public methods */
	public:
		irr::IrrlichtDevice *getDevice() const;
		irr::scene::ISceneManager *getSceneManager() const;

	/* Private variables */
	private:
		irr::scene::ISceneManager		*_sceneManager;
	};
}

#endif /* !CPP_INDIE_STUDIO_CORE_HPP*/
