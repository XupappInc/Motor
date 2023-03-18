#pragma once
#ifndef BEHAVIOUR_H
#define BEHAVIOUR_H

#include <Component.h>

namespace Separity {
	class Behaviour : public Component 
	{
		public:
		Behaviour();
		~Behaviour();

		virtual void update() override;
		virtual void start();
		virtual void awake();
		virtual void onCollisionEnter();
		virtual void onCollisionExit();
		virtual void onCollisionStay();

		protected:
	};
}  // namespace Separity

#endif  // !BEHAVIOUR_H