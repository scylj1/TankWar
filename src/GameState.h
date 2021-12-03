#pragma once
#include "header.h"
#include "GameTile.h"
class GameEngine;
class GameState
{
public:
	GameState() {};
	~GameState() {};
	virtual void drawBackground(GameEngine* e) {};
	virtual void mouseControl(GameEngine* e, int iButton, int iX, int iY) {};
	virtual void keyControl(GameEngine* e, int iKeyCode) {};
	virtual void drawString(GameEngine* e) {};

protected:
	GameTile* t;
};
