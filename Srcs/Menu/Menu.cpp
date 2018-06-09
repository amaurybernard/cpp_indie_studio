//
// EPITECH PROJECT, 2018
// Menu.cpp
// File description:
// Menu.cpp
//

#include "../Menu/Menu.hpp"

Menu::Menu(Engine::Engine* engine) :
	_engine(engine),
	_env(_engine->getDevice()->getGUIEnvironment())
{}

Menu::~Menu()
{}

void Menu::createButton()
{
//const irr::core::dimension2du &screenSize = driver->irr::video::IVideoDriver::getScreenSize();
	_env->addButton(irr::core::rect<irr::s32>(100, 100, 500, 180), 0,
			Engine::buttonId_e::ONE_PLAYER, L"1 PLAYER", L"1 PLAYER");
	_env->addButton(irr::core::rect<irr::s32>(100, 200, 500, 280), 0,
                        Engine::buttonId_e::TWO_PLAYER, L"2 PLAYERS", L"2 PLAYERS");
	_env->addButton(irr::core::rect<irr::s32>(100, 300, 500, 380), 0,
                        Engine::buttonId_e::EXIT, L"OPTIONS", L"OPTIONS");
	_env->addButton(irr::core::rect<irr::s32>(100, 400, 500, 480), 0,
                        Engine::buttonId_e::EXIT, L"EXIT", L"EXIT");
}

void Menu::actionButton(Engine::buttonId_e btn, irr::IrrlichtDevice *device)
{
	switch (btn)
	{
	case Engine::buttonId_e::ONE_PLAYER:
		break;
	case Engine::buttonId_e::TWO_PLAYER:
		break;
	case Engine::buttonId_e::OPTION:
		break;
	case Engine::buttonId_e::EXIT:
		device->closeDevice();
		break;
	case Engine::buttonId_e::NONE:
		break;
	}
}

void Menu::runMenu()
{
	auto device = _engine->getDevice();
	auto driver = _engine->getDriver();
	auto scene = _engine->getSceneManager();
	auto event = _engine->getEventReceiver();
//	irr::video::ITexture* images = driver->getTexture("../../Image/MenuBackground.jpg");

	createButton();
	while(device->run())
	{
		auto btn = event->getBtn();
		if (btn != Engine::buttonId_e::NONE)
			actionButton(btn, device);
		driver->beginScene(true, true,
				   irr::video::SColor(1, 82, 108, 152));
/*		driver->draw2DImage(images, irr::core::position2d<irr::s32>(50,50),
				    irr::core::rect<irr::s32>(0,0,342,224), 0,
				    irr::video::SColor(255,255,255,255), true); */
		scene->drawAll();
		_env->drawAll();
		driver->endScene();
	}
	device->drop();
}
