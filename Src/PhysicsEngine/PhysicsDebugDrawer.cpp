#include "PhysicsDebugDrawer.h"

#include <OgreRoot.h>

Separity::PhysicsDebugDrawer::PhysicsDebugDrawer(Ogre::SceneManager* sceneMgr)
    : sceneMngr_(sceneMgr) {
	debugMode_ = DBG_DrawWireframe;
	debugNode_ = sceneMngr_->getRootSceneNode()->createChildSceneNode();
}

Separity::PhysicsDebugDrawer::~PhysicsDebugDrawer() { 
	/*clearLines();
	sceneMngr_->destroySceneNode(debugNode_);*/
	
	debugNode_ = nullptr;
	sceneMngr_ = nullptr;
}

void Separity::PhysicsDebugDrawer::clearLines() {
	for(int i = 0; i < lines_.size(); i++) {
		if(lines_[i] != nullptr)
			sceneMngr_->destroyManualObject(lines_[i]);
	}

	lines_.clear();
}

void Separity::PhysicsDebugDrawer::drawLine(const btVector3& from,
                                            const btVector3& to,
                                            const btVector3& color) {
	Ogre::ManualObject* line = sceneMngr_->createManualObject();
	line->begin("BaseWhiteNoLighting", Ogre::RenderOperation::OT_LINE_LIST);
	line->position(from.x(), from.y(), from.z());
	line->position(to.x(), to.y(), to.z());
	line->colour(Ogre::ColourValue(color.x(), color.y(), color.z()));
	line->end();
	debugNode_->attachObject(line);
	lines_.push_back(line);
}

// void Separity::PhysicsDebugDrawer::drawBox(const btVector3& bbMin,
//                                            const btVector3& bbMax,
//                                            const btVector3& color) {
//	// Dibuja una caja que se extiende desde bbMin a bbMax en el color
//	// especificado
//	Ogre::ColourValue ogreColor(color.getX(), color.getY(), color.getZ(), 1.0f);
//	Ogre::ManualObject* manualObject =
//	    sceneMngr_->createManualObject("MyManualObject");
//	manualObject->begin("MyMaterialName", Ogre::RenderOperation::OT_LINE_LIST);
//	manualObject->position(bbMin.getX(), bbMin.getY(), bbMin.getZ());
//	manualObject->colour(ogreColor);
//	manualObject->position(bbMax.getX(), bbMin.getY(), bbMin.getZ());
//	manualObject->colour(ogreColor);
//	manualObject->position(bbMax.getX(), bbMin.getY(), bbMin.getZ());
//	manualObject->colour(ogreColor);
//	manualObject->position(bbMax.getX(), bbMax.getY(), bbMin.getZ());
//	manualObject->colour(ogreColor);
//	manualObject->position(bbMax.getX(), bbMax.getY(), bbMin.getZ());
//	manualObject->colour(ogreColor);
//	manualObject->position(bbMin.getX(), bbMax.getY(), bbMin.getZ());
//	manualObject->colour(ogreColor);
//	manualObject->position(bbMin.getX(), bbMax.getY(), bbMin.getZ());
//	manualObject->colour(ogreColor);
//	manualObject->position(bbMin.getX(), bbMin.getY(), bbMin.getZ());
//	manualObject->colour(ogreColor);
//	manualObject->position(bbMin.getX(), bbMin.getY(), bbMax.getZ());
//	manualObject->colour(ogreColor);
//	manualObject->position(bbMax.getX(), bbMin.getY(), bbMax.getZ());
//	manualObject->colour(ogreColor);
//	manualObject->position(bbMax.getX(), bbMin.getY(), bbMax.getZ());
//	manualObject->colour(ogreColor);
//	manualObject->position(bbMax.getX(), bbMax.getY(), bbMax.getZ());
//	manualObject->colour(ogreColor);
//	manualObject->position(bbMax.getX(), bbMax.getY(), bbMax.getZ());
//	manualObject->colour(ogreColor);
//	manualObject->position(bbMin.getX(), bbMax.getY(), bbMax.getZ());
//	manualObject->colour(ogreColor);
//	manualObject->position(bbMin.getX(), bbMax.getY(), bbMax.getZ());
//	manualObject->colour(ogreColor);
//	manualObject->position(bbMin.getX(), bbMin.getY(), bbMax.getZ());
//	manualObject->colour(ogreColor);
//	manualObject->position(bbMax.getX(), bbMin.getY(), bbMax.getZ());
//	manualObject->colour(ogreColor);
//	manualObject->position(bbMax.getX(), bbMax.getY(), bbMax.getZ());
//	manualObject->colour(ogreColor);
//	manualObject->position(bbMin.getX(), bbMax.getY(), bbMax.getZ());
//	manualObject->colour(ogreColor);
//	manualObject->end();
//	sceneMngr_->getRootSceneNode()
//	    ->createChildSceneNode("MyNodeName")
//	    ->attachObject(manualObject);
// }

void Separity::PhysicsDebugDrawer::drawContactPoint(const btVector3& PointOnB,
                                                    const btVector3& normalOnB,
                                                    btScalar distance,
                                                    int lifeTime,
                                                    const btVector3& color) {}

void Separity::PhysicsDebugDrawer::reportErrorWarning(
    const char* warningString) {}

void Separity::PhysicsDebugDrawer::draw3dText(const btVector3& location,
                                              const char* textString) {}

void Separity::PhysicsDebugDrawer::setDebugMode(int debugMode) {
	debugMode_ = (DebugDrawModes) debugMode;
}

int Separity::PhysicsDebugDrawer::getDebugMode() const { return debugMode_; }

void Separity::PhysicsDebugDrawer::setSceneManager(
    Ogre::SceneManager* sceneManager) {
	sceneMngr_ = sceneManager;
}
