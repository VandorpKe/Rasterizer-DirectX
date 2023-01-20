#include "pch.h"
#include "Camera.h"

using namespace dae;

Camera::Camera(Vector3 _origin, float _fovAngle):
	origin{_origin},
	fovAngle{_fovAngle}
{}

Matrix Camera::GetViewMatrix()
{
	return Matrix::CreateLookAtLH(origin, forward, up);
}

Matrix Camera::GetProjectionMatrix()
{
	return{};
}