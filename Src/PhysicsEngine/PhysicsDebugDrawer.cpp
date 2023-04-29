#include "PhysicsDebugDrawer.h"

#include "RenderEngine/RenderManager.h"

#include <OgreRoot.h>

Separity::PhysicsDebugDrawer::PhysicsDebugDrawer() {
	debugMode_ = DBG_DrawWireframe;

	node_ = Separity::RenderManager::getInstance()->getOgreSceneManager()
	            ->getRootSceneNode()->createChildSceneNode();
}

Separity::PhysicsDebugDrawer::~PhysicsDebugDrawer() { 

	clearLines();
	RenderManager::getInstance()->getOgreSceneManager()->destroySceneNode(node_);
	
	node_ = nullptr;
}

void Separity::PhysicsDebugDrawer::clearLines() {

	Ogre::SceneManager* ogreSceneManager =
	    RenderManager::getInstance()->getOgreSceneManager();

	for(int i = 0; i < lines_.size(); i++) {
		if(lines_[i] != nullptr)
			ogreSceneManager->destroyManualObject(lines_[i]);
	}

	lines_.clear();
}

void Separity::PhysicsDebugDrawer::drawLine(const btVector3& from,
                                            const btVector3& to,
                                            const btVector3& color) {

	Ogre::ManualObject* line = RenderManager::getInstance()->getOgreSceneManager()->createManualObject();

	line->begin("BaseWhiteNoLighting", Ogre::RenderOperation::OT_LINE_LIST);
	line->position(from.x(), from.y(), from.z());
	line->position(to.x(), to.y(), to.z());
	line->colour(Ogre::ColourValue(color.x(), color.y(), color.z()));
	line->end();

	node_->attachObject(line);
	lines_.push_back(line);
}

void Separity::PhysicsDebugDrawer::drawContactPoint(const btVector3& PointOnB,
                                                    const btVector3& normalOnB,
                                                    btScalar distance,
                                                    int lifeTime,
                                                    const btVector3& color) {}

void Separity::PhysicsDebugDrawer::reportErrorWarning(const char* warningString) {}

void Separity::PhysicsDebugDrawer::draw3dText(const btVector3& location,
                                              const char* textString) {}

void Separity::PhysicsDebugDrawer::setDebugMode(int debugMode) {
	debugMode_ = (DebugDrawModes) debugMode;
}

int Separity::PhysicsDebugDrawer::getDebugMode() const { 
	return debugMode_; 
}


