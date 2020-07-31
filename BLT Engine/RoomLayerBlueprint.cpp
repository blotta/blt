
#include "RoomLayer.h"

#include <string>

namespace BLT
{
	RoomLayerBlueprint::RoomLayerBlueprint(RoomLayerType type, std::string name)
		: name(name), type(type) {}
	RoomLayerBlueprint::~RoomLayerBlueprint() {}
}
