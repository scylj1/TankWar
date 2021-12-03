#pragma once
#include "TileManager.h"


class GameTile :
    public TileManager
{
public:
	GameTile(void) : TileManager(50, 50)
	{
	}


	// Draw a tile at a location on the screen determined by the tile position and the base X and Y co-ordinates
	virtual void virtDrawTileAt(
		BaseEngine* pEngine,
		DrawingSurface* pSurface,
		int iMapX, int iMapY,
		int iStartPositionScreenX, int iStartPositionScreenY) const override;
	

};

