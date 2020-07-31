# BLT Engine

A GameMaker-inspired C++ game engine

## About

This engine is primarily designed to have a workflow similar to the one used on GameMaker Studio 2.

## Build Dependencies

* SDL2-devel-2.0.12-VC
* SDL2_image-devel-2.0.5-VC

## Runtime Dependencies

* SDL2.dll
* SDL2_image.dll
* libjpeg-9.dll
* libpng16-16.dll
* libtiff-5.dll
* libwebp-7.dll
* zlib1.dll

## Example

```cpp

#include "BLT.h"

// Everything is in BLT namespace
using namespace BLT;

// WIP
// class player : Actor
// {
// 	void create() override
// 	{
// 		// do create stuff
// 	}
//
// 	void step() override
// 	{
// 		// do step stuff
// 	}
// 
// };


int main(int argc, char* args[])
{
	// Create a game instance
	Game* game = Game::getInstance();

	// Create a sprite that can be instantiated
	game->createSpriteBlueprint("spr_astronaut_idle", "res/images/astronaut.png");

	// Edit the sprite blueprint
	SpriteBlueprint* astro_idle = game->getSpriteBlueprint("spr_astronaut_idle");
	astro_idle->origin = Vector2i{ astro_idle->size.x / 2, astro_idle->size.y - 1 }; // Bottom center

	// Another sprite (sprite frames of animation to come)
	SpriteBlueprint* hook = game->createSpriteBlueprint("spr_hook", "res/images/hook.png");

	// Without a room, there is no game
	RoomBlueprint* rm0 = game->createRoomBlueprint("rm0");
	
	// First layer added renders first, so other layers render on top
	// Asset layer holds graphics, being a Sprite instance with a transform (position, scale, rotation)
	AssetLayerBlueprint* al = rm0->addAssetLayer("Assets");

	// Adding assets to be instantiated when the room starts
	al->addElement(AssetLayerElementBlueprint{ "spr_astronaut_idle", Transform{Vector2f{400.f, 300.f}} });
	al->addElement(AssetLayerElementBlueprint{ "spr_hook", Transform{Vector2f{100.f, 100.f}} });

	// Actors - WIP
	// ActorBlueprint* act_player = game->createActorBlueprint<player>("act_player");
	// act_player->assignSprite("spr_astro_idle");
	// InstanceLayerBlueprint* il = rm0->addInstanceLayer("Instances");
	// il->addElement(InstanceLayerElementBlueprint{"act_player", Transform{Vector2f{200.f, 300.f}, 45.f });

	// No more blueprints can be added after the game starts
	game->start();

	// Temporary solution for cleanup
	delete game;
	
	return 0;
}
```
