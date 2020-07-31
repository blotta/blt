#pragma once

#include <string>
#include <vector>

#include "RoomLayer.h"

namespace BLT
{
	class Room;

	/*-----------------------------------------------------------------*/
	/*-------------------- RoomBlueprint ------------------------------*/
	/*-----------------------------------------------------------------*/
	class RoomBlueprint
	{
	public:
		RoomBlueprint(std::string name);
		// Room(std::string name);
		~RoomBlueprint();
		const std::string name;

		Room* _instantiate();

		AssetLayerBlueprint* addAssetLayer(std::string name);
		// std::vector<RoomLayerBlueprint*> _getLayers();
	private:
		std::vector<RoomLayerBlueprint*> mLayers;
	};

	/*-----------------------------------------------------------------*/
	/*---------------------------- Room -------------------------------*/
	/*-----------------------------------------------------------------*/
	class Room
	{
	public:
		Room(std::string name, std::vector<RoomLayerBlueprint*> const &layers);
		~Room();

		const std::string name;
		void update();

	private:
		std::vector<RoomLayer*> mLayers;
	};
}
