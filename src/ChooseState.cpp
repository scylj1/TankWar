#include "header.h"
#include "ChooseState.h"
#include "GameEngine.h"

void ChooseState::drawBackground(GameEngine* e)
{
	(*e).fillBackground(0x000000);

	// Foreground image
	SimpleImage logoImage = ImageManager::loadImage("resources/logo.bmp", true);
	logoImage.renderImage((*e).getBackgroundSurface(), 0, 0, 285, 0,
		logoImage.getWidth(), logoImage.getHeight());

	(*e).drawBackgroundRectangle(300, 240, 400, 290, 0xffffff);
	(*e).drawBackgroundRectangle(600, 240, 700, 290, 0xffffff);
	(*e).drawBackgroundRectangle(300, 340, 700, 390, 0xffffff);
	//(*e).redrawDisplay();

	(*e).drawBackgroundString(300, 250, "LEVEL1", 0x000000, NULL);
	(*e).drawBackgroundString(600, 250, "LEVEL2", 0x000000, NULL);
	(*e).drawBackgroundString(370, 355, "LOAD LAST GAME", 0x000000, NULL);
}

void ChooseState::mouseControl(GameEngine* e, int iButton, int iX, int iY)
{
	if (iButton == SDL_BUTTON_LEFT)
	{
		if (iX >= 300 && iX <= 400 && iY >= 240 && iY <= 290) {
			e->setLevel(1);
			(*e).setState(e->getState('r'));
		}
		if (iX >= 600 && iX <= 700 && iY >= 240 && iY <= 290) {
			e->setLevel(2);
			(*e).setState(e->getState('r'));
		}
		if (iX >= 300 && iX <= 700 && iY >= 340 && iY <= 390) {
			e->setLevel(0);
			(*e).setState(e->getState('r'));
		}
	}
}
