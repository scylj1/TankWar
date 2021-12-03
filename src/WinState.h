#pragma once
#include "GameState.h"
#include "MyImage.h"

class WinState :
    public GameState
{
public:
    WinState()
        : logoImage(ImageManager::get()->getImagebyURL("resources/win.bmp", true/*Load*/, false/*Keep it loaded*/).getTheData()) {};

    virtual void drawBackground(GameEngine* e) override;
    virtual void mouseControl(GameEngine* e, int iButton, int iX, int iY) override;
    virtual void keyControl(GameEngine* e, int iKeyCode) override;

private:
    MyImage logoImage;
};

