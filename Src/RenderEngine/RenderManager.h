#pragma once
#ifndef __RENDER_MANAGER_H__
#define __RENDER_MANAGER_H__
#include "ManagerTemplate.h"
class RenderManager : ManagerTemplate {
	public:

	inline RenderManager();
	virtual ~RenderManager();

	// render
	void render();
};
#endif __RENDER_MANAGER_H__
