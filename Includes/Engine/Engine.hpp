/*
** EPITECH PROJECT, 2017
**  cpp_indie_studio, Engine
** File description:
**      Created by Amaury Bernard, the 5/15/18, at 2:13 PM
*/

#ifndef ENGINE_HPP
#define ENGINE_HPP
#include <string>
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
		static constexpr irr::video::E_DRIVER_TYPE VIDEO_TYPE
		= irr::video::EDT_OPENGL;
		static constexpr irr::u32 		DIM_VERTICAL = 1080;
		static constexpr irr::u32		DIM_HORIZONTAL = 1920;
		static constexpr char	SAVEDGAMES_DIR[] = "SavedGames/";
		irr::IrrlichtDevice			*_device;
		EventReceiver				_EventReceiver;
		irr::video::IVideoDriver		*_driver;
		irr::scene::ISceneManager		*_sceneManager;
	};
}

#endif /* !ENGINE_HPP */
