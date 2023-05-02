#pragma once
#ifndef BEHAVIOUR_H
#define BEHAVIOUR_H

#include "SeparityExports\SeparityApi.h"
#include <EntityComponent\Component.h>

#include <string>

namespace luabridge {
	class LuaRef;
}

class lua_State;

namespace Separity {

	/// <summary>
	/// Clase que representa un script de comportamiento. El script se definira
	/// en Lua y se utilizara esta clase para poder gestionar su ciclo de vida y
	/// llamada a metodos en C++.
	/// </summary>
	class _SEPARITY_API_ Behaviour : public Component {
		friend class LuaManager;

		public:
		__CMPTYPE_DECL__(Separity::_SCRIPT)
		__CMPID_DECL__(Separity::_BEHAVIOUR)

		/// <summary>
		/// Constructor vacio, asigna nullptr a la LuaRef, sera necesario
		/// asignarla posteriormente con setLuaScript()
		/// </summary>
		Behaviour(std::string name);
		/// <summary>
		/// Construye un Behaviour con la LuaRef se le pase
		/// </summary>
		/// <param name="behaviourLua">LuaRef del script .lua que se desea
		/// vincular a esta clase</param>
		Behaviour(std::string name, luabridge::LuaRef* behaviourLua);
		/// <summary>
		/// El destructor se encarga de borrar el puntero de LuaRef
		/// </summary>
		virtual ~Behaviour();

		/// <summary>
		/// Asigna valor a la LuaRef que se corresponde al script .lua
		/// </summary>
		/// <param name="behaviourLua">La LuaRef obtenida al hacer un
		/// luabridge::getGlobal con el script .lua</param>
		void setLuaScript(luabridge::LuaRef* behaviourLua);

		/// <summary>
		/// Awake se llama tras la creacion de todos los scripts, como primer
		/// metodo
		/// </summary>
		virtual void awake() override;
		/// <summary>
		/// Start se llama tras awake, al comienzo de la ejecucion
		/// </summary>

		virtual void start() override;

		/// <summary>
		/// Update se llama en cada frame
		/// </summary>
		/// <param name="deltaTime">Tiempo que ha transcurrido desde el ultimo
		/// frame</param>
		virtual void update(const uint32_t& deltaTime) override;
		/// <summary>
		/// Metodo que se llama cuando se produce una colision entre 2 entidades
		/// con RigidBody
		/// </summary>
		/// <param name="other">Entidad con la que ha colisionado</param>
		virtual void onCollisionEnter(Entity* other);
		/// <summary>
		/// Metodo que se llama cuando se termina una colision entre 2
		/// entidades con RigidBody
		/// </summary>
		/// <param name="other">Entidad con la que ha colisionado</param>
		virtual void onCollisionExit(Entity* other);
		/// <summary>
		/// Metodo que se llama cuando se mantiene una colision entre 2
		/// entidades con RigidBody, se llama en cada frame mientras se mantega
		/// la colision
		/// </summary>
		/// <param name="other">Entidad con la que ha colisionado</param>
		virtual void onCollisionStay(Entity* other);
		/// <summary>
		/// Metodo que se llama cuando se hace click en el boton
		/// </summary>
		virtual void onButtonClick();
		/// <summary>
		/// Metodo que se llama cuando ya no se hace click en el boton
		/// </summary>
		virtual void onButtonReleased();
		/// <summary>
		/// Metodo que se llama la primera vez que se pone el raton sobre el boton
		/// </summary>
		virtual void onButtonHover();
		/// <summary>
		/// Metodo que se llama cuando el raton sale del boton
		/// </summary>
		virtual void onButtonUnhover();

		/// <summary>
		/// Devuelve la LuaRef al behaviour en Lua, requiere Luabridge, usar bajo responsabilidad
		/// </summary>
		/// <returns>Una LuaRef al script en Lua</returns>
		luabridge::LuaRef* getBehaviourLua();

		protected:
		/// <summary>
		/// LuaRef del script. Esta clase representa el script .lua en C++,
		/// pudiendo usarlo para llamar a todos sus metodos en esta clase
		/// </summary>
		luabridge::LuaRef* behaviourLua_;
		lua_State* L_;
		/// <summary>
		/// Nombre del script
		/// </summary>
		std::string name_;
	};
}  // namespace Separity

#endif  // !BEHAVIOUR_H