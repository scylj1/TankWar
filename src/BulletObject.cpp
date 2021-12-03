#include "header.h"
#include "BulletObject.h"

void BulletObject::virtDoUpdate(int iCurrentTime)
{
	if (!isVisible() || getEngine()->isPaused())
		return;

	if (getEngine()->isKeyPressed(SDLK_k)) {
		if (e->isPaused() == false) {
			ofstream outfile1("resources/savedBullet.txt");

			outfile1 << m_iCurrentScreenX << endl;
			outfile1 << m_iCurrentScreenY << endl;
			outfile1 << m_dSX << endl;
			outfile1 << m_dSY << endl;

			outfile1.close();
		}
	}

	// Alter position for speed
	m_dX += m_dSX;
	m_dY += m_dSY;

	m_iCurrentScreenX = (int)(m_dX + 0.5);
	m_iCurrentScreenY = (int)(m_dY + 0.5);

	if (!(tm->isValidTilePosition(m_iCurrentScreenX - 50, m_iCurrentScreenY - 50) && tm->isValidTilePosition(m_iCurrentScreenX + 50, m_iCurrentScreenY + 50))) {

		setShouldDeleteOnRemoval(true);

	}

	// pixel detection
	DisplayableObject* tank1 = e->getDisplayableObject(0);

	if (tank1 != nullptr) {

		int iX, iY = m_iCurrentScreenY;

		for (int iYOffset = 0; iYOffset < 50; iYOffset++)
		{
			iX = m_iCurrentScreenX;
			for (int iXOffset = 0; iXOffset < 50; iXOffset++)
			{
				if (virtIsPositionWithinObject(iX, iY)) {
					if (tank1->virtIsPositionWithinObject(iX, iY)) {

						setShouldDeleteOnRemoval(true);
						tank1->setShouldDeleteOnRemoval(true);
					}
				}
				iX++;
			}
			iY++;
		}

	}
	this->redrawDisplay();
	if (deleteOnRemoval()) {
		e->removeDisplayableObject(this);
		e->drawableObjectsChanged();
		delete(this);
	}
}


