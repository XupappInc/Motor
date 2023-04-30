#pragma once
#ifndef __PHYSICS_MANAGER_H__
#define __PHYSICS_MANAGER_H__

#include "SeparityExports\SeparityApi.h"
#include "EntityComponent\Manager.h"

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
	class RigidBody;
	class _SEPARITY_API_ PhysicsManager
	    : public Separity::Manager,
	                       public Singleton<Separity::PhysicsManager> {
		friend Singleton<PhysicsManager>;

		friend class RigidBody;

		public:
		
		
		/// <summary>
		/// Obtiene la instancia del Manager de f�sicas
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
		/// M�todo update que actualiza la simulaci�n f�sica del mundo
		/// </summary>
		virtual void update(const uint32_t& deltaTime) override;
		
		
		/// <summary>
		/// A�ade el componente al vector, si es un rigidBody lo a�ade al vector de rigidBodies
		/// </summary>
		/// <param name="cmp">Componente que se quiere a�adir al manager</param>
		void addComponent(Component* cmp) override;
		/// <summary>
		/// inicializa todos los componentes
		/// </summary>
		void initComponents() override;
		/// <summary>
		/// elimina el componente
		/// </summary>
		/// <param name="cmp">componente a eliminar</param>
		void removeComponent(Separity::Component* cmp) override;
		/// <summary>
		/// hace el start de las fisicas
		/// </summary>
		void start() override;
		/// <summary>
		/// borra todos los componentes y rigidbodys
		/// </summary>
		void clean() override;

		protected:
		/// <summary>
		/// Constructor de la clase
		/// </summary>
		PhysicsManager();
		
		private:
		/// <summary>
		///	Obtiene un puntero del mundo de bullet
		/// </summary>
		/// <returns>El mundo donde sucede la simulaci�n</returns>
		btDynamicsWorld* getWorld();
		/// <summary>
		/// Crea un mundo din�mico discreto de bullet
		/// </summary>
		void initWorld();
		/// <summary>
		/// Crea el DebugDrawer y lo a�ade al bullet
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
