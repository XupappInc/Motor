#pragma once
#ifndef __MESH_RENDERER_CREATOR_H__
#define __MESH_RENDERER_CREATOR_H__

#include "CCreator.h"

class lua_State;

namespace Separity {

	class _SEPARITY_API_ MeshRendererCreator : public CCreator {
		public:
		/// <summary>
		/// Creador de MeshRendererCreator, vacío de predeterminado
		/// </summary>
		MeshRendererCreator();
		~MeshRendererCreator() = default;

		/// <summary>
		/// Registra en Lua, un tipo de componente en este caso el tipo
		/// MeshRendererCreator y las funciones correspondientes que queramos
		/// </summary>
		void registerInLua() override;

		/// <summary>
		/// Se crea un componente Animator con parametros meshMaterial que es el
		/// nombre de dicho material, y también en ciertos casos un texture, por
		/// si lo que hay es una textura, aunque no siempre es así
		/// </summary>
		/// <param name="L"></param>
		/// <param name="ent"></param>
		void createComponent(lua_State* L, Separity::Entity* ent) override;
	};
};  // namespace Separity

#endif  // !__MESH_RENDERER_CREATOR_H__