#include "header.h"
#include "LoseState.h"
#include "GameEngine.h"
#include "ExampleDragableObjects.h"

void LoseState::drawBackground(GameEngine* e)
{
	//e->drawableObjectsChanged();
	//e->destroyOldObjects(true);
	// background color
	(*e).fillBackground(0x000000);

	// background image

	MappableImageObject* ob = new MappableImageObject(e->getShifter(), 550, 300, e, "resources/gameover.jpg", false);
	ob->setTransparencyColour(ob->getPixelColour(0, 0));
	e-> storeObjectInArray(4, ob);

	(*e).drawBackgroundString(500, 500, "CLICK 'R' TO REPLAY", 0xffffff, NULL);
}

void LoseState::mouseControl(GameEngine* e, int iButton, int iX, int iY)
{
}

void LoseState::keyControl(GameEngine* e, int iKeyCode)
{
	if (iKeyCode == 'R' || iKeyCode == 'r') {
		e->drawableObjectsChanged();

		// Destroy any existing objects
		e->destroyOldObjects(true);
		e->deletestate();
		e->setupstate();
		e->setState(e->getState('s'));
	}
}
