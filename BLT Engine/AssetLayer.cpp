#include "RoomLayer.h"

namespace BLT
{
	AssetLayer::AssetLayer(std::string name)
		: RoomLayer{Asset, name}
	{
	}

	AssetLayer::~AssetLayer()
	{
		for (AssetLayerElement e : mAssets)
		{
			delete e.sprite;
		}
	}

	std::vector<AssetLayerElement>& const AssetLayer::getAssets()
	{
		return mAssets;
	}

	void AssetLayer::addElement(AssetLayerElement a)
	{
		mAssets.push_back(a);
	}

}
