#pragma once
#include "GameState.h"


class LoseState :
    public GameState
{
public:
    
    
    virtual void drawBackground(GameEngine* e) override;
    virtual void mouseControl(GameEngine* e, int iButton, int iX, int iY) override;
    virtual void keyControl(GameEngine* e, int iKeyCode) override;

    //ImagePixelMappingShiftXY* m;
};

