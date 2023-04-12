#pragma once
#ifndef __RENDER_COMPONENT_H__
#define __RENDER_COMPONENT_H__

#include "Component.h"

namespace Separity {
	class RenderComponent : public Separity::Component {
		public:
		RenderComponent();
		virtual ~RenderComponent();
	};
}  // namespace Separity
#endif __RENDER_COMPONENT_H__
