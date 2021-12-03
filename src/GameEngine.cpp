#include "header.h"
#include "GameEngine.h"

int GameEngine::virtInitialise()
{
	getBackgroundSurface()->setDrawPointsFilter(&scroll);
	getForegroundSurface()->setDrawPointsFilter(&scroll);

	return BaseEngine::virtInitialise();
}

void GameEngine::virtSetupBackgroundBuffer()
{
	(*current).drawBackground(this);

}

int GameEngine::virtInitialiseObjects()
{
	drawableObjectsChanged();

	destroyOldObjects(true);

	createObjectArray(2000);

	return 0;
}

void GameEngine::virtMouseDown(int iButton, int iX, int iY)
{
	(*current).mouseControl(this, iButton, iX, iY);
}

void GameEngine::virtKeyDown(int iKeyCode)
{
	if (iKeyCode == SDLK_ESCAPE) { // End program when escape is pressed
		setExitWithCode(0);
	}
	
	(*current).keyControl(this, iKeyCode);
	redrawDisplay();
}

void GameEngine::virtDrawStringsOnTop()
{
	
	current->drawString(this);
}

void GameEngine::virtCleanUp()
{
	for (int i = 0; i < 5; i++) {
		DisplayableObject* o = getDisplayableObject(i);
		if (o != nullptr) {
			o->setShouldDeleteOnRemoval(true);
		}
	}
	drawableObjectsChanged();
	// Destroy any existing objects
	destroyOldObjects(true);

	deletestate();	
}



void GameEngine::virtMainLoopDoBeforeUpdate()
{
	int iOffset = getModifiedTime() / 10;
	//std::cout << iOffset;
	shifter1.setXShift((double)iOffset);

	this->redrawDisplay();
}

void GameEngine::setState(GameState* s)
{
	current = s;
	lockAndSetupBackground();
	redrawDisplay();
}

