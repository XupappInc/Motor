#pragma once
#ifndef __PATH_FOLLOW_H__
#define __PATH_FOLLOW_H__

#include "PhysicsComponent.h"

#include <vector>

namespace Spyutils {
	class Vector3;
}  // namespace Spyutils

namespace Separity {
	class Transform;
	class RigidBody;

	class PathFollow : public Separity::PhysicsComponent {
		public:
		__CMPTYPE_DECL__(Separity::_PHYSICS)
		__CMPID_DECL__(Separity::_PATH_FOLLOW)

		enum PathingType { DEFAULT = 0, CYCLIC } pathingType_
			;
		/// <summary>
		/// Crea el componente pathfollow
		/// </summary>
		PathFollow(std::vector<Spyutils::Vector3> const& path);

		/// <summary>
		/// Destructora del componente
		/// </summary>
		~PathFollow();

		/// <summary>
		/// Método update heredado de Component
		/// </summary>
		void update(const uint32_t& deltaTime = 0) override;

		void initComponent() override;

		void setStopped(bool stop);
		void setPath(std::vector<Spyutils::Vector3> const& path);
		void setVelocity(float vel);
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
