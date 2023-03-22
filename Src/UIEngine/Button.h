#pragma once
#ifndef __BUTTON_H__
#define __BUTTON_H__

#include "Component.h"
namespace Separity {
	class Button : public Separity::Component{
		public:
		/// <summary>
		/// Constructora de botones
		/// </summary>
		Button();
		bool ButtonPressed();
		/// <summary>
		/// Destructora de botones
		/// </summary>
		~Button();
	};

}  // namespace Separity
#endif  // !__BUTTON_H__
