#pragma once
#include "DisplayableObject.h"
#include "GameEngine.h"
#include "GameTile.h"


class TankObject :
    public DisplayableObject
{
public:
	TankObject(GameEngine* pEngine, std::string up, std::string right, std::string down, std::string left, int iMapX, int iMapY, GameTile* tm) 
		: DisplayableObject(pEngine, iMapX, iMapY, true),
		imageup(ImageManager::get()->getImagebyURL(up, true/*Load*/, false/*Keep it loaded*/)),
		imageright(ImageManager::get()->getImagebyURL(right, true/*Load*/, false/*Keep it loaded*/)),
		imagedown(ImageManager::get()->getImagebyURL(down, true/*Load*/, false/*Keep it loaded*/)),
		imageleft(ImageManager::get()->getImagebyURL(left, true/*Load*/, false/*Keep it loaded*/))
	{ 
		pEngine->notifyObjectsAboutKeys(true);
		this->tm = tm; 
		currentimage = imageup;
		e = pEngine;
		setShouldDeleteOnRemoval(false);
	};
	~TankObject(void);

	void virtDraw() override
	
	{
		if (isVisible())
		{
			switch (dir) {
			case 0:
				currentimage = imageup;
				break;
			case 1:
				currentimage = imageright;
				break;
			case 2:
				currentimage = imagedown;
				break;
			case 3:
				currentimage = imageleft;
				break;
			}
			currentimage.renderImageWithMask(getEngine()->getForegroundSurface(), 0, 0, m_iCurrentScreenX + m_iStartDrawPosX, m_iCurrentScreenY + m_iStartDrawPosY, m_iDrawWidth, m_iDrawHeight);
		}
	}
	void virtDoUpdate(int iCurrentTime) override;

	virtual bool virtIsPositionWithinObject(int iXS, int iYS) {
		int iMaskColor = currentimage.getTheData()->getRawPixelColour(currentimage.getTheData()->getWidth() - 1, currentimage.getTheData()->getHeight() - 1);
		int iX, iY = m_iCurrentScreenY;
		for (int iYOffset = 0; iYOffset < 50; iYOffset++)
		{
			iX = m_iCurrentScreenX;
			for (int iXOffset = 0; iXOffset < 50; iXOffset++)
			{
				int iPixel = currentimage.getTheData()->getRawPixelColour(iXOffset, iYOffset);
				if (iPixel != iMaskColor) {
					if (iX == iXS && iY == iYS) {
						return true;
					}
				}
				iX++;
			}
			iY++;
		}
		return false;
	}

	
	
protected:
	
	// The image to draw
	SimpleImage imageup;
	SimpleImage imageright;
	SimpleImage imagedown;
	SimpleImage imageleft;
	SimpleImage currentimage;

	GameEngine* e;

	GameTile* tm;
	int dir = 0;

	template <typename T1, typename T2>
	int getMap(const T1& x, const T2& y)
	{
		return tm->getMapValue((int)x, (int)y);
	}
};



