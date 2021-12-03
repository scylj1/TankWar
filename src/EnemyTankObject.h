#pragma once
#include "TankObject.h"
#include "UtilCollisionDetection.h"

class EnemyTankObject :
    public TankObject
{
public:
	EnemyTankObject(GameEngine* pEngine, std::string up, std::string right, std::string down, std::string left, GameTile* t, int X, int Y, int d)
		: TankObject(pEngine, up, right, down, left, 50, 50, t)
		
	{
		m_iCurrentScreenX = X; // Starting position on the screen
		m_iCurrentScreenY = Y;
		dir = d;
	}

	virtual void virtDoUpdate(int iCurrentTime);
	
protected:
	int newX = 0;
	int newY = 0;
	int shortest = 1000;
	int way[12][16];
	

	int isValid(int newX1, int newY1, int tankX, int tankY, int d) {
		if (tm->isValidTilePosition(newX1 - 50, newY1 - 50) && tm->isValidTilePosition(newX1 + 100, newY1 + 100))
		{
			if (((getMap(newX1 / 50, newY1 / 50) == 0) && (getMap(ceil(newX1 / 50.0), newY1 / 50) == 0)) &&
				((getMap(newX1 / 50, ceil(newY1 / 50.0)) == 0) && (getMap(ceil(newX1 / 50.0), ceil(newY1 / 50.0)) == 0))) {
				//cout << 111 << endl;
				return d;
			}
		}
		return 5;
	}

};


