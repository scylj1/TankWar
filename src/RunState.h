#pragma once
#include "GameState.h"
#include "GameTile.h"
#include "time.h"
#include <fstream>
using namespace std;

class RunState :
    public GameState
{
public:

    RunState() {};
    ~RunState() {};
    virtual void drawBackground(GameEngine* e) override;
    virtual void mouseControl(GameEngine* e, int iButton, int iX, int iY) override;
    virtual void keyControl(GameEngine* e, int iKeyCode) override;
    virtual void drawString(GameEngine* e) override;


    friend ofstream& operator << (ofstream& output, const RunState& R)
    {
        for (int y = 0; y < 12; y++) {
            for (int x = 0; x < 16; x++) {
                output << (char)(R.t->getMapValue(x, y) + 'a');
            }
            output << endl;
        }
        //cout << 1;
        return output;
    }
    
private:
    bool ifsaved = false;
    clock_t t1;

};

