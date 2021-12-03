#pragma once
#include "GameState.h"

class ChooseState :
    public GameState
{
public:
    virtual void drawBackground(GameEngine* e) override;
    virtual void mouseControl(GameEngine* e, int iButton, int iX, int iY) override;
 
};

