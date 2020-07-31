#include <iostream>

#include "BLT.h"

using namespace BLT;
// WIP
// class player : Actor
// {
// 	void step() override
// 	{
// 		// do create stuff
// 	}
// 
// };

int main(int argc, char* args[])
{
	Game* game = Game::getInstance();

	// Create a sprite that can be instantiated
	game->createSpriteBlueprint("spr_astronaut_idle", "res/images/astronaut.png");

	// Edit the blueprint
	SpriteBlueprint* astro_idle = game->getSpriteBlueprint("spr_astronaut_idle");
	astro_idle->origin = Vector2i{ astro_idle->size.x / 2, astro_idle->size.y - 1 };
	astro_idle->scale = Vector2f{ 2.f, 1.f };

	// Another sprite
	SpriteBlueprint* hook = game->createSpriteBlueprint("spr_hook", "res/images/hook.png");

	// Without a room, there is no game
	RoomBlueprint* rm0 = game->createRoomBlueprint("rm0");
	
	// First layer added renders first, so other layers render on top
	// Asset layer holds graphics, being a Sprite instance with a transform (position, scale, rotation)
	AssetLayerBlueprint* al = rm0->addAssetLayer("Assets");

	// Adding assets to be instantiated when the room starts
	al->addElement(AssetLayerElementBlueprint{ "spr_astronaut_idle", Transform{Vector2f{400.f, 300.f}} });
	al->addElement(AssetLayerElementBlueprint{ "spr_hook", Transform{Vector2f{100.f, 100.f}} });

	// No more assets added
	game->start();

	// Temporary solution for cleanup
	delete game;
	
	return 0;
}
