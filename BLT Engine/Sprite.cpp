#include <SDL.h>

#include "Sprite.h"

namespace BLT
{
	Sprite::Sprite(std::string bpName, Vector2f scale, Vector2i size, Vector2i origin, Rect collisionMask, void* texture, void* renderer)
		: blueprintName(bpName), scale(scale), size(size), origin(origin), collisionMask(collisionMask),
		mTexture((SDL_Texture*)texture), mRenderer((SDL_Renderer*)renderer)
	{

	}

	Sprite::~Sprite()
	{

	}

	void Sprite::render(Transform transform)
	{
		Vector2f pos = transform.position;
		// SDL_Rect r{ 10, 10, 64, 64 };
		SDL_Rect r{ pos.x - origin.x, pos.y - origin.y, size.x, size.y };
		SDL_RenderCopy(mRenderer, mTexture, NULL, &r);
	}
}
