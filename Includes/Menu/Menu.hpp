//
// EPITECH PROJECT, 2018
// Menu.hpp
// File description:
// Menu.hpp
//

#ifndef MENU_HPP
#define MENU_HPP
#include <irrlicht/irrlicht.h>
#include "../Engine/Engine.hpp"

class Menu {
public:
	Menu(Engine::Engine* engine);
	~Menu();
	void runMenu();

private:
	void createButton();
	void actionButton(Engine::buttonId_e btn, irr::IrrlichtDevice *device);

private:
	Engine::Engine *_engine;
	irr::gui::IGUIEnvironment *_env;
};

#endif /* !MENU_HPP */
