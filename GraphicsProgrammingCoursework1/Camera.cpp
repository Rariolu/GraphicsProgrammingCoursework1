#include "Camera.h"

Camera::Camera(float fieldOfView, float aspectRatio, float nearClip, float farClip, Vec3 pos)
{
	forward = Vec3(0.0f, 0.0f, 1.0f);
	position = pos;
	up = Vec3(0.0f, 1.0f, 0.0f);
	projection = glm::perspective(fieldOfView, aspectRatio, nearClip, farClip);
}

Vec3* Camera::GetForward()
{
	return &forward;
}

Vec3* Camera::GetUp()
{
	return &up;
}

Matrix Camera::GetViewProjection() const
{
	return projection * GetView();
}

Matrix Camera::GetView() const
{
	return glm::lookAt(position, position + forward, up);
}

Matrix Camera::GetProjection() const
{
	return projection;
}