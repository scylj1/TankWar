#include "header.h"
#include "WinState.h"
#include "GameEngine.h"


void WinState::drawBackground(GameEngine* e)
{
	
	e->fillBackground(0x000000);
	e->drawBackgroundString(400, 200, "YOU WIN!", 0xffffff, NULL);
	(*e).drawBackgroundString(500, 500, "CLICK 'R' TO REPLAY", 0xffffff, NULL);

	logoImage.renderImage((*e).getBackgroundSurface(), 0, 0, 285, 0,
		logoImage.getWidth(), logoImage.getHeight());
	logoImage.renderImageMirror((*e).getBackgroundSurface(), 0, 0, 285, 100,
		logoImage.getWidth(), logoImage.getHeight());
	
}

void WinState::mouseControl(GameEngine* e, int iButton, int iX, int iY)
{
}

void WinState::keyControl(GameEngine* e, int iKeyCode)
{
	if (iKeyCode == 'r' || iKeyCode == 'R') {
		e->drawableObjectsChanged();

		// Destroy any existing objects
		e->destroyOldObjects(true);
		e->deletestate();
		e->setupstate();
		(*e).setState(e->getState('s'));
	}
}
