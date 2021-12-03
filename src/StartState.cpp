#include "header.h"
#include "StartState.h"
#include "GameEngine.h"

void StartState::drawBackground(GameEngine* e) { 
	// background color
	(*e).fillBackground(0x000000);

	
}

void StartState::mouseControl(GameEngine* e, int iButton, int iX, int iY)
{
	if (iButton == SDL_BUTTON_LEFT)
	{
		if (iX >= 300 && iX <= 400 && iY >= 240 && iY <= 290) {
			
			e->getScaling()->adapt();
			e->getTranslation()->adapt();
			(*e).setState(e->getState('c'));
		}
		if (iX >= 600 && iX <= 700 && iY >= 240 && iY <= 290) {
			exit(0);
		}
	}
}

void StartState::keyControl(GameEngine* e, int iKeyCode)
{
	switch (iKeyCode)
	{
	case SDLK_LEFT:
		e->getTranslation()->changeOffset(-10, 0);
		e->redrawDisplay();
		break;
	case SDLK_RIGHT:
		e->getTranslation()->changeOffset(10, 0);
		e->redrawDisplay();
		break;
	case SDLK_UP:
		e->getTranslation()->changeOffset(0, -10);
		e->redrawDisplay();
		break;
	case SDLK_DOWN:
		e->getTranslation()->changeOffset(0, 10);
		e->redrawDisplay();
		break;
	
	case SDLK_z:
		e->getScaling()->stretch();
		break;
	case SDLK_x:
		e->getScaling()->compress();
		break;
	}
	
}

void StartState::drawString(GameEngine* e)
{
	// Foreground image
	SimpleImage logoImage = ImageManager::loadImage("resources/logo.bmp", true);
	logoImage.renderImage((*e).getForegroundSurface(), 0, 0, 285, 0,
		logoImage.getWidth(), logoImage.getHeight());


	(*e).lockForegroundForDrawing();
	(*e).drawForegroundRectangle(300, 240, 400, 290, 0xffffff);
	(*e).drawForegroundRectangle(600, 240, 700, 290, 0xffffff);
	(*e).unlockForegroundForDrawing();
	//(*e).redrawDisplay();

	(*e).drawForegroundString(300, 250, "START", 0x000000, NULL);
	(*e).drawForegroundString(620, 250, "QUIT", 0x000000, NULL);

	(*e).drawForegroundString(400, 400, "CLICK TO START", 0xffffff, NULL);
	(*e).drawForegroundString(400, 450, "Z OR X TO ZOOM", 0xffffff, NULL);
	(*e).drawForegroundString(400, 500, "ARROW KEY TO SCROLL", 0xffffff, NULL);
}
