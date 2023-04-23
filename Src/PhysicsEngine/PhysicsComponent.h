#pragma once
#ifndef __PHYSICS_COMPONENT_H__
#define __PHYSICS_COMPONENT_H__

#include "EntityComponent/Component.h"

namespace Separity {
	class _SEPARITY_API_ PhysicsComponent : public Separity::Component {

		public:
		PhysicsComponent();
		virtual ~PhysicsComponent();

	};
}  
#endif __PHYSICS_COMPONENT_H__

