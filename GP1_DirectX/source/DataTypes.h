#pragma once
#include "Math.h"
#include "vector"

namespace dae
{
	struct Vertex
	{
		Vector3 position = {};
		ColorRGB color = { colors::White };
	};
}