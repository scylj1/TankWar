#include "header.h"
#include "MyTankObject.h"

void MyTankObject::virtDoUpdate(int iCurrentTime)
{
	if (!isVisible() || getEngine()->isPaused())
		return;


	if (getEngine()->isKeyPressed(SDLK_SPACE)) {

		if (e->getDisplayableObject(2) == nullptr) {


			switch (dir) {
			case 0:
				e->storeObjectInArray(2, new BulletObject(e, m_iCurrentScreenX + 20, m_iCurrentScreenY - 10, 0, -1, tm));
				break;
			case 1:
				e->storeObjectInArray(2, new BulletObject(e, m_iCurrentScreenX + 50, m_iCurrentScreenY + 20, 1, 0, tm));
				break;
			case 2:
				e->storeObjectInArray(2, new BulletObject(e, m_iCurrentScreenX + 20, m_iCurrentScreenY + 50, 0, 1, tm));
				break;
			case 3:
				e->storeObjectInArray(2, new BulletObject(e, m_iCurrentScreenX - 10, m_iCurrentScreenY + 20, -1, 0, tm));
				break;
			}
		}
		e->setAllObjectsVisible(true);
	}

	int newX = m_iCurrentScreenX, newY = m_iCurrentScreenY;
	// Change position if player presses a key
	if (getEngine()->isKeyPressed(SDLK_w)) {
		newY = m_iCurrentScreenY - 1;
		dir = 0;
	}
	if (getEngine()->isKeyPressed(SDLK_s)) {
		newY = m_iCurrentScreenY + 1;
		dir = 2;
	}
	if (getEngine()->isKeyPressed(SDLK_a)) {
		newX = m_iCurrentScreenX - 1;
		dir = 3;
	}
	if (getEngine()->isKeyPressed(SDLK_d)) {
		newX = m_iCurrentScreenX + 1;
		dir = 1;
	}
	if (getEngine()->isKeyPressed(SDLK_k)) {
		if (e->isPaused() == false) {
			ofstream outfile1("resources/savedMytank.txt");

			outfile1 << m_iCurrentScreenX << endl;
			outfile1 << m_iCurrentScreenY << endl;
			outfile1 << dir << endl;

			outfile1.close();
		}
	}
	DisplayableObject* tank = e->getDisplayableObject(0);
	DisplayableObject* bullet = e->getDisplayableObject(2);

	if (tm->isValidTilePosition(newX - 50, newY - 50) && tm->isValidTilePosition(newX + 100, newY + 100))
	{
		if (((getMap(newX / 50, newY / 50) == 2) || (getMap(ceil(newX / 50.0), newY / 50) == 2)) ||
			((getMap(newX / 50, ceil(newY / 50.0)) == 2) || (getMap(ceil(newX / 50.0), ceil(newY / 50.0)) == 2))) {

			if (tank != nullptr) {

				tank->setShouldDeleteOnRemoval(true);
			}
			if (bullet != nullptr) {

				bullet->setShouldDeleteOnRemoval(true);
			}
			setShouldDeleteOnRemoval(true);
			e->setState(e->getState('l'));

		}

		if (((getMap(newX / 50, newY / 50) == 3) || (getMap(ceil(newX / 50.0), newY / 50) == 3)) ||
			((getMap(newX / 50, ceil(newY / 50.0)) == 3) || (getMap(ceil(newX / 50.0), ceil(newY / 50.0)) == 3))) {
			for (int y = 0; y < 12; y++)
			{
				for (int x = 0; x < 16; x++)
					if (getMap(x, y) == 3) {
						tm->setMapValue(x, y, 0);
					}

			}
			tm->setMapValue(14, 10, 4);
			// Specify the screen x,y of top left corner
			tm->setTopLeftPositionOnScreen(0, 0);
			tm->drawAllTiles(e, e->getBackgroundSurface());
		}
		if (((getMap(newX / 50, newY / 50) == 4) || (getMap(ceil(newX / 50.0), newY / 50) == 4)) ||
			((getMap(newX / 50, ceil(newY / 50.0)) == 4) || (getMap(ceil(newX / 50.0), ceil(newY / 50.0)) == 4))) {

			if (tank != nullptr) {

				tank->setShouldDeleteOnRemoval(true);
			}
			if (bullet != nullptr) {

				bullet->setShouldDeleteOnRemoval(true);
			}
			setShouldDeleteOnRemoval(true);
			e->setState(e->getState('e'));
		}
		if (((getMap(newX / 50, newY / 50) == 0) && (getMap(ceil(newX / 50.0), newY / 50) == 0)) &&
			((getMap(newX / 50, ceil(newY / 50.0)) == 0) && (getMap(ceil(newX / 50.0), ceil(newY / 50.0)) == 0))) {
			m_iCurrentScreenX = newX;
			m_iCurrentScreenY = newY;
			getEngine()->lockForegroundForDrawing();
			virtDraw();
			getEngine()->unlockForegroundForDrawing();
		}

	}

	// Ensure that the objects get redrawn on the display
	this->redrawDisplay();
	if (deleteOnRemoval()) {
		//cout << 1 << endl;
		e->removeDisplayableObject(this);
		e->drawableObjectsChanged();
		delete(this);
	}
}
