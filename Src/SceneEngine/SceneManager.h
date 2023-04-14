#pragma once
#ifndef __SCENE_MANAGER_H__
#define __SCENE_MANAGER_H__

#include "Manager.h"

#include <string>

namespace Separity {

	class Entity;
	class ComponentFactory;

	class SceneManager : public Separity::Manager,
	                     public Singleton<Separity::SceneManager> {
		friend Singleton<Separity::SceneManager>;

		public:

		void clean() override;

		static SceneManager* getInstance();

		bool loadScene(const std::string& root);

		protected:
		SceneManager();

		private:

		ComponentFactory* factory_;
	};
}  // namespace Separity

#endif __SCENE_MANAGER_H__