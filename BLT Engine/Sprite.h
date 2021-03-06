#pragma once

#include <string>

#include <SDL.h>

#include "Util.h"

namespace BLT
{
	struct SpriteControl
	{
		Vector2f scale;
		Vector2i size;
		Vector2i origin;
		Rect collisionMask;
	};

	/*-----------------------------------------------------------------*/
	/*----------------------- Sprite ----------------------------------*/
	/*-----------------------------------------------------------------*/
	class Sprite
	{
	public:
		// Sprite(std::string bpName, Vector2f scale, Vector2i size, Vector2i origin, Rect collisionMask, void* texture, void* renderer);
		Sprite(std::string bpName, SpriteControl sprCtrl, void* texture, void* renderer);
		~Sprite();


		const std::string blueprintName;

		SpriteControl val;
		// Vector2f scale;
		// Vector2i size;
		// Vector2i origin;
		// Rect collisionMask;

		void render(Transform transform);

	private:
		SDL_Texture* mTexture;
		SDL_Renderer* mRenderer;
	};

	/*-----------------------------------------------------------------*/
	/*------------------- SpriteBlueprint -----------------------------*/
	/*-----------------------------------------------------------------*/
	class SpriteBlueprint
	{
	public:
		SpriteBlueprint(std::string name, std::string path, void* renderer);
		~SpriteBlueprint();

		const std::string name;

		SpriteControl val;
		// Vector2f scale;
		// Vector2i size;
		// Vector2i origin;
		// Rect collisionMask;

		Sprite* _instantiate();
	private:
		SDL_Texture* mTexture;
		SDL_Renderer* mRenderer;

		static SDL_Texture* loadTexture(SDL_Surface* surf, SDL_Renderer* rend);
		static SDL_Surface* loadSurface(std::string path);
	};


}
