#pragma once
#ifndef __LUA_MANAGER_H__
#define __LUA_MANAGER_H__

#include "SeparityExports/SeparityApi.h"

#include "EntityComponent/Manager.h"

#include <string>

class lua_State;

namespace Separity {
	class Behaviour;
	/// <summary>
	/// Clase encargada de gestionar la maquina virtual de Lua y los scripts de comportamiento
	/// </summary>
	class _SEPARITY_API_ LuaManager : public Separity::Manager,
	                   public Singleton<Separity::LuaManager> {
		friend Singleton<LuaManager>;

		public:
		/// <summary>
		/// Registra las clases básicas en Lua, principalmente Behaviour
		/// </summary>
		void registerClasses();

		/// <summary>
		/// Carga el script y crea un Behaviour al que asociarlo, tambien se
		/// encarga de añadirlo a este manager y a su entidad
		/// </summary>
		/// <param name="name">Nombre del script, sin extension</param>
		/// <param name="ent">Entidad a la que añadir el Behaviour</param>
		/// <returns>El Behaviour creado</returns>
		Behaviour* loadScript(std::string name, Entity* ent);

		/// <summary>
		/// Metodo que devuelve el lua_State de este manager. Encargado de
		/// gestionar todos los scripts de comportamiento del motor
		/// </summary>
		/// <returns>El lua_State que representa la maquina virtual de
		/// Lua</returns>
		lua_State* getLuaState();

		/// <summary>
		/// Metodo para obtener la instancia a este Manager
		/// </summary>
		/// <returns>La instancia a este Manager, que es un singleton</returns>
		static LuaManager* getInstance();
		void clean() override;

		protected:
		LuaManager();

		private:
		/// <summary>
		/// Se encarga de crear el LuaState e incializar todo lo necesario para
		/// el scripting
		/// </summary>
		void initLua();

		lua_State* L_;
		// Behaviour* behaviourTemplate_;
	};
}  // namespace Separity

#endif __LUA_MANAGER_H__