/*
** EPITECH PROJECT, 2017
**  cpp_indie_studio, EventReceiver
** File description:
**      Created by Amaury Bernard, the 5/31/18, at 3:18 PM
*/

#include "Engine/EventReceiver.hpp"

Engine::EventReceiver::EventReceiver(irr::IrrlichtDevice &device)
	: _device(device),
	  _btn(NONE)
{
	this->resetKeysDown();
}

bool Engine::EventReceiver::OnEvent(const irr::SEvent &event)
{
	if (event.EventType == irr::EET_KEY_INPUT_EVENT) {
		if (event.KeyInput.PressedDown)
			_keysDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
		if (event.KeyInput.Key == irr::KEY_ESCAPE && event.KeyInput.PressedDown)
			_device.closeDevice();
	} else if (event.EventType == irr::EET_GUI_EVENT) {
		auto id = event.GUIEvent.Caller->getID();
		if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED)
		{
			switch (id) {
			case PLAY:
				_btn = PLAY;
				break;
			case LAN:
				_btn = LAN;
				break;
			case BACKUP:
				_btn = BACKUP;
				break;
			case EXIT:
				_btn = EXIT;
				break;
			default:
				_btn = NONE;
				break;

			}
		}
	}
	return false;
}

bool Engine::EventReceiver::isKeyDown(irr::EKEY_CODE keyCode)
{
	return _keysDown[keyCode];
}

void Engine::EventReceiver::resetKeysDown(void)
{
	for (auto&& key : _keysDown) {
		key = false;
	}
}

void Engine::EventReceiver::update(void)
{
	this->resetKeysDown();
}
