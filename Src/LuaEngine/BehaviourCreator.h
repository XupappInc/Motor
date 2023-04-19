#pragma once
#ifndef __BEHAVIOUR_CREATOR_H__
#define __BEHAVIOUR_CREATOR_H__

#include "CCreator.h"

class lua_State;

namespace Separity {

	class BehaviourCreator : public CCreator {
		public:
		BehaviourCreator();
		~BehaviourCreator() = default;

		void registerInLua() override;

		void createComponent(lua_State* L, Separity::Entity* ent) override;
	};
};  

#endif __BEHAVIOUR_CREATOR_H__