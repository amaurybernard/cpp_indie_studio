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
		if (event.KeyInput.PressedDown) {
			if (_keysDown[event.KeyInput.Key] == KEYS_DOWN_TYPE::SHORT
				&& _keysDownTimer[event.KeyInput.Key]->max() >= 500)
				_keysDown[event.KeyInput.Key] = KEYS_DOWN_TYPE::LONG;
			} else {
				_keysDown[event.KeyInput.Key] = KEYS_DOWN_TYPE::SHORT;
				_keysDownTimer[event.KeyInput.Key]
				= new std::chrono::duration<std::chrono::milliseconds>;
			}
		} else {
			_keysDown[event.KeyInput.Key] = KEYS_DOWN_TYPE::NOT_DOWN;
		}

		if (event.KeyInput.Key == irr::KEY_ESCAPE && event.KeyInput.PressedDown)
			_device.closeDevice();
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
		key = KEYS_DOWN_TYPE::NOT_DOWN;
	}
}

void Engine::EventReceiver::update(void)
{
	//this->resetKeysDown();
}
