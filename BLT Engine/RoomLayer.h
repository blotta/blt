#pragma once

#include <vector>
#include <string>

#include "Util.h"
#include "Sprite.h"

namespace BLT
{
	enum RoomLayerType
	{
		Asset,
		Instance,
		Background
	};

	/*-----------------------------------------------------------------*/
	/*----------------------- RoomLayer -------------------------------*/
	/*-----------------------------------------------------------------*/

	class RoomLayer
	{
	public:
		RoomLayer(RoomLayerType type, std::string name);
		virtual ~RoomLayer();

		const RoomLayerType type;
		const std::string name;
	};


	/*-----------------------------------------------------------------*/
	/*------------------- RoomLayerBlueprint --------------------------*/
	/*-----------------------------------------------------------------*/
	class RoomLayerBlueprint
	{
	public:
		RoomLayerBlueprint(RoomLayerType type, std::string name);
		virtual ~RoomLayerBlueprint();

		const RoomLayerType type;
		const std::string name;
	};


	/*-----------------------------------------------------------------*/
	/*-------------------- AssetLayerBlueprint ------------------------*/
	/*-----------------------------------------------------------------*/
	struct AssetLayerElementBlueprint
	{
		std::string sprite;
		Transform transform;
	};

	class AssetLayerBlueprint : public RoomLayerBlueprint
	{
	public:
		AssetLayerBlueprint(std::string name);
		~AssetLayerBlueprint();

		void addElement(AssetLayerElementBlueprint a);
		std::vector<AssetLayerElementBlueprint>& const getAssets();
	private:
		std::vector<AssetLayerElementBlueprint> mAssets;
	};

	/*-----------------------------------------------------------------*/
	/*-------------------- AssetLayer ---------------------------------*/
	/*-----------------------------------------------------------------*/
	struct AssetLayerElement
	{
		Sprite* sprite = nullptr;
		Transform transform;
		// AssetLayerElement(Sprite* s, Transform t) : sprite(s), transform(t) {}

		// For some reason, this makes iterators crash with read violation
		// Sprite* being freed on AssetLayer's destructor
		// ~AssetLayerElement() { delete sprite; }
	};

	class AssetLayer : public RoomLayer
	{
	public:
		AssetLayer(std::string name);
		~AssetLayer();

		void addElement(AssetLayerElement a);
		std::vector<AssetLayerElement>& const getAssets();
	private:
		std::vector<AssetLayerElement> mAssets;
	};
}
