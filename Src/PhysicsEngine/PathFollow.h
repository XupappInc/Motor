#pragma once
#ifndef __PATH_FOLLOW_H__
#define __PATH_FOLLOW_H__

#include "SeparityExports\SeparityApi.h"
#include "EntityComponent\Component.h"
#include <vector>

namespace Spyutils {
	class Vector3;
}  // namespace Spyutils

namespace Separity {
	class Transform;
	class RigidBody;

	class _SEPARITY_API_ PathFollow : public Separity::Component {
		public:
		__CMPTYPE_DECL__(Separity::_PHYSICS)
		__CMPID_DECL__(Separity::_PATH_FOLLOW)

		enum PathingType { DEFAULT = 0, CYCLIC } pathingType_;
		/// <summary>
		/// Crea el componente pathfollow
		/// </summary>
		PathFollow(std::vector<Spyutils::Vector3> const& path, float velocity);
		/// <summary>
		/// Destructora del componente
		/// </summary>
		~PathFollow();
		/// <summary>
		/// Método update heredado de Component
		/// </summary>
		void preUpdate() override;
		/// <summary>
		/// Método initComponent heredado de Component
		/// </summary>
		void initComponent() override;
		/// <summary>
		/// Cambia el estado del pathing (parado/moviendose)
		/// </summary>
		/// <param name="stop">nuevo estado</param>
		void setStopped(bool stop);
		/// <summary>
		/// Cambia el path
		/// </summary>
		/// <param name="path">nuevo path</param>
		void setPath(std::vector<Spyutils::Vector3> const& path);
		/// <summary>
		/// Cambia la velocidad a la que se mueve la entidad
		/// </summary>
		/// <param name="vel">nueva velocidad</param>
		void setVelocity(float vel);
		/// <summary>
		/// Cambia el tipo del pathing
		/// </summary>
		/// <param name="type">nuevo tipo</param>
		void setPathingType(PathingType type);

		private:
		std::vector<Spyutils::Vector3> path_;
		float velocity_;
		bool stopped_;

		int pathingTo_;
		int pathingDir_;

		Separity::Transform* transform_;
		Separity::RigidBody* rigidBody_;
	};

}  // namespace Separity

#endif  // !__PATH_FOLLOW__
