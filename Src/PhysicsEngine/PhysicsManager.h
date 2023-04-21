#pragma once
#ifndef __PHYSICS_MANAGER_H__
#define __PHYSICS_MANAGER_H__
#include "Manager.h"
class btDynamicsWorld;
class btBroadphaseInterface;
class btCollisionDispatcher;
class btSequentialImpulseConstraintSolver;
class btDefaultCollisionConfiguration;

namespace Ogre {
	class SceneManager;
}  // namespace Ogre
namespace Separity {
	class PhysicsDebugDrawer;
	class PhysicsManager : public Separity::Manager,
	                       public Singleton<Separity::PhysicsManager> {
		friend Singleton<PhysicsManager>;

		public:
		/// <summary>
		/// Constructor de la clase
		/// </summary>
		inline PhysicsManager();
		/// <summary>
		/// Obtiene la instancia del Manager de físicas
		/// </summary>
		/// <returns>La instancia del Manager</returns>
		static PhysicsManager* getInstance();
		/// <summary>
		/// Dibuja el debug
		/// </summary>
		void debug();
		/// <summary>
		/// Borra el mundo de bullet y los objetos de este
		/// </summary>
		void deleteWorld();
		/// <summary>
		/// Método update que actualiza la simulación física del mundo
		/// </summary>
		virtual void update(const uint32_t& deltaTime) override;
		/// <summary>
		///	Obtiene un puntero del mundo de bullet
		/// </summary>
		/// <returns>El mundo donde sucede la simulación</returns>
		btDynamicsWorld* getWorld();
		
		void clean() override;
		
		private:
		/// <summary>
		/// Crea un mundo dinámico discreto de bullet
		/// </summary>
		void initWorld();
		/// <summary>
		/// Crea el DebugDrawer y lo añade al bullet
		/// </summary>
		void initDebug();
		

		btDynamicsWorld* world_;
		btBroadphaseInterface* broadphase_;
		btCollisionDispatcher* dispatcher_;
		btSequentialImpulseConstraintSolver* solver_;
		btDefaultCollisionConfiguration* collisionConfiguration_;
		PhysicsDebugDrawer* debugDrawer_;
	};
}  // namespace Separity

#endif __PHYSICS_MANAGER_H__
