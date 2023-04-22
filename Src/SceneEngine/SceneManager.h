#pragma once
#ifndef __SCENE_MANAGER_H__
#define __SCENE_MANAGER_H__

#ifdef _SEPARITY_EXPORT_
#define _SEPARITY_EXPORT_ __declspec(dllexport)
#else
#define _SEPARITY_EXPORT_ __declspec(dllimport)
#endif

#include "Manager.h"

#include <string>

namespace Separity {

	class Entity;
	class ComponentFactory;

	class SceneManager : public Separity::Manager,
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