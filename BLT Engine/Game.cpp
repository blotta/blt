#include "Game.h"

#include <iostream>

#include <SDL.h>
#include <SDL_image.h>

namespace BLT
{
	Game* Game::instance = 0;

	// PUBLIC
	Game::Game()
	{
		SDL_Init(SDL_INIT_EVERYTHING);

		mWindow = SDL_CreateWindow("BLT Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			800, 600, SDL_WINDOW_SHOWN);

		mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
		SDL_SetRenderDrawColor(mRenderer, 0x00, 0x00, 0x00, 0xFF);

		int flags = IMG_INIT_JPG | IMG_INIT_PNG;
		int initted = IMG_Init(flags);
	}

	Game::~Game()
	{
		// destroy room blueprints
		for (auto roomBP : mRoomBlueprints)
		{
			std::cout << "Deleted room blueprint '" << roomBP->name << "'\n";
			delete roomBP;
		}
		mRoomBlueprints.clear();

		// destroy sprite blueprints ("owns" texture pointer)
		for (auto sbp : mSpriteBlueprints)
		{
			std::cout << "Deleted sprite blueprint '" << sbp->name << "'\n";
			delete sbp;
		}
		mSpriteBlueprints.clear();

		SDL_DestroyRenderer(mRenderer);
		SDL_DestroyWindow(mWindow);

		IMG_Quit();
		SDL_Quit();
	}

	Game* Game::getInstance()
	{
		if (instance == 0)
		{
			instance = new Game();
		}

		return instance;
	}

	/*-----------------------------------------------------------------*/
	/*------------------- Sprite Functionality ------------------------*/
	/*-----------------------------------------------------------------*/
	SpriteBlueprint* Game::createSpriteBlueprint(std::string name, std::string path)
	{
		if (getSpriteBlueprint(name) != nullptr)
		{
			std::cout << "SpriteBlueprint named '" << name << "' already exists" << std::endl;
			return nullptr;
		}

		SpriteBlueprint* spr = new SpriteBlueprint(name, path, (void*)(this->mRenderer));

		// Register Sprite blueprint
		mSpriteBlueprints.push_back(spr);

		std::cout << "Created sprite '" << spr->name << "'\n";

		// Return as Sprite*
		return spr;
	}

	SpriteBlueprint* Game::getSpriteBlueprint(std::string name)
	{
		for (auto s = mSpriteBlueprints.begin(); s < mSpriteBlueprints.end(); s++)
		{
			auto n = (*s)->name;
			if (n == name)
			{
				return (*s);
			}
		}
		return nullptr;
	}

	/*-----------------------------------------------------------------*/
	/*--------------------- Room Functionality ------------------------*/
	/*-----------------------------------------------------------------*/
	RoomBlueprint* Game::createRoomBlueprint(std::string name)
	{
		if (getRoomBlueprint(name) != nullptr)
		{
			std::cout << "RoomBlueprint named '" << name << "' already exists" << std::endl;
			return nullptr;
		}

		RoomBlueprint* rm = new RoomBlueprint(name);

		mRoomBlueprints.push_back(rm);

		std::cout << "Created room '" << rm->name << "'\n";
		return rm;
	}

	RoomBlueprint* Game::getRoomBlueprint(std::string name)
	{
		for (auto r = mRoomBlueprints.begin(); r < mRoomBlueprints.end(); r++)
		{
			auto n = (*r)->name;
			if (n == name)
			{
				return (*r);
			}
		}
		return nullptr;
	}

	/*-----------------------------------------------------------------*/
	/*--------------------- Start running game ------------------------*/
	/*-----------------------------------------------------------------*/
	void Game::start()
	{

		bool quit = false;
		SDL_Event e;

		// init room
		if (mRoomBlueprints.empty())
		{
			std::cout << "No Room Blueprint defined\n";
			quit = true;
		}
		else
		{
			mCurrentRoom = mRoomBlueprints.front()->_instantiate();
		}

		// Application running
		while (!quit)
		{
			// Handle events
			while (SDL_PollEvent(&e) != 0)
			{
				if (e.type == SDL_QUIT)
				{
					quit = true;
				}
				// User presses key
				else if (e.type == SDL_KEYDOWN)
				{
					switch (e.key.keysym.sym)
					{
					case SDLK_ESCAPE:
						quit = true;
						break;
					}
				}
			}

			// Clear screen
			SDL_SetRenderDrawColor(mRenderer, 0x00, 0x00, 0x00, 0xFF);
			SDL_RenderClear(mRenderer);

			// Render texture to screen
			// SDL_Rect r{ 10, 10, 64, 64 };
			// SDL_RenderCopy(gRenderer, gTexture, NULL, &r);
			mCurrentRoom->update();

			// Update screen
			SDL_RenderPresent(mRenderer);
		}
	}

	// PRIVATE
}
