#pragma once
#ifndef __MESH_RENDERER_CREATOR_H__
#define __MESH_RENDERER_CREATOR_H__

#include "SeparityExports\SeparityApi.h"
#include "EntityComponent\CCreator.h"

class lua_State;

namespace Separity {

	/// <summary>
	/// Clase para la creaci�n de componentes de tipo MeshRenderer
	/// </summary>
	class _SEPARITY_API_ MeshRendererCreator : public CCreator {
		public:
		/// <summary>
		/// Creador de MeshRendererCreator, vac�o de predeterminado
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
		/// nombre de dicho material, y tambi�n en ciertos casos un texture, por
		/// si lo que hay es una textura, aunque no siempre es as�
		/// </summary>
		/// <param name="L"></param>
		/// <param name="ent"></param>
		bool createComponent(lua_State* L, Separity::Entity* ent) override;
	};
};  // namespace Separity

#endif  // !__MESH_RENDERER_CREATOR_H__