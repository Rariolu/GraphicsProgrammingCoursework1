#ifndef _CAMERA_H
#define _CAMERA_H

#include <gtx/transform.hpp>
#include "Aliases.h"
#include "MutablePoint.h"

namespace GraphicsProgramming
{

	class Camera : public MutablePoint
	{
		public:
			Camera(float fieldOfView, float aspectRatio, float nearClip, float farClip, Vec3 pos = Vec3(0, 0, 0));

			//Get the Vec3 forward direction of this camera.
			Vec3* GetForward();

			//Get the Vec3 up direction of this camera.
			Vec3* GetUp();

			//Calculate a ViewProjection matrix to
			//be given to the shader to render the
			//3D world from the camera's perspective.
			Matrix GetViewProjection() const;
			Matrix GetView() const;
			Matrix GetProjection() const;

			void RotateY(float angle);
			void Rotate(AXIS axis, float angle);

		private:
			Vec3 forward;
			Matrix projection;
			Vec3 up;
	};

}

#endif