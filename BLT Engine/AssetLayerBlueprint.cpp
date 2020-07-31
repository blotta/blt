#include "RoomLayer.h"

namespace BLT
{
	AssetLayerBlueprint::AssetLayerBlueprint(std::string name)
		: RoomLayerBlueprint{Asset, name} {}

	std::vector<AssetLayerElementBlueprint>& const AssetLayerBlueprint::getAssets()
	{
		return mAssets;
	}

	void AssetLayerBlueprint::addElement(AssetLayerElementBlueprint a)
	{
		mAssets.push_back(a);
	}
}