#pragma once
#ifndef __TRANSFORM_H__
#define __TRANSFORM_H__
#include "Component.h"
#include "Vector.h"


class btTransform;
class Transform : public ec::Component {
	public:
	__CMPTYPE_DECL__(ec::_PHYSICS)
	__CMPID_DECL__(ec::_TRANSFORM)
	Transform();
	~Transform();
	/// <summary>
	/// Setear la posición del componente tranform
	/// </summary>
	/// <param name="other">Vector3 de la posición</param>
	void setPosition(spyutils::Vector3 other);
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
	void translate(spyutils::Vector3 other);
	/// <summary>
	/// Coger la posición del transform
	/// </summary>
	/// <returns></returns>
	spyutils::Vector3 getPosition();
	/// <summary>
	/// Setetar l posición del transform.
	/// </summary>
	/// <param name="rotationX">grados del eje x</param>
	/// <param name="rotationY">grados eje y</param>
	/// <param name="rotationZ">grados de ejez</param>
	void setRotation(float rotationX, float rotationY, float rotationZ);
	/// <summary>
	/// geter de la rotación en un Vector3
	/// </summary>
	/// <returns></returns>
	spyutils::Vector3 getRotation();
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
	/// geter de la escala del transform
	/// </summary>
	/// <returns></returns>
	spyutils::Vector3 getScale();

	private:
	btTransform* tr_;
	spyutils::Vector3 positition_;
	spyutils::Vector3 rotation_;
	spyutils::Vector3 scale_;
};
#endif __TRANSFORM_H__