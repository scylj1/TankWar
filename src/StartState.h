#pragma once
#include "header.h"
#include "GameState.h"


class StartState :
    public GameState
{
public :
    virtual void drawBackground(GameEngine* e) override;
    virtual void mouseControl(GameEngine* e, int iButton, int iX, int iY) override;
    virtual void keyControl(GameEngine* e, int iKeyCode) override;
    virtual void drawString(GameEngine* e) override;
};



