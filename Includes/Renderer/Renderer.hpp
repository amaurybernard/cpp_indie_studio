//
// Created by artha on 02.06.18.
//

#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <irrlicht/irrlicht.h>
#include "Engine/Engine.hpp"
#include "Game/Map.hpp"

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
		void init(Game::Map &, size_t);
		void render();
		void render(Game::Map &, size_t size);

		/* protected attribute */
		protected:
		Engine::Engine &mEngine;
		irr::IrrlichtDevice &mDevice;
		irr::video::IVideoDriver &mDriver;
		irr::scene::ISceneManager &mSceneMgr;
		irr::video::SColor mBackColor;
		irr::scene::ISceneNode *mBoxNode;
		irr::scene::ISceneNode *mPlayerNode;
		irr::scene::ISceneNode *mBombNode;
		irr::scene::ISceneNode *mFlameNode;
		irr::video::ITexture *mBackground;
	};

	namespace Scene {
		irr::scene::IMeshSceneNode *addGroundCube(irr::core::vector3df &
		);

		irr::scene::IMeshSceneNode *addBreakableCube(
			irr::core::vector3df &,
			irr::scene::ISceneNode *
		);

		void spawnWall(std::vector<std::string> &, size_t);
		void spawnBox(
			std::vector<std::string> &,
		        size_t,
			irr::scene::ISceneNode *
		);

		void spawnPlayer(
			std::vector<std::string> &,
			size_t,
			irr::scene::ISceneNode *
		);

		void spawnBomb(
			std::vector<std::string> &,
			size_t,
			irr::scene::ISceneNode *
		);

		void spawnFlame(
			std::vector<std::string> &,
			size_t,
			irr::scene::ISceneNode *
		);

		void drawText();

		void spawnGround(size_t);
		void setBaseLight();
		void setBaseCamera(size_t);
	}
}
#endif //RENDERER_HPP