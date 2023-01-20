#pragma once
#include <cassert>
#include <SDL_keyboard.h>
#include <SDL_mouse.h>

#include "Math.h"
#include "Timer.h"

// From the rasterizor

namespace dae
{
	struct Camera
	{
		Camera() = default;

		Camera(const Vector3& _origin, float _fovAngle):
			origin{_origin},
			fovAngle{_fovAngle}
		{
		}


		Vector3 origin{};
		float fovAngle{90.f};
		float fov{ tanf((fovAngle * TO_RADIANS) / 2.f) };
		float aspectRatio{};

		float nearPlane{ .1f };
		float farPlane{ 100.f };

		Vector3 forward{Vector3::UnitZ};
		Vector3 up{Vector3::UnitY};
		Vector3 right{Vector3::UnitX};

		float totalPitch{};
		float totalYaw{};

		void Initialize(float _fovAngle = 90.f, Vector3 _origin = {0.f,0.f,0.f}, float _aspectRatio = 1)
		{
			fovAngle = _fovAngle;
			fov = tanf((fovAngle * TO_RADIANS) / 2.f);
			aspectRatio = _aspectRatio;

			origin = _origin;
		}

		Matrix GetViewMatrix() const
		{
			return Matrix::CreateLookAtLH(origin, forward, up);
			//DirectX Implementation => https://learn.microsoft.com/en-us/windows/win32/direct3d9/d3dxmatrixlookatlh
		}

		Matrix GetProjectionMatrix() const
		{
			return Matrix::CreatePerspectiveFovLH(fov, aspectRatio, nearPlane, farPlane);
			//DirectX Implementation => https://learn.microsoft.com/en-us/windows/win32/direct3d9/d3dxmatrixperspectivefovlh
		}
	};
}
