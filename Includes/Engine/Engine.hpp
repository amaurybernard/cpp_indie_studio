/*
** EPITECH PROJECT, 2017
**  cpp_indie_studio, Engine
** File description:
**      Created by Amaury Bernard, the 5/15/18, at 2:13 PM
*/

#ifndef ENGINE_HPP
#define ENGINE_HPP
#include <irrlicht/irrlicht.h>
#include "EventReceiver.hpp"

/** The Engine class keep all basic object needed by the graphical library */
namespace Engine {
	class Engine {
	/* Public things: */
	public:
		Engine(irr::video::E_DRIVER_TYPE videoType
		= irr::video::EDT_OPENGL,
		irr::core::dimension2d<irr::u32> dimension2d
		= irr::core::dimension2d<irr::u32>(1920, 1080));
		~Engine(void);

	public:	/* methods */
		EventReceiver *getEventReceiver();
		irr::IrrlichtDevice *getDevice() const;
		irr::scene::ISceneManager *getSceneManager() const;
		irr::video::IVideoDriver *getDriver() const;
		void 				update(void);

	/* Private things */
	private:
		irr::IrrlichtDevice			*_device;
		EventReceiver				_EventReceiver;
		irr::video::IVideoDriver		*_driver;
		irr::scene::ISceneManager		*_sceneManager;
	};
}

#endif /* !ENGINE_HPP*/
