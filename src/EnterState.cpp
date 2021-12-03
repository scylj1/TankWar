#include "header.h"
#include "EnterState.h"
#include "GameEngine.h"

void EnterState::drawBackground(GameEngine* e)
{
	
	e->fillBackground(0x000000);
	(*e).drawBackgroundString(50, 200, "TYPE YOUR NAME, 'DELETE' FOR DELETE, 'ENTER' TO CONTINUE", 0xffffff, NULL);
}

void EnterState::mouseControl(GameEngine* e, int iButton, int iX, int iY)
{
}

void EnterState::keyControl(GameEngine* e, int iKeyCode)
{
	if (iKeyCode == SDLK_RETURN) {
		e->setState(e->getState('w'));
	}
	if (iKeyCode == SDLK_DELETE) {
		
		if (i > 0) {
			c[i - 1] = ' ';
			i--;
		}

	}
	if(iKeyCode>=33 && iKeyCode <=125){
		c[i] = char(iKeyCode);
		i++;
	}
	else {
		c[i] = ' ';
	}
	e->lockAndSetupBackground();
	e->lockBackgroundForDrawing();
	(*e).drawBackgroundString(400, 300, c, 0xffffff, NULL);
	e->unlockBackgroundForDrawing();
	
}
