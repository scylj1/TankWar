#pragma once
#include "DisplayableObject.h"
#include "GameEngine.h"
#include "GameTile.h"

class BulletObject :
    public DisplayableObject
{
public:
	BulletObject(GameEngine* pEngine, int X, int Y, int speedX, int speedY, GameTile* tm)
		: DisplayableObject(pEngine, 10, 10, tm),
		m_dX(X), m_dY(Y), m_dSX(speedX), m_dSY(speedY)
	{
		m_iCurrentScreenX = X; // Starting position on the screen
		m_iCurrentScreenY = Y;
		e = pEngine;
		this->tm = tm;
		setShouldDeleteOnRemoval(false);
	}

	virtual void virtDraw()
	{

		if (!isVisible())
			return;
		
		e->drawForegroundOval(
			m_iCurrentScreenX,
			m_iCurrentScreenY,
			m_iCurrentScreenX + 10,
			m_iCurrentScreenY+10,
			0xffffff);
	}

	virtual void virtDoUpdate(int iCurrentTime);
	
	virtual bool virtIsPositionWithinObject(int iX, int iY) {
		double fCentreX = m_iCurrentScreenX + 5;
		double fCentreY = m_iCurrentScreenY + 5;
		if (((iX - fCentreX) * (iX - fCentreX) + (iY - fCentreY) * (iY - fCentreY)) <= 25) {
			return true;
		}
		return false;
	}
protected:
	GameEngine* e;
	
	int dir = 0;

	double m_dSX;
	double m_dSY;
	double m_dX;
	double m_dY;

	GameTile* tm;
};

