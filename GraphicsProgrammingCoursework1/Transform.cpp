#include "Transform.h"

namespace GraphicsProgramming
{

	Transform::Transform() : scale(Vec3(1, 1, 1))
	{

	}

	Matrix Transform::GetModel()
	{
		//Calculate the position matrix using the current position vector.
		Matrix positionMatrix = glm::translate(position);

		//Calculate the scale matrix using the current scale vector.
		Matrix scaleMatrix = glm::scale(scale);

		//Calculate the rotation matrices for the 3 axes using
		//their respective values in the rotation vector.
		Matrix rotationXMatrix = glm::rotate(rotation.x, Vec3(1, 0, 0));
		Matrix rotationYMatrix = glm::rotate(rotation.y, Vec3(0, 1, 0));
		Matrix rotationZMatrix = glm::rotate(rotation.z, Vec3(0, 0, 1));

		//Calculate the main rotation matrix by multiplying the matrices
		//of the 3 axes.
		Matrix rotationMatrix = rotationXMatrix * rotationYMatrix * rotationZMatrix;

		//Calculate and return the "Model" matrix by multiplying
		//the position, rotation, and scale matrices.
		return positionMatrix * rotationMatrix * scaleMatrix;
	}

	Vec3* Transform::GetRotation()
	{
		return &rotation;
	}

	Vec3* Transform::GetScale()
	{
		return &scale;
	}

	void Transform::Rotate(AXIS axis, float r)
	{
		//For each possible axis, check if that is the one
		//that is being changed. If so, call the "SetRotation"
		//method with the appropriate new values (the current ones
		//but with the value of the given axis being increased by r).
		switch (axis)
		{
			case AXIS::X:
				SetRotation(rotation.x + r, rotation.y, rotation.z);
				break;
			case AXIS::Y:
				SetRotation(rotation.x, rotation.y + r, rotation.z);
				break;
			case AXIS::Z:
				SetRotation(rotation.x, rotation.y, rotation.z + r);
				break;
			default:
				break;
		}
	}

	void Transform::SetRotation(float x, float y, float z)
	{
		SetRotation(Vec3(x, y, z));
	}

	void Transform::SetRotation(Vec3 rotation)
	{
		this->rotation = rotation;
	}

	void Transform::SetScale(float x, float y, float z)
	{
		SetScale(Vec3(x, y, z));
	}

	void Transform::SetScale(Vec3 scale)
	{
		this->scale = scale;
	}

}