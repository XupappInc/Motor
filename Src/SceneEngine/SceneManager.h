#pragma once
#ifndef __SCENE_MANAGER_H__
#define __SCENE_MANAGER_H__

#include "SeparityExports/SeparityApi.h"

#include "Manager.h"

#include <string>

namespace Separity {

	class Entity;
	class ComponentFactory;

	class _SEPARITY_API_ SceneManager
	    : public Separity::Manager,
	                     public Singleton<Separity::SceneManager> {
		friend Singleton<Separity::SceneManager>;

		public:

		bool loadScene(const std::string& root);

		bool changeScene(const std::string& root);

		void clean() override;

		static SceneManager* getInstance();


		protected:
		SceneManager();

		private:

		ComponentFactory* factory_;
	};
}  // namespace Separity

#endif __SCENE_MANAGER_H__