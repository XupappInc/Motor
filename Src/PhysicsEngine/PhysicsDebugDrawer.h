#pragma once
#ifndef PHYSICS_DEBUG_DRAWER_H
#define PHYSICS_DEBUG_DRAWER_H

#include <LinearMath\btIDebugDraw.h>
#include <vector>

namespace Ogre {
	class SceneManager;
	class ManualObject;
}

namespace Separity {
	/// <summary>
	/// Clase que se encarga de dibujar los colliders de bullet
	/// </summary>
	class PhysicsDebugDrawer : public btIDebugDraw {
		
		public:
		PhysicsDebugDrawer(Ogre::SceneManager* sceneMgr);
		~PhysicsDebugDrawer();

		/// <summary>
		/// Borra las lineas dibujadas anteriormente
		/// </summary>
		void clearLines();

		/// <summary>
		/// Dibuja una linea usando Ogre (se llama por bullet de forma automatica)
		/// </summary>
		/// <param name="from">Punto de origen</param>
		/// <param name="to">Punto final</param>
		/// <param name="color">Color de la linea</param>
		void drawLine(const btVector3& from, const btVector3& to,
		              const btVector3& color) override;

		void drawContactPoint(const btVector3& PointOnB,
		                              const btVector3& normalOnB,
		                              btScalar distance, int lifeTime,
		                              const btVector3& color) override;

		void reportErrorWarning(const char* warningString) override;

		void draw3dText(const btVector3& location,
		                        const char* textString) override;

		/// <summary>
		/// Asigna valor a los flags del DebugDrawer
		/// </summary>
		/// <param name="debugMode">Flags de DebugMode de bullet</param>
		void setDebugMode(int debugMode) override;

		/// <summary>
		/// Devuelve los flags del DebugDrawer de bullet
		/// </summary>
		/// <returns>Un entero con los flags</returns>
		int getDebugMode() const override;
		void setSceneManager(Ogre::SceneManager* sceneManager);
		private:
		Ogre::SceneManager* sceneMngr_;
		DebugDrawModes debugMode_;

		std::vector<Ogre::ManualObject*> lines_;
	};
}  // namespace Separity

#endif  // !PHYSICS_DEBUG_DRAWER_H