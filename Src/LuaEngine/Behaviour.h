#pragma once
#ifndef BEHAVIOUR_H
#define BEHAVIOUR_H

#include <Component.h>

namespace luabridge 
{
	class LuaRef;
}

namespace Separity {
	//class RigidBody;
	class Transform;
	class Behaviour : public Component 
	{
		friend class LuaManager;

		public:
		__CMPTYPE_DECL__(Separity::_SCRIPT)
		__CMPID_DECL__(Separity::_BEHAVIOUR)

		Behaviour();
		Behaviour(luabridge::LuaRef* behaviourLua);
		~Behaviour();

		void setLuaScript(luabridge::LuaRef* behaviourLua);

		void initComponent() override;

		virtual void update() override;
		virtual void start();
		virtual void awake();
		virtual void onCollisionEnter(Entity* other);
		virtual void onCollisionExit(Entity* other);
		virtual void onCollisionStay(Entity* other);

		Transform& getTransform();
		Transform* transform_;

		protected:
		luabridge::LuaRef* behaviourLua_;
		//RigidBody* rigidBody_;
	};
}  // namespace Separity

#endif  // !BEHAVIOUR_H