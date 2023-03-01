#pragma once
#ifndef __RENDER_MANAGER_H__
#define __RENDER_MANAGER_H__
#include "Manager.h"

namespace Separity {
	class RenderManager : public ec::Manager {
		friend Singleton<RenderManager>;

		public:
		inline RenderManager();
		virtual ~RenderManager();
		static RenderManager* getInstance();

		/// <summary>
		/// Método encargado de renderizar todos los componentes
		/// dentro de la lista de componentes
		/// </summary>
		void render();
	};
}  // namespace Separity

#endif  // !__RENDER_MANAGER_H__
