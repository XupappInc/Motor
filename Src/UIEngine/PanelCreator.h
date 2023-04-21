#pragma once
#ifndef __PANEL_CREATOR_H__
#define __PANEL_CREATOR_H__

#include "CCreator.h"

class lua_State;

namespace Separity {

	class PanelCreator : public CCreator {
		public:
		/// <summary>
		/// Creador de panelCreator, vacío de predeterminado
		/// </summary>
		PanelCreator();
		~PanelCreator() = default;

		/// <summary>
		/// Registra en Lua, un tipo de componente en este caso el tipo Panel y
		/// las funciones correspondientes que queramos
		/// </summary>
		void registerInLua() override;

		/// <summary>
		/// Se crea un componente panel a partir de un texto escrito en Lua con
		/// parámetros name que es el nombre que queramos pasarle a dicho
		/// panel, una posición x, y, y un tamaño, tanto ancho, width
		/// como alto height, y por último el nombre del material que se llama
		/// material
		/// </summary>
		/// <param name="L"></param>
		/// <param name="ent"></param>
		void createComponent(lua_State* L, Separity::Entity* ent) override;
	};
};  // namespace Separity

#endif  // !__PANEL_CREATOR_H__