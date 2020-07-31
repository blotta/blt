#pragma once

namespace BLT
{
	struct Vector2f
	{
		float x, y;
	};

	struct Vector2i
	{
		int x, y;
	};

	struct Vector2u
	{
		unsigned int x, y;
	};

	struct Rect
	{
		int x, y, w, h;
	};

	struct Transform
	{
		Transform(Vector2f pos)
			: position(pos), scale(Vector2f{ 1, 1 }), rotation(0) {}
		Transform(Vector2f pos, Vector2f scale)
			: position(pos), scale(scale), rotation(0) {}
		Transform(Vector2f pos, Vector2f scale, float rotation)
			: position(pos), scale(scale), rotation(rotation) {}
		Transform(Vector2f pos, float rotation)
			: position(pos), scale(Vector2f{ 1, 1 }), rotation(rotation) {}

		Vector2f position;
		Vector2f scale;
		float rotation;
	};
}
