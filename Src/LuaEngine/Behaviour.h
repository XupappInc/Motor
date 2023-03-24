#pragma once
#ifndef BEHAVIOUR_H
#define BEHAVIOUR_H

#include <Component.h>
#include <string>

namespace Separity {
	class Behaviour : public Component 
	{
		public:
		__CMPTYPE_DECL__(Separity::_SCRIPT)
		__CMPID_DECL__(Separity::_BEHAVIOUR)
			
		Behaviour(std::string name = "defaultName");
		~Behaviour();

		virtual void update() override;
		virtual void start();
		virtual void awake();
		virtual void onCollisionEnter(Entity* other);
		virtual void onCollisionExit(Entity* other);
		virtual void onCollisionStay(Entity* other);

		protected:
		std::string name_;
	};
}  // namespace Separity

#endif  // !BEHAVIOUR_H