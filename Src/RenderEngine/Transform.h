#pragma once
#ifndef __TRANSFORM_H__
#define __TRANSFORM_H__
#include "Component.h"
#include "Vector.h"

namespace Ogre {
	class SceneManager;
	class SceneNode;
}  // namespace Ogre
namespace Spyutils {
	class spyQuaternion;
}
namespace Separity {
	class Transform : public Separity::Component {
		public:
		__CMPTYPE_DECL__(Separity::_TRANSFORM_COMPONENT)
		__CMPID_DECL__(Separity::_TRANSFORM)
		Transform();
	
		
		~Transform();
		/// <summary>
		/// geter del nodo de ogre
		/// </summary>
		/// <returns></returns>
		Ogre::SceneNode* getNode() { return tr_; }
		/// <summary>
		/// Setear la posición del componente tranform
		/// </summary>
		/// <param name="other">Vector3 de la posición</param>
		void setPosition(Spyutils::Vector3 other);
		/// <summary>
		/// Setear la posición del componente tranform
		/// </summary>
		/// <param name="x">posición x</param>
		/// <param name="y">posición y</param>
		/// <param name="z">posición z</param>
		void setPosition(float x, float y, float z);
		/// <summary>
		/// Transladar la posición del transform
		/// </summary>
		/// <param name="other">Vector3 para transladar</param>
		void translate(Spyutils::Vector3 other);
		/// <summary>
		/// Coger la posición del transform
		/// </summary>
		/// <returns></returns>
		Spyutils::Vector3 getPosition();
		/// <summary>
		/// Setetar l posición del transform.
		/// </summary>
		/// <param name="rotationX">grados del eje x</param>
		/// <param name="rotationY">grados eje y</param>
		/// <param name="rotationZ">grados de ejez</param>
		void setRotation(Spyutils::spyQuaternion quat);
		/// <summary>
		/// geter de la rotacion local en qutaerniones
		/// </summary>
		/// <returns></returns>
		Spyutils::spyQuaternion getRotationQuat();
		/// <summary>
		/// geter de la rotación en un Vector3
		/// </summary>
		/// <returns></returns>
		Spyutils::Vector3 getRotation();
		/// <summary>
		/// Rotacion en el eje x
		/// </summary>
		/// <param name="degree">grados a girar</param>
		void pitch(float degree);
		/// <summary>
		/// Rotacion en el eje y
		/// </summary>
		/// <param name="degree">grados a girar</param>
		void yaw(float degree);
		/// <summary>
		/// Rotacion en el eje z
		/// </summary>
		/// <param name="degree">grados a girar</param>
		void roll(float degree);
		/// <summary>
		/// setear la escala del transform
		/// </summary>
		/// <param name="scaleX">float para escalar del eje x</param>
		/// <param name="scaleY">float para escalar del eje y</param>
		/// <param name="scaleZ">float para escalar del eje z</param>
		void setScale(float scaleX, float scaleY, float scaleZ);
		/// <summary>
		/// setear la escala del transform
		/// </summary>
		/// <param name="scale">float para escalar el eje x y z</param>
		void setScale(float scale);
		/// <summary>
		/// geter de la posición global
		/// </summary>
		/// <returns>la posicion en coordenadas globales</returns>
		Spyutils::Vector3 getGlobalPosition();
		/// <summary>
		/// seter de la posición global
		/// </summary>
		/// <param name="other">vector3 para el cambio de la posición global</param>
		void setGlobalPosition(Spyutils::Vector3 other);
		/// <summary>
		/// geter de la escala del transform
		/// </summary>
		/// <returns></returns>
		Spyutils::Vector3 getScale();
		/// <summary>
		/// Seter de la rotacion en coordenadas globales
		/// </summary>
		/// <param name="quat">quaternion para cambiar la rotación</param>
		void setGlobalRotation(Spyutils::spyQuaternion quat);
		/// <summary>
		/// geter de la rotacion en coordenadas globales
		/// </summary>
		/// <returns></returns>
		Spyutils::spyQuaternion  getGlobalRotation();
		private:
		Ogre::SceneNode* tr_ = nullptr;
		Spyutils::Vector3 position_;
		Spyutils::Vector3 rotation_;
		Spyutils::Vector3 scale_;
		
		
	};

}  // namespace Separity
#endif __TRANSFORM_H__