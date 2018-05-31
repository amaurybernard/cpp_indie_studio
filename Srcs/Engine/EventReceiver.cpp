/*
** EPITECH PROJECT, 2017
**  cpp_indie_studio, EventReceiver
** File description:
**      Created by Amaury Bernard, the 5/31/18, at 3:18 PM
*/

#include "Engine/EventReceiver.hpp"

Engine::EventReceiver::EventReceiver(irr::IrrlichtDevice &device)
: _device(device)
{
	this->resetKeysDown();
}

bool Engine::EventReceiver::OnEvent(const irr::SEvent &event)
{
	if (event.EventType == irr::EET_KEY_INPUT_EVENT) {
		if (event.KeyInput.PressedDown && _keysDown[event.KeyInput.Key] != true)
			_keysDown[event.KeyInput.Key] = true;
		if (event.KeyInput.Key == irr::KEY_ESCAPE && event.KeyInput.PressedDown)
			_device.closeDevice();
		if (event.KeyInput.Key == irr::KEY_SPACE && event.KeyInput.PressedDown) {
			puts("Event: space is true");
			_keysDown[irr::KEY_SPACE] = true;
		} else if (event.KeyInput.Key == irr::KEY_SPACE)
			puts("Event: space is false");
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
	//this->resetKeysDown();
}
