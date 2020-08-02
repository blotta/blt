#include "Room.h"

#include <iostream>

namespace BLT
{
	RoomBlueprint::RoomBlueprint(std::string name)
		: name(name)
	{
		std::cout << "Creating room blueprint '" << name << "'" << std::endl;
	}

	RoomBlueprint::~RoomBlueprint()
	{
		std::cout << "Deleting room blueprint '" << name << "'" << std::endl;
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
