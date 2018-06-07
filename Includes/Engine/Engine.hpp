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
	private:
		/** Use instance() instead */
		Engine(void);
		static Engine				*_instance;
	public:
		~Engine(void);

	public:	/* methods */
		static Engine 			*instance(void);
		/* Useful ? */
		void	 			drop(void);
		EventReceiver 			*getEventReceiver();
		irr::IrrlichtDevice 		*getDevice() const;
		irr::scene::ISceneManager 	*getSceneManager() const;
		irr::video::IVideoDriver 	*getDriver() const;
		void 				update(void);
		/* @Return true in case of error */
		bool saveGame(const std::vector<std::string> map, std::string name = "");

	private:
		static constexpr irr::video::E_DRIVER_TYPE _videoType
		= irr::video::EDT_OPENGL;
		static constexpr irr::u32 		_dimVertical = 1080;
		static constexpr irr::u32		_dimHorizontal = 1920;
		irr::IrrlichtDevice			*_device;
		EventReceiver				_EventReceiver;
		irr::video::IVideoDriver		*_driver;
		irr::scene::ISceneManager		*_sceneManager;
	};
}

#endif /* !ENGINE_HPP */
