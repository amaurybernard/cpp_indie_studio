/*
** EPITECH PROJECT, 2017
**  cpp_indie_studio, Menu
** File description:
**      Created by Amaury Bernard, the 6/10/18, at 2:17 PM
*/

#include <Game/Game.hpp>
#include "Menu/Menu.hpp"

Menu::Menu::Menu(void)
{
	this->createButton();
	_engine->getDriver()->beginScene(true, true,
		irr::video::SColor(1, 82, 108, 152));
	_engine->getSceneManager()->drawAll();
	_guiEnv->drawAll();
	_engine->getDriver()->endScene();
}

/* todo everything: take a vector<string> */
void Menu::Menu::createButton()
{
	_btnSize = 5;
	_guiEnv->addButton(irr::core::rect<irr::s32>(100, 100, 500, 180), 0,
		ButtonId::PLAY_KB, L"Play at 2", L"1 PLAYER");
	_guiEnv->addButton(irr::core::rect<irr::s32>(100, 100, 500, 180), 0,
		ButtonId::PLAY_IA, L"PLAY with IA", L"1 PLAYER");
	_guiEnv->addButton(irr::core::rect<irr::s32>(100, 200, 500, 280), 0,
		ButtonId::PLAY_LAN, L"Play on LAN", L"MULTIPLAYER");
	_guiEnv->addButton(irr::core::rect<irr::s32>(100, 300, 500, 380), 0,
		ButtonId::BACKUP, L"Play from Backup", L"BACKUP");
	_guiEnv->addButton(irr::core::rect<irr::s32>(100, 400, 500, 480), 0,
		ButtonId ::EXIT, L"EXIT", L"EXIT");
}

Game::Game *Menu::Menu::getSelectedGame(void)
{
	ButtonId btn = (ButtonId)_engine->getEventReceiver()->getBtnId();
	switch (btn)
	{
	case ButtonId::PLAY_KB:
		return new Game::Game();
	case ButtonId::PLAY_IA:
		return new Game::Game();
		break;
	case ButtonId::PLAY_LAN:
		return new Game::Game();
		break;
	case ButtonId::BACKUP:
		//Change the screen and show an other menu
		return new Game::Game();
		break;
	case ButtonId::EXIT:
		_engine->getDevice()->closeDevice();
		return nullptr;
	}
	return nullptr;
}
