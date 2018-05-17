/*
** EPITECH PROJECT, 2017
**  cpp_indie_studio, Core
** File description:
**      Created by Amaury Bernard, the 5/15/18, at 2:13 PM
*/

#ifndef CPP_INDIE_STUDIO_CORE_HPP
#define CPP_INDIE_STUDIO_CORE_HPP
#include <irrlicht/irrlicht.h>
namespace Core {
	class Core {
	public:
		Core(irr::video::E_DRIVER_TYPE videoType
		= irr::video::EDT_OPENGL,
		irr::core::dimension2d<irr::u32> dimension2d
		= irr::core::dimension2d<irr::u32>(1920, 1080));
		~Core(void);

	private:
		irr::IrrlichtDevice			*_device;
	public:
		irr::IrrlichtDevice *getDevice() const;
	private:
		irr::video::IVideoDriver		*_driver;
		irr::scene::ISceneManager		*_sceneManager;

	};
}

#endif /* !CPP_INDIE_STUDIO_CORE_HPP*/
