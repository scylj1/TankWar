#include "header.h"
#include "EnemyTankObject.h"

void EnemyTankObject::virtDoUpdate(int iCurrentTime)
{
	if (!isVisible() || getEngine()->isPaused())
		return;

	// save
	if (getEngine()->isKeyPressed(SDLK_k)) {
		if (e->isPaused() == false) {
			ofstream outfile1("resources/savedEnemytank.txt");

			outfile1 << m_iCurrentScreenX << endl;
			outfile1 << m_iCurrentScreenY << endl;
			outfile1 << dir << endl;

			outfile1.close();
		}
	}


	// collide detection, move
	DisplayableObject* tank = e->getDisplayableObject(1);
	int tankX = 0, tankY = 0;
	if (tank != nullptr) {
		tankX = tank->getXCentre() - 25;
		tankY = tank->getYCentre() - 25;

		if (CollisionDetection::checkRectangles(m_iCurrentScreenX, m_iCurrentScreenX + 50, m_iCurrentScreenY, m_iCurrentScreenY + 50, tankX, tankX + 50, tankY, tankY + 50)) {

			tank->setShouldDeleteOnRemoval(true);
			setShouldDeleteOnRemoval(true);
			e->setState(e->getState('l'));
		}

		if (m_iCurrentScreenX % 50 == 0 && m_iCurrentScreenY % 50 == 0) {
			for (int y = 0; y < 12; y++)
			{
				for (int x = 0; x < 16; x++) {
					if (getMap(x, y) == 0) {
						way[y][x] = -1;
					}
					else {
						way[y][x] = -2;
					}
				}
			}
			way[tankY / 50][tankX / 50] = 0;

			for (int p = 0; p < 50; p++) {
				for (int y = 1; y < 12; y++)
				{
					for (int x = 1; x < 16; x++) {
						if (way[y][x] == p) {
							bool flag = true;
							if (way[y - 1][x] != -2) {
								for (int k = 0; k <= p; k++) {
									if (way[y - 1][x] == k) {
										flag = false;
									}
								}
								if (flag) {
									way[y - 1][x] = p + 1;
								}
							}
							flag = true;
							if (way[y + 1][x] != -2) {
								for (int k = 0; k <= p; k++) {
									if (way[y + 1][x] == k) {
										flag = false;
									}
								}

								if (flag) {
									way[y + 1][x] = p + 1;
								}
							}
							flag = true;
							if (way[y][x + 1] != -2) {
								for (int k = 0; k <= p; k++) {
									if (way[y][x + 1] == k) {
										flag = false;
									}
								}
								if (flag) {
									way[y][x + 1] = p + 1;
								}
							}
							flag = true;
							if (way[y][x - 1] != -2) {
								for (int k = 0; k <= p; k++) {
									if (way[y][x - 1] == k) {
										flag = false;
									}
								}
								if (flag) {
									way[y][x - 1] = p + 1;
								}
							}

						}
					}
				}
			}

			/*for (int y = 0; y < 12; y++)
			{
				for (int x = 0; x < 16; x++) {
					cout << way[y][x] << "   ";
				}
				cout << endl;
			}*/
			
			newX = m_iCurrentScreenX;
			newY = m_iCurrentScreenY;


			int newX1 = newX + 1, newY1 = newY;
			if (isValid(newX1, newY1, tankX, tankY, 1) == 1) {
				int temp = way[newY1 / 50][(newX1 + 49) / 50];
				//cout << "right" << temp << endl;
				if (temp != -2 && temp < shortest) {
					shortest = temp;
					dir = 1;
				}

			}

			int newX2 = newX - 1, newY2 = newY;
			if (isValid(newX2, newY2, tankX, tankY, 3) == 3) {
				int temp = way[newY2 / 50][(newX2 - 49) / 50];
				//cout << "left" << temp << endl;
				if (temp != -2 && temp < shortest) {
					shortest = temp;
					dir = 3;
				}
			}

			int newX3 = newX, newY3 = newY + 1;
			if (isValid(newX3, newY3, tankX, tankY, 2) == 2) {
				int temp = way[(newY3 + 49) / 50][newX3 / 50];
				//cout << "down" << temp << endl;
				if (temp != -2 && temp < shortest) {
					shortest = temp;
					dir = 2;
				}
			}

			int newX4 = newX, newY4 = newY - 1;
			if (isValid(newX4, newY4, tankX, tankY, 0) == 0) {
				int temp = way[(newY4 - 49) / 50][newX4 / 50];
				//cout << "up" << temp << endl;
				if (temp != -2 && temp < shortest) {
					shortest = temp;
					dir = 0;
				}
			}

		}

		if (dir == 0) { m_iCurrentScreenY -= 1; }
		if (dir == 1) { m_iCurrentScreenX += 1; }
		if (dir == 2) { m_iCurrentScreenY += 1; }
		if (dir == 3) { m_iCurrentScreenX -= 1; }
		getEngine()->lockForegroundForDrawing();
		virtDraw();
		getEngine()->unlockForegroundForDrawing();
		shortest = 1000;
		//cout << m_iCurrentScreenX << endl << m_iCurrentScreenY << endl<<way[m_iCurrentScreenY/50][m_iCurrentScreenX/50]<< endl;


	}

	if (this->deleteOnRemoval()) {
		e->removeDisplayableObject(this);
		e->drawableObjectsChanged();
		delete(this);
	}

}
