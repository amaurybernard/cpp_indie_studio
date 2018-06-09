/*
** EPITECH PROJECT, 2017
**  cpp_indie_studio, EventReceiver
** File description:
**      Created by Amaury Bernard, the 5/31/18, at 3:18 PM
*/

#ifndef EVENTRECEIVER_HPP
#define EVENTRECEIVER_HPP
#include <irrlicht/irrlicht.h>
#include <vector>
#include <ctime>
#include <chrono>

namespace Engine {
	class EventReceiver : public irr::IEventReceiver {
	/* Public things */
	enum KEYS_DOWN_TYPE {
		NOT_DOWN = 0,
		SHORT,
		LONG
	};
	public:
		EventReceiver(irr::IrrlichtDevice &device);
	public: /* Methods */
		virtual bool 	OnEvent(const irr::SEvent& event);
		bool 		isKeyDown(irr::EKEY_CODE keyCode);
		/** Have to be executed at each frame
		** todo check is this is nececsary
		*/
		void 		update(void);
	/* Private things */
	private: /* Methods */
		void		resetKeysDown(void);
	private: /* variables */
		irr::IrrlichtDevice 	&_device;
		KEYS_DOWN_TYPE 		_keysDown[irr::KEY_KEY_CODES_COUNT];
		std::vector<std::chrono::duration<std::chrono::milliseconds> const*>	_keysDownTimer;
	};
}

#endif /* !EVENTRECEIVER_HPP*/
