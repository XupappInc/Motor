#include "PhysicsDebugDrawer.h"

Separity::PhysicsDebugDrawer::PhysicsDebugDrawer(Ogre::SceneManager* sceneMgr)
    : sceneMngr_(sceneMgr) {}

Separity::PhysicsDebugDrawer::~PhysicsDebugDrawer() {}

void Separity::PhysicsDebugDrawer::drawLine(const btVector3& from,
                                            const btVector3& to,
                                            const btVector3& color) {
	// Ogre::ManualObject* line = mSceneMgr->createManualObject();
	// line->begin("BaseWhiteNoLighting", Ogre::RenderOperation::OT_LINE_LIST);
	// line->position(from.x(), from.y(), from.z());
	// line->position(to.x(), to.y(), to.z());
	// line->colour(Ogre::ColourValue(color.x(), color.y(), color.z()));
	// line->end();
	// sceneMngr_->getRootSceneNode()->createChildSceneNode()->attachObject(line);
}

void Separity::PhysicsDebugDrawer::drawBox(const btVector3& bbMin,
                                           const btVector3& bbMax,
                                           const btVector3& color) {
	// Dibuja una caja que se extiende desde bbMin a bbMax en el color
	// especificado
	/*Ogre::ColourValue ogreColor(color.getX(), color.getY(), color.getZ(), 1.0f);
	Ogre::ManualObject* manualObject =
	    sceneManager->createManualObject("MyManualObject");
	manualObject->begin("MyMaterialName", Ogre::RenderOperation::OT_LINE_LIST);
	manualObject->position(bbMin.getX(), bbMin.getY(), bbMin.getZ());
	manualObject->colour(ogreColor);
	manualObject->position(bbMax.getX(), bbMin.getY(), bbMin.getZ());
	manualObject->colour(ogreColor);
	manualObject->position(bbMax.getX(), bbMin.getY(), bbMin.getZ());
	manualObject->colour(ogreColor);
	manualObject->position(bbMax.getX(), bbMax.getY(), bbMin.getZ());
	manualObject->colour(ogreColor);
	manualObject->position(bbMax.getX(), bbMax.getY(), bbMin.getZ());
	manualObject->colour(ogreColor);
	manualObject->position(bbMin.getX(), bbMax.getY(), bbMin.getZ());
	manualObject->colour(ogreColor);
	manualObject->position(bbMin.getX(), bbMax.getY(), bbMin.getZ());
	manualObject->colour(ogreColor);
	manualObject->position(bbMin.getX(), bbMin.getY(), bbMin.getZ());
	manualObject->colour(ogreColor);
	manualObject->position(bbMin.getX(), bbMin.getY(), bbMax.getZ());
	manualObject->colour(ogreColor);
	manualObject->position(bbMax.getX(), bbMin.getY(), bbMax.getZ());
	manualObject->colour(ogreColor);
	manualObject->position(bbMax.getX(), bbMin.getY(), bbMax.getZ());
	manualObject->colour(ogreColor);
	manualObject->position(bbMax.getX(), bbMax.getY(), bbMax.getZ());
	manualObject->colour(ogreColor);
	manualObject->position(bbMax.getX(), bbMax.getY(), bbMax.getZ());
	manualObject->colour(ogreColor);
	manualObject->position(bbMin.getX(), bbMax.getY(), bbMax.getZ());
	manualObject->colour(ogreColor);
	manualObject->position(bbMin.getX(), bbMax.getY(), bbMax.getZ());
	manualObject->colour(ogreColor);
	manualObject->position(bbMin.getX(), bbMin.getY(), bbMax.getZ());
	manualObject->colour(ogreColor);
	manualObject->position(bbMax.getX(), bbMin.getY(), bbMax.getZ());
	manualObject->colour(ogreColor);
	manualObject->position(bbMax.getX(), bbMax.getY(), bbMax.getZ());
	manualObject->colour(ogreColor);
	manualObject->position(bbMin.getX(), bbMax.getY(), bbMax.getZ());
	manualObject->colour(ogreColor);
	manualObject->end();

	sceneMngr_->getRootSceneNode()
	    ->createChildSceneNode("MyNodeName")
	    ->attachObject(manualObject);*/
}
