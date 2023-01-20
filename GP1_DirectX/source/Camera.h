#pragma once
using namespace dae;

class Camera
{
public:
	Camera(Vector3 _origin, float _fovAngle);

	//void Initialize(float _fovAngle = 90.f, Vector3 _origin = { 0.f,0.f,0.f }, float ratio = 1);
	dae::Matrix GetViewMatrix();
	dae::Matrix GetProjectionMatrix();

	Vector3 origin{};
	float fovAngle{ 90.f };
	float fov{ tanf((fovAngle * TO_RADIANS) / 2.f) };
	float aspectRatio{};

	Vector3 forward{ Vector3::UnitZ };
	Vector3 up{ Vector3::UnitY };
	Vector3 right{ Vector3::UnitX };

	float totalPitch{};
	float totalYaw{};

	Matrix invViewMatrix{};
	Matrix viewMatrix{};
	Matrix projectionMatrix{};

	const float nearPlane{ 0.1f };
	const float farPlane{ 100.f };
};

