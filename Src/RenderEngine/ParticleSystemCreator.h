#pragma once
#ifndef __PARTICLE_SYSTEM_CREATOR_H__
#define __PARTICLE_SYSTEM_CREATOR_H__

#include "CCreator.h"

class lua_State;

namespace Separity {

	class ParticleSystemCreator : public CCreator {
		public:
		ParticleSystemCreator();
		~ParticleSystemCreator() = default;

		void registerInLua() override;

		void createComponent(lua_State* L, Separity::Entity* ent) override;
	};
};  // namespace Separity

#endif  // !__PARTICLE_SYSTEM_CREATOR_H__