//#include "PlayerCtrl.h"
//
//#include "Entity.h"
//#include "VehicleMovement.h"
//// #include "InputManager.h"
////
////  #include "checkML.h"
//
//Separity::PlayerCtrl::PlayerCtrl() : PhysicsComponent() {}
//
//Separity::PlayerCtrl::~PlayerCtrl() { vM_ = nullptr; }
//
//void Separity::PlayerCtrl::initComponent() {
//	vM_ = ent_->getComponent<VehicleMovement>();
//	assert(vM_ != nullptr);
//}
//
//void Separity::PlayerCtrl::steering(int dir) {}
//
//void Separity::PlayerCtrl::acelerar(bool dir) {}
//
//void Separity::PlayerCtrl::frenar() {}
//
//void Separity::PlayerCtrl::update(const uint32_t& deltaTime) {
//
//	//if(inputManager_->isKeyHeld('w')) {
//	//	cam_tr->translate(Spyutils::Vector3(-1, 0, 0));
//	//}
//	//if(inputManager_->isKeyHeld('s')) {
//	//	cam_tr->translate(Spyutils::Vector3(1, 0, 0));
//	//}
//	//if(inputManager_->isKeyHeld('a')) {
//	//	cam_tr->translate(Spyutils::Vector3(0, 1, 0));
//	//}
//	//if(inputManager_->isKeyHeld('d')) {
//	//	cam_tr->translate(Spyutils::Vector3(0, 1, 0));
//	//}
//}