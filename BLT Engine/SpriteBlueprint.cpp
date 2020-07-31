#include <iostream>

#include <SDL_image.h>

#include "Sprite.h"

namespace BLT
{
	// PUBLIC

	// user shouldn't be used
	SpriteBlueprint::SpriteBlueprint(std::string name, std::string path, void* renderer)
		: name(name)
	{
		this->scale = Vector2f{ 1.f, 1.f };

		SDL_Surface* surf = SpriteBlueprint::loadSurface(path);

		this->size = Vector2i{ surf->w, surf->h };
		this->origin = Vector2i{ 0, 0 };
		this->collisionMask = Rect{ 0, 0, surf->w - 1, surf->h - 1 };

		this->mRenderer = (SDL_Renderer*)renderer;
		this->mTexture = SpriteBlueprint::loadTexture(surf, mRenderer);
	}

	SpriteBlueprint::~SpriteBlueprint()
	{
		SDL_DestroyTexture(this->mTexture);
	}

	Sprite SpriteBlueprint::_instantiate()
	{
		return Sprite(name, scale, size, origin, collisionMask, (void*)mTexture, (void*)mRenderer);
	}

	SDL_Texture* SpriteBlueprint::loadTexture(SDL_Surface* surf, SDL_Renderer* rend)
	{
		SDL_Texture* newTexture = NULL;

		// SDL_Surface* tempSurf = loadSurface(path);
		if (surf == NULL)
		{
			std::cout << "Failed to load image surface\n";
		}
		else
		{
			// Create texture from surface pixels
			newTexture = SDL_CreateTextureFromSurface(rend, surf);
			if (newTexture == NULL)
			{
				std::cout << "Unable to create texture from surface SDL_Error: " << SDL_GetError() << std::endl;
			}

			// SDL_FreeSurface(tempSurf);
		}
		return newTexture;
	}

	SDL_Surface* SpriteBlueprint::loadSurface(std::string path)
	{
		SDL_Surface* loadedSurface = IMG_Load(path.c_str());
		if (loadedSurface == NULL)
		{
			std::cout << "Unable to load image '" << path << "' IMG_Load:" << IMG_GetError() << std::endl;
		}

		return loadedSurface;
	}
}
