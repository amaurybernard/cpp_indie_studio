//
// Created by artha on 02.06.18.
//

#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <irrlicht/irrlicht.h>
#include "Engine/Engine.hpp"

namespace Renderer {
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
	};
}
#endif //RENDERER_HPP
