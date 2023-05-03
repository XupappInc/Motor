#pragma once
#ifndef __TRANSFORM_H__
#define __TRANSFORM_H__

#include "Component.h"
#include "SeparityExports\SeparityApi.h"
#include "SeparityUtils\Vector.h"
#include "SeparityUtils\spyQuaternion.h"

#include <vector>

namespace Separity {
	enum typeOR { LOCAL, GLOBAL };

	/// <summary>
	/// Componente que contiene la información de la posición, rotación y escala
	/// de una entidad
	/// </summary>
	class _SEPARITY_API_ Transform : public Separity::Component {
		public:
		__CMPTYPE_DECL__(Separity::_ENTITY)
		__CMPID_DECL__(Separity::_TRANSFORM)

		/// <summary>
		/// Constructora de la clase
		/// </summary>
		Transform();

		/// <summary>
		/// Calcula la matriz de rotación a partir de un vector de rotación
		/// </summary>
		/// <param name="rotation">Vector de rotación</param>
		/// <returns>Matriz de rotación</returns>
		std::vector<std::vector<float>>
		calculateRotationMatrix(Spyutils::Vector3 rotation);

		/// <summary>
		/// Setea la variable "hasChanged" para que sea sobreescrita en cada
		/// iteración.
		/// </summary>
		/// <param name="deltaTime"></param>
		void update(const uint32_t& deltaTime) override;

		///< summary>
		/// Destructora de la clase
		///  </summary>
		~Transform();

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
		void translate(Spyutils::Vector3 other, typeOR TP = LOCAL);

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
		void setRotationQ(float rotationW, float rotationX, float rotationY,
		                  float rotationZ);
		/// <summary>
		/// geter de la rotación en un Vector3
		/// </summary>
		/// <returns></returns>
		Spyutils::Vector3 getRotation();

		/// <summary>
		/// geter de la rotación en un Quaternion
		/// </summary>
		/// <returns></returns>
		Spyutils::spyQuaternion getRotationQ();

		/// <summary>
		/// Rotacion en el eje x
		/// </summary>
		/// <param name="degree">grados a girar</param>
		void pitch(float degree, typeOR TP = LOCAL);

		/// <summary>
		/// Rotacion en el eje y
		/// </summary>
		/// <param name="degree">grados a girar</param>
		void yaw(float degree, typeOR TP = LOCAL);

		/// <summary>
		/// Rotacion en el eje z
		/// </summary>
		/// <param name="degree">grados a girar</param>
		void roll(float degree, typeOR TP = LOCAL);

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
		Spyutils::Vector3 getScale();

		/// <summary>
		/// rota el transform para mirar hacia un punto
		/// </summary>
		/// <param name="target">Punto al que mirar</param>
		void lookAt(Spyutils::Vector3 target);

		/// <returns>Si el transform ha sido modificado en esta iteración. Útil
		/// para el Render Manager.</returns>
		bool hasChanged();

		private:
		Spyutils::Vector3 rotar(Spyutils::Vector3 posicion,
		                        Spyutils::Vector3 anclaje,
		                        Spyutils::Vector3 rotacion);
		Spyutils::Vector3 rotar(Spyutils::Vector3 posicion,
		                        Spyutils::Vector3 anclaje,
		                        Spyutils::spyQuaternion rotacion);
		Spyutils::Vector3 position_;
		Spyutils::Vector3 rotation_;
		Spyutils::spyQuaternion rotationQ_;
		Spyutils::Vector3 scale_;

		bool hasChanged_;
	};

}  // namespace Separity
#endif __TRANSFORM_H__