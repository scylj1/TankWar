#pragma once
#include "TankObject.h"
#include "UtilMovementPosition.h"
#include "BulletObject.h"

class MyTankObject :
	public TankObject
{
public:
	MyTankObject(GameEngine* pEngine, std::string up, std::string right, std::string down, std::string left, GameTile* t, int X, int Y, int d)
		: TankObject(pEngine, up, right, down, left, 50, 50, t)
	{
		
		m_iCurrentScreenX = X; // Starting position on the screen
		m_iCurrentScreenY = Y;
		dir = d;
	}

	virtual void virtDoUpdate(int iCurrentTime);
	

};

