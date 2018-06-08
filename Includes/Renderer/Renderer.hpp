//
// Created by artha on 02.06.18.
//

#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <irrlicht/irrlicht.h>
#include "Engine/Engine.hpp"

namespace RR {
	class Renderer {
		/* Constructor and destructor */
		public:
		Renderer(Engine::Engine &engine);
		Renderer(const Renderer&) = default;
		~Renderer() = default;

		/* operator */
		public:
		Renderer &operator=(const Renderer&);

		public:	/* getter and setter */
		Engine::Engine &getEngine() const;
		void setEngine(Engine::Engine &engine);

		/* public function */
		public:
		void init();
		void render();

		/* protected attribute */
		protected:
		Engine::Engine &mEngine;
		irr::IrrlichtDevice &mDevice;
		irr::video::IVideoDriver &mDriver;
		irr::scene::ISceneManager &mSceneMgr;
	};

	namespace Scene {
		irr::scene::IMeshSceneNode *addMapCube(
			irr::scene::ISceneManager &,
			irr::video::IVideoDriver &,
			irr::core::vector3df &
		);

		irr::scene::IMeshSceneNode *addBreakableCube(
			irr::scene::ISceneManager &,
			irr::video::IVideoDriver &,
			irr::core::vector3df &
		);
	}
}
#endif //RENDERER_HPP