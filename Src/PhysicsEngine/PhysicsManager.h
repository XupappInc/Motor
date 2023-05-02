#pragma once
#ifndef __PHYSICS_MANAGER_H__
#define __PHYSICS_MANAGER_H__

#include "EntityComponent\Manager.h"
#include "SeparityExports\SeparityApi.h"

class btDynamicsWorld;
class btBroadphaseInterface;
class btCollisionDispatcher;
class btSequentialImpulseConstraintSolver;
class btDefaultCollisionConfiguration;

namespace Ogre {
	class SceneManager;
}

namespace Separity {
	class PhysicsDebugDrawer;
	class RigidBody;

	/// <summary>
	/// Clase que gestiona la f�sica del motor
	/// </summary>
	class _SEPARITY_API_ PhysicsManager
	    : public Separity::Manager,
	      public Singleton<Separity::PhysicsManager> {
		friend Singleton<PhysicsManager>;

		friend class RigidBody;

		public:

		/// <returns>Instancia de PhysicsManager</returns>
		static PhysicsManager* getInstance();

		/// <summary>
		/// LLama primero a los preUpdates de de los componentes.
		/// Prioriza los dem�s componentes de f�sica a los RigidBodies.
		/// </summary>
		virtual void update(const uint32_t& deltaTime) override;

		/// <summary>
		/// A�ade el componente al vector, si es un 
		/// RigidBody, lo a�ade a su vector propio.
		/// </summary>
		/// <param name="cmp">: componente a a�adir</param>
		void addComponent(Component* cmp) override;

		/// <summary>
		/// Inicializa los componentes, priorizando el resto 
		/// de componentes a los Rigidbodies. 
		/// </summary>
		void initComponents() override;

		/// <summary>
		/// Elimina el componente, teniendo en cuenta si es un Rigidbody.
		/// </summary>
		/// <param name="cmp">: componente a eliminar</param>
		void removeComponent(Separity::Component* cmp) override;

		/// <summary>
		/// Inicializa el mundo f�sico (y el debug).
		/// </summary>
		void start() override;

		/// <summary>
		/// Borra el mundo f�sico (y el debug).
		/// </summary>
		void clean() override;

		protected:
		
		/// <summary>
		/// Constructora de la clase
		/// </summary>
		PhysicsManager();

		private:

		/// <summary>
		///	Obtiene un puntero del mundo de bullet
		/// </summary>
		/// <returns>El mundo f�sico de bullet</returns>
		btDynamicsWorld* getWorld();

		/// <summary>
		/// Crea un mundo din�mico discreto de bullet.
		/// </summary>
		void initPhysicsWorld();

		/// <summary>
		/// Borra el mundo de bullet y los objetos de este.
		/// </summary>
		void deletePhysicsWorld();

		/// <summary>
		/// Crea el DebugDrawer y lo a�ade al bullet.
		/// </summary>
		void initDebug();

		btDynamicsWorld* world_;
		btBroadphaseInterface* broadphase_;
		btCollisionDispatcher* dispatcher_;
		btSequentialImpulseConstraintSolver* solver_;
		btDefaultCollisionConfiguration* collisionConfiguration_;
		PhysicsDebugDrawer* debugDrawer_;

		std::vector<Separity::RigidBody*> rigidBodies_;
	};
}  // namespace Separity

#endif __PHYSICS_MANAGER_H__
