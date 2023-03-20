#pragma once
#ifndef __SCENE_MANAGER_H__
#define __SCENE_MANAGER_H__

#include "Manager.h"

namespace Separity {
	class SceneManager : public Separity::Manager,
	                     public Singleton<Separity::SceneManager> {
		friend Singleton<Separity::SceneManager>;

		public:

		// update
		virtual void update() override;

		static SceneManager* getInstance();

		virtual ~SceneManager() override;

		bool loadScene();

		protected:
		SceneManager();


	};
}  // namespace Separity

#endif __SCENE_MANAGER_H__