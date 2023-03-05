#pragma once
#ifndef __PHYSICS_MANAGER_H__
#define __PHYSICS_MANAGER_H__
#include "Manager.h"
class btDiscreteDynamicsWorld;
class btBroadphaseInterface;
class btCollisionDispatcher;
class btSequentialImpulseConstraintSolver;
class btDefaultCollisionConfiguration;
namespace Separity {
	class PhysicsManager : public Separity::Manager,
	                       public Singleton<Separity::PhysicsManager> {
		friend Singleton<PhysicsManager>;

		public:
		/// <summary>
		/// Crea un mundo dinámico discreto de bullet
		/// </summary>
		void initWorld();
		/// <summary>
		/// Borra el mundo de bullet y los objetos de este
		/// </summary>
		void deleteWorld();
		/// <summary>
		/// Método update que actualiza la simulación física del mundo
		/// </summary>
		virtual void update() override;
		/// <summary>
		///	Obtiene un puntero del mundo de bullet
		/// </summary>
		/// <returns>El mundo donde sucede la simulación</returns>
		btDiscreteDynamicsWorld* getWorld();
		/// <summary>
		/// Obtiene la instancia del Manager de físicas
		/// </summary>
		/// <returns>La instancia del Manager</returns>
		static PhysicsManager* getInstance();
		/// <summary>
		/// El destructor heredado del Manager
		/// </summary>
		virtual ~PhysicsManager() override;

		private:
		/// <summary>
		/// Constructor de la clase
		/// </summary>
		inline PhysicsManager();

		btDiscreteDynamicsWorld* world_;
		btBroadphaseInterface* broadphase_;
		btCollisionDispatcher* dispatcher_;
		btSequentialImpulseConstraintSolver* solver_;
		btDefaultCollisionConfiguration* collisionConfiguration_;
	};
}  // namespace Separity

#endif __PHYSICS_MANAGER_H__
