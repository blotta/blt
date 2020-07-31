#include "RoomLayer.h"

#include <string>

namespace BLT
{
	RoomLayer::RoomLayer(RoomLayerType type, std::string name)
		: name(name), type(type) {}
	RoomLayer::~RoomLayer() {}
}
