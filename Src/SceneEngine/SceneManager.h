#pragma once
#ifndef __SCENE_MANAGER_H__
#define __SCENE_MANAGER_H__



#include "Manager.h"
#include <vector>

#include "CCreatorFactory.h"

namespace Separity {
	class Entity;

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

		CCreatorFactory factory_;

		std::vector<Entity*> entidades;
	};
}  // namespace Separity

#endif __SCENE_MANAGER_H__