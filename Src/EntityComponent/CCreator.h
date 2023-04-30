#pragma once
#ifndef __CREATOR_H__
#define __CREATOR_H__

#include "SeparityExports\SeparityApi.h"

#include <string>

class lua_State;

namespace Separity {

	class Entity;

	/// <summary>
	/// Clase abstracta para la creación de componentes
	/// </summary>
	class _SEPARITY_API_ CCreator {
		public:
		/// <summary>
		/// Constructora de la clase
		/// </summary>
		CCreator();

		/// <summary>
		///	Destructora de la clase
		/// </summary>
		~CCreator() = default;

		/// <summary>
		/// Registra el componente para su uso en Lua
		/// </summary>
		virtual void registerInLua();

		/// <summary>
		/// Crea un componente y se lo asigna a la entidad
		/// </summary>
		/// <param name="L">Referencia a la tabla de Lua</param>
		/// <param name="ent">Entidad a la que asignar el componente
		/// creado</param> <returns>True si se ha podido crear y asignar / False
		/// e.o.c</returns>
		virtual bool createComponent(lua_State* L, Separity::Entity* ent) = 0;

		protected:
		/// <summary>
		/// Lee la entrada "paramName" de la tabla "lua_state" y se lo asigna a
		/// "data"
		/// </summary>
		/// <param name="paramName">Entrada de la tabla (array)</param>
		/// <param name="L">Referencia a la tabla de Lua</param>
		/// <param name="data">Parámetro al que se le asigna la entrada</param>
		/// <param name="n">Número de elementos del array
		/// "paramName"</param> <returns>True si la entrada existe en la tabla y
		/// es un array / False e.o.c</returns>
		bool readArray(const std::string& paramName, lua_State* L, float* data,
		               int n = 3);
		/// <summary>
		/// Lee la entrada "paramName" de la tabla "lua_state" y se lo asigna a
		/// "param"
		/// </summary>
		/// <param name="paramName">Entrada de la tabla (string)</param>
		/// <param name="L">Referencia a la tabla de Lua</param>
		/// <param name="param">Parámetro al que se le asigna la entrada
		/// "paramName"</param> <returns>True si la entrada existe en la tabla y
		/// es un string / False e.o.c</returns>
		bool readParam(const std::string& paramName, lua_State* L,
		               std::string& param);

		/// <summary>
		/// Lee la entrada "paramName" de la tabla "lua_state" y se lo asigna a
		/// "param"
		/// </summary>
		/// <param name="paramName">Entrada de la tabla (int)</param>
		/// <param name="L">Referencia a la tabla de Lua</param>
		/// <param name="param">Parámetro al que se le asigna la entrada
		/// "paramName"</param> <returns>True si la entrada existe en la tabla y
		/// es un entero / False e.o.c</returns>
		bool readParam(const std::string& paramName, lua_State* L, int& param);

		/// <summary>
		/// Lee la entrada "paramName" de la tabla "lua_state" y se lo asigna a
		/// "param"
		/// </summary>
		/// <param name="paramName">Entrada de la tabla (float)</param>
		/// <param name="L">Referencia a la tabla de Lua</param>
		/// <param name="param">Parámetro al que se le asigna la entrada
		/// "paramName"</param> <returns>True si la entrada existe en la tabla y
		/// es un entero / False e.o.c</returns>
		bool readParam(const std::string& paramName, lua_State* L, float& param);

	};
};  // namespace Separity

#endif __CREATOR_H__