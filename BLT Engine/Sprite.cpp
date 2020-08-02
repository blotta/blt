#include <SDL.h>

#include "Sprite.h"

#include <iostream>

namespace BLT
{
	Sprite::Sprite(std::string bpName, SpriteControl sprCtrl, void* texture, void* renderer)
		: blueprintName(bpName), val(sprCtrl), mTexture((SDL_Texture*)texture), mRenderer((SDL_Renderer*)renderer)
	{
		std::cout << "Instantiating sprite '" << blueprintName << '"' << std::endl;
	}

	Sprite::~Sprite()
	{
		std::cout << "Destroying sprite instance of '" << blueprintName << '"' << std::endl;
	}

	void Sprite::render(Transform transform)
	{
		Vector2f pos = transform.position;
		// SDL_Rect r{ 10, 10, 64, 64 };
		SDL_Rect r{ pos.x - val.origin.x, pos.y - val.origin.y, val.size.x, val.size.y };
		SDL_RenderCopy(mRenderer, mTexture, NULL, &r);
	}
}
