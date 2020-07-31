#include "Room.h"

namespace BLT
{
	RoomBlueprint::RoomBlueprint(std::string name)
		: name(name)
	{

	}

	RoomBlueprint::~RoomBlueprint()
	{
		for (auto layer : mLayers) {
			delete layer;
		}
		mLayers.clear();
	}

	Room* RoomBlueprint::_instantiate()
	{
		return new Room(name, mLayers);
	}

	AssetLayerBlueprint* RoomBlueprint::addAssetLayer(std::string name)
	{
		AssetLayerBlueprint* al = new AssetLayerBlueprint(name);
		mLayers.emplace_back(al);
		return al;
	}
}
