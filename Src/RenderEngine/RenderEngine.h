#pragma once
#ifndef __RENDER_ENGINE_H
#define __RENDER_ENGINE_H

namespace Ogre {
	class Root;
}  // namespace Ogre

namespace Separity {
	class SeparityRender {
		public:
		int renderOgre();
		Ogre::Root* mRoot;
	};
}  // namespace Separity

#endif  // !__RENDER_ENGINE_H