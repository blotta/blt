#include "RoomLayer.h"

namespace BLT
{
	AssetLayer::AssetLayer(std::string name)
		: RoomLayer{Asset, name} {}

	std::vector<AssetLayerElement>& const AssetLayer::getAssets()
	{
		return mAssets;
	}

	void AssetLayer::addElement(AssetLayerElement a)
	{
		mAssets.push_back(a);
	}

}
