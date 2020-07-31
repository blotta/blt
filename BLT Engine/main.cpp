#include <iostream>

#include "BLT.h"

using namespace BLT;

// class player : Actor
// {
// 	void step() override
// 	{
// 		// do step stuff
// 	}
// 
// };

int main(int argc, char* args[])
{
	Game* game = Game::getInstance();

	game->createSpriteBlueprint("spr_astronaut_idle", "res/images/astronaut.png");

	SpriteBlueprint* astro_idle = game->getSpriteBlueprint("spr_astronaut_idle");
	astro_idle->origin = Vector2i{ astro_idle->size.x / 2, astro_idle->size.y - 1 };
	astro_idle->scale = Vector2f{ 2.f, 1.f };

	SpriteBlueprint* hook = game->createSpriteBlueprint("spr_hook", "res/images/hook.png");

	RoomBlueprint* rm0 = game->createRoomBlueprint("rm0");
	
	AssetLayerBlueprint* al = rm0->addAssetLayer("Assets");

	al->addElement(AssetLayerElementBlueprint{ "spr_astronaut_idle", Transform{Vector2f{400.f, 300.f}} });
	al->addElement(AssetLayerElementBlueprint{ "spr_hook", Transform{Vector2f{100.f, 100.f}} });

	game->start();

	delete game;
	
	return 0;
}
