#pragma once
#ifndef __CREATOR_H__
#define __CREATOR_H__

#include <string>

class lua_State;

namespace Separity {

	class Entity;

	class CCreator {
		public:
		CCreator();
		~CCreator() = default;

		virtual void registerInLua() {};

		virtual bool createComponent(lua_State* L, Separity::Entity* ent) = 0;

		protected:

		bool readArray(const std::string& paramName, lua_State* L, float* data, int n = 3);

		bool readParam(const std::string& paramName, lua_State* L, std::string& param);
		bool readParam(const std::string& paramName, lua_State* L, int& param);
	};
};  // namespace Separity

#endif __CREATOR_H__