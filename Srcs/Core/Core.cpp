/*
** EPITECH PROJECT, 2017
**  cpp_indie_studio, Core
** File description:
**      Created by Amaury Bernard, the 5/15/18, at 2:13 PM
*/

#include <iostream>
#include "Core/Core.hpp"

Core::Core::~Core(void)
{
	_device->drop();
}

Core::Core::Core(irr::video::E_DRIVER_TYPE videoType,
	irr::core::dimension2d<irr::u32> dimension2d)
{
	_device = irr::createDevice(videoType, dimension2d);
	if (!_device) {
		std::cerr << "Core::Core() init fail" << std::endl;
		throw std::exception();
	}
}

irr::IrrlichtDevice *Core::Core::getDevice() const
{
	return _device;
}

