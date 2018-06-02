/*
** EPITECH PROJECT, 2017
**  cpp_indie_studio, Engine
** File description:
**      Created by Amaury Bernard, the 5/15/18, at 2:13 PM
*/

#include <iostream>
#include "Engine/Engine.hpp"

extern Engine::Engine *Engine::Engine::_instance;

Engine::Engine::Engine(irr::video::E_DRIVER_TYPE videoType,
irr::core::dimension2d<irr::u32> dimension2d)
: _device(irr::createDevice(videoType, dimension2d)),
_EventReceiver(EventReceiver(*_device))
{
	if (!_device) {
		std::cerr << "Engine::Engine(): createDevice" << std::endl;
		throw std::exception();
	}
	_driver = _device->getVideoDriver();
	if (!_driver) {
		std::cerr << "Engine::Engine(): VideoDriver" << std::endl ;
		throw std::exception();
	}
	_sceneManager = _device->getSceneManager();
	if (!_sceneManager) {
		std::cerr << "Engine::Engine(): SceneManager" << std::endl ;
		throw std::exception();
	}
	_device->setEventReceiver(&_EventReceiver);
}

Engine::Engine::~Engine(void)
{
	_device->drop();
}

irr::IrrlichtDevice *Engine::Engine::getDevice() const
{
	return _device;
}

irr::video::IVideoDriver *Engine::Engine::getDriver() const
{
	return _driver;
}

irr::scene::ISceneManager *Engine::Engine::getSceneManager() const
{
	return _sceneManager;
}

Engine::EventReceiver *Engine::Engine::getEventReceiver()
{
	return &_EventReceiver;
}

void Engine::Engine::update(void)
{
	this->getSceneManager()->drawAll();
	this->getDriver()->endScene();
	_EventReceiver.update();
}


Engine::Engine *Engine::Engine::instance(void)
{
	if (!_instance)
		_instance = new Engine;
	return (_instance);
}

void Engine::Engine::drop(void)
{
	delete(_instance);
}
