#include "header.h"
#include "GameTile.h"

void GameTile::virtDrawTileAt(BaseEngine* pEngine, DrawingSurface* pSurface, int iMapX, int iMapY, int iStartPositionScreenX, int iStartPositionScreenY) const
{
	SimpleImage wallImage = ImageManager::loadImage("resources/wall1.jpg", true);
	SimpleImage wallImage2 = ImageManager::loadImage("resources/wall2.jpg", true);
	
	switch (getMapValue(iMapX, iMapY))
	{
	// floor
	case 0:
		pSurface->drawRectangle(
			iStartPositionScreenX,
			iStartPositionScreenY,
			iStartPositionScreenX + getTileWidth() - 1,
			iStartPositionScreenY + getTileHeight() - 1,
			0x000000);
		break;
	// wall
	case 1:

		wallImage.renderImage(pSurface, 0, 0, iStartPositionScreenX, iStartPositionScreenY,
			wallImage.getWidth(), wallImage.getHeight());		
		break;
	// dangerous wall
	case 2:
		wallImage2.renderImage(pSurface, 0, 0, iStartPositionScreenX, iStartPositionScreenY,
			wallImage.getWidth(), wallImage.getHeight());
		break;
	// button
	case 3:
		pSurface->drawOval(
			iStartPositionScreenX,
			iStartPositionScreenY,
			iStartPositionScreenX + getTileWidth() - 1,
			iStartPositionScreenY + getTileHeight() - 1,
			0xff0000);
		break;
	// destination
	case 4:
		pSurface->drawRectangle(
			iStartPositionScreenX,
			iStartPositionScreenY,
			iStartPositionScreenX + getTileWidth() - 1,
			iStartPositionScreenY + getTileHeight() - 1,
			0x0000ff);
		break;
	};
}
