#include "RoomLayer.h"

#include <iostream>

namespace BLT
{
	AssetLayerBlueprint::AssetLayerBlueprint(std::string name)
		: RoomLayerBlueprint{Asset, name}
	{
		std::cout << "Creating asset layer blueprint '" << name << "'" << std::endl;
	}

	AssetLayerBlueprint::~AssetLayerBlueprint()
	{
		std::cout << "Deleting asset layer blueprint '" << name << "'" << std::endl;
	}

	std::vector<AssetLayerElementBlueprint>& const AssetLayerBlueprint::getAssets()
	{
		return mAssets;
	}

	void AssetLayerBlueprint::addElement(AssetLayerElementBlueprint a)
	{
		mAssets.push_back(a);
	}
}