
#include "RoomLayer.h"

#include <string>
#include <iostream>

namespace BLT
{
	RoomLayerBlueprint::RoomLayerBlueprint(RoomLayerType type, std::string name)
		: name(name), type(type) {}

	RoomLayerBlueprint::~RoomLayerBlueprint() {}
}
