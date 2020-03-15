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

void Camera::RotateY(float angle)
{
	const Vec3 UP(0.0f, 1.0f, 0.0f);

	Matrix rotation = glm::rotate(angle, UP);

	forward = Vec3(glm::normalize(rotation * glm::vec4(forward, 0.0)));
	up = Vec3(glm::normalize(rotation * Vec4(up, 0.0)));
}

void Camera::Rotate(AXIS axis, float angle)
{
	Vec3 axisVector = Vec3(axis == AXIS::X, axis == AXIS::Y, axis == AXIS::Z);
	
	Matrix rotation = glm::rotate(angle, axisVector);
	
	forward = Vec3(glm::normalize(rotation * glm::vec4(forward, 0.0)));
	up = Vec3(glm::normalize(rotation * Vec4(up, 0.0)));
}