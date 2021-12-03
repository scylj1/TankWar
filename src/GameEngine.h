#pragma once
#include "BaseEngine.h"
#include "GameState.h"
#include "StartState.h"
#include "LoseState.h"
#include "RunState.h"
#include "WinState.h"
#include "EnterState.h"

#include "ExampleFilterPointClasses.h" 
#include "ImagePixelMapping.h"
#include "ChooseState.h"

class GameEngine :
    public BaseEngine
{
public:
    GameEngine() 
        : zoom(0, 0, this), scroll(0, 0, &zoom) , shifter1(0, 0) {
        setupstate();
    };
    int virtInitialise() override;

    virtual void virtSetupBackgroundBuffer() override;
    virtual int virtInitialiseObjects() override;
    virtual void virtMouseDown(int iButton, int iX, int iY) override;
    virtual void virtKeyDown(int iKeyCode) override;
    virtual void virtDrawStringsOnTop() override;
    virtual void virtCleanUp() override;

    virtual void virtMainLoopDoBeforeUpdate() override;
 
    void setState(GameState* s);

    GameState* getState(char c) {
        switch (c) {
        case 's':
            return s;
        case 'c':
            return cs;
        case 'r':
            return r;
        case 'w':
            return w;
        case 'l':
            return l;
        case 'e':
            return e;
        }
        return 0;
    };

    GameTile* getTile() { return &t; };
    
    MyImagePixelMapping* getShifter() {
        return &shifter1;
    }
    MyFilterZoom* getScaling() {
        return &zoom;
    }
    MyFilterScroll* getTranslation() {
        return &scroll;
    }

    void setLevel(int l) {
        level = l;
    }
    int getLevel() {
        return level;
    }

    void setupstate() {
        s = new StartState();
        cs = new ChooseState();
        r = new RunState();
        w = new WinState();
        l = new LoseState();
        e = new EnterState();
        current = s;
    }

    void deletestate() {
        delete s;
        delete cs;
        delete r;
        delete w;
        delete l;
        delete e;
    }

private:
    int level;
    GameTile t;
    GameState *current;
    StartState *s;
    ChooseState* cs;
    RunState* r;
    LoseState* l;
    WinState* w;
    EnterState* e;

   MyFilterZoom zoom;
   MyFilterScroll scroll;

   MyImagePixelMapping shifter1;
  
};