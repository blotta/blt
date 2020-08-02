#include "Actor.h"

#include "Game.h"

namespace BLT
{
	void Actor::assignSprite(std::string spr)
	{
		if (sprite != nullptr)
		{
			delete sprite;
		}

		sprite = Game::getInstance()->getSpriteBlueprint(spr)->_instantiate();
	}

	void Actor::draw()
	{
		// draw_self()
	}
}
