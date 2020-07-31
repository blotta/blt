#pragma once

#include <string>
#include <vector>
#include <map>
#include <SDL.h>

#include "Room.h"
#include "Sprite.h"

namespace BLT
{
	class Game
	{
	public:
		~Game();
		static Game* getInstance();

		SpriteBlueprint* createSpriteBlueprint(std::string name, std::string path);
		SpriteBlueprint* getSpriteBlueprint(std::string name);

		RoomBlueprint* createRoomBlueprint(std::string name);
		RoomBlueprint* getRoomBlueprint(std::string name);

		void start();

	private:
		Game();
		static Game* instance;
		SDL_Window* mWindow;
		SDL_Renderer* mRenderer;

		std::vector<SpriteBlueprint*> mSpriteBlueprints;
		std::vector<RoomBlueprint*> mRoomBlueprints;

		Room* mCurrentRoom;
	};
}
