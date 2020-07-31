#include <iostream>

#include <SDL.h>

#include "Room.h"
#include "Game.h"

namespace BLT
{
	Room::Room(std::string name, std::vector<RoomLayerBlueprint*> const &layers)
		: name(name)
	{
		// auto layer = layers.begin();
		for (auto layer : layers)
		{
			if (layer->type == Asset)
			{
				AssetLayerBlueprint* albp = (AssetLayerBlueprint*)layer;

				// Add new layer
				AssetLayer* assetLayer = new AssetLayer(albp->name);
				mLayers.emplace_back(assetLayer);

				// instantiate layer assets
				for (auto asset : albp->getAssets())
				{
					AssetLayerElement elem{
						Game::getInstance()->getSpriteBlueprint(asset.sprite)->_instantiate(),
						asset.transform
					};
					assetLayer->addElement(elem);
				}
			}

		}
	}

	Room::~Room()
	{
		for (auto layer : mLayers) {
			delete layer;
		}
		mLayers.clear();
	}

	void Room::update()
	{
		// std::cout << "Updating room '" << name << "'\n";

		for (auto layer : mLayers)
		{
			if (layer->type == Asset)
			{
				AssetLayer* al = (AssetLayer*)layer;
				for (auto asset : al->getAssets())
				{
					asset.sprite.render(asset.transform);
				}

			}
		}

	}
}
