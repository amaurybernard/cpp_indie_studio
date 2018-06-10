/*
** EPITECH PROJECT, 2017
**  cpp_indie_studio, Menu
** File description:
**      Created by Amaury Bernard, the 6/10/18, at 2:17 PM
*/

#ifndef CPP_INDIE_STUDIO_MENU_HPP
#define CPP_INDIE_STUDIO_MENU_HPP

#include <irrlicht/IGUIEnvironment.h>
#include <Engine/Engine.hpp>
#include "Menu/BtnEnum.hpp"

namespace Menu {

	class Menu {
	public:
		Menu(void);
		Game::Game *getSelectedGame(void);
	private:
		void createButton();
		Engine::Engine *_engine = Engine::Engine::instance();
		/** Contain menu's buttons */
		irr::gui::IGUIEnvironment *_guiEnv = _engine->getDevice()->getGUIEnvironment();
		size_t _btnSize;
	};
}
#endif /* !CPP_INDIE_STUDIO_MENU_HPP*/
