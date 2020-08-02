#pragma once

#include "Sprite.h"

namespace BLT
{
	/*-----------------------------------------------------------------*/
	/*---------------------------- Actor ------------------------------*/
	/*-----------------------------------------------------------------*/
	class Actor
	{
	public:
		virtual ~Actor();

		Transform transform;

		// can be null
		Sprite* sprite = nullptr;

		void assignSprite(std::string spr);

		// Events
		virtual void create() = 0;
		virtual void step() = 0;
		virtual void draw();
	};
}

