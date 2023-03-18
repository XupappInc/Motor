#pragma once
#ifndef PHYSICS_DEBUG_DRAWER_H
#define PHYSICS_DEBUG_DRAWER_H

#include <LinearMath\btIDebugDraw.h>

namespace Ogre {
	class SceneManager;
}

namespace Separity {
	class PhysicsDebugDrawer : public btIDebugDraw {
		
		public:
		PhysicsDebugDrawer(Ogre::SceneManager* sceneMgr);
		~PhysicsDebugDrawer();

		void drawLine(const btVector3& from, const btVector3& to,
		              const btVector3& color) override;

		void drawBox(const btVector3& bbMin, const btVector3& bbMax,
		             const btVector3& color) override;

		private:
		Ogre::SceneManager* sceneMngr_;
	};
}  // namespace Separity

#endif  // !PHYSICS_DEBUG_DRAWER_H