#pragma once
#ifndef __UI_MANAGER_H__
#define __UI_MANAGER_H__

#include "Manager.h"

namespace Separity {
	class UIManager : public Separity::Manager,
		public Singleton<Separity::UIManager> {

	};
}  // namespace Separity
#endif  //!__UI_MANAGER_H__