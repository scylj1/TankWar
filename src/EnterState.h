#pragma once
#include "GameState.h"
class EnterState :
    public GameState
{
public:
    EnterState() {
        for (int j = 0; j < 256; j++) {
            c[j] = ' ';
        }
        i = 0;
    }
    virtual void drawBackground(GameEngine* e) override;
    virtual void mouseControl(GameEngine* e, int iButton, int iX, int iY) override;
    virtual void keyControl(GameEngine* e, int iKeyCode) override;
    char c[256];
    int i;
};

