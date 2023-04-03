#pragma once
#ifndef __TRANSFORM_MANAGER_H__
#define __TRANSFORM_MANAGER_H__
#include "Manager.h"
namespace Separity {
	class TransformManager : public Separity::Manager,
	                         public Singleton<Separity::TransformManager> {
		friend Singleton<TransformManager>;

		public:
		/// <summary>
		/// Constructor de la clase
		/// </summary>
		inline TransformManager();
		virtual ~TransformManager();
		/// <summary>
		/// Obtiene la instancia del Manager de físicas
		/// </summary>
		/// <returns>La instancia del Manager</returns>
		static TransformManager* getInstance();
	};
}  // namespace Separity

#endif __TRANSFORM_MANAGER_H__
