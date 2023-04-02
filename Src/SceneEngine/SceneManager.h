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

		// update
		virtual void update() override;

		static SceneManager* getInstance();

		virtual ~SceneManager() override;


		bool loadScene(const std::string& root);

		void eraseEntities();

		protected:
		SceneManager();

		private:

		std::vector<Entity*> entidades;
		ComponentFactory* factory_;
	};
}  // namespace Separity

#endif __SCENE_MANAGER_H__