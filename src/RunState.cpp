#include "header.h"
#include "RunState.h"
#include "GameEngine.h"
#include "MyTankObject.h"
#include "EnemyTankObject.h"
#include <fstream>
#include <string>
using namespace std;


void RunState::drawBackground(GameEngine* e)
{
	// background color
	(*e).fillBackground(0x000000);	

	SimpleImage logoImage = ImageManager::loadImage("resources/instruction.bmp", true);
	logoImage.renderImage((*e).getBackgroundSurface(), 0, 0, 830, 50,
		logoImage.getWidth(), logoImage.getHeight());

	string level;
	if (e->getLevel() == 1) {
		level = "resources/level1.txt";
		
		e->storeObjectInArray(0, new EnemyTankObject(e, "resources/p2tank_up.jpg", "resources/p2tank_right.jpg", "resources/p2tank_down.jpg", "resources/p2tank_left.jpg", e->getTile(), 650, 500, 0));
		e->storeObjectInArray(1, new MyTankObject(e, "resources/tank_up.jpg", "resources/tank_right.jpg", "resources/tank_down.jpg", "resources/tank_left.jpg", e->getTile(), 50, 50, 0));
		// Make everything invisible to start with
		e->setAllObjectsVisible(false);
	}
	else if (e->getLevel() == 2) {
		level = "resources/level2.txt";
		e->storeObjectInArray(0, new EnemyTankObject(e, "resources/p2tank_up.jpg", "resources/p2tank_right.jpg", "resources/p2tank_down.jpg", "resources/p2tank_left.jpg", e->getTile(), 700, 50, 0));
		e->storeObjectInArray(1, new MyTankObject(e, "resources/tank_up.jpg", "resources/tank_right.jpg", "resources/tank_down.jpg", "resources/tank_left.jpg", e->getTile(), 50, 500, 0));
		// Make everything invisible to start with
		e->setAllObjectsVisible(false);
	}
	else if (e->getLevel() == 0) {
		//_CrtSetBreakAlloc(790);
		level = "resources/saved.txt";
		ifstream myobject("resources/savedEnemytank.txt");
		int X, Y, dir;
		while (!myobject.eof()) {
			myobject >> X >> Y >> dir;
			
		}	
		if (X != -1) {
			e->storeObjectInArray(0, new EnemyTankObject(e, "resources/p2tank_up.jpg", "resources/p2tank_right.jpg", "resources/p2tank_down.jpg", "resources/p2tank_left.jpg", e->getTile(), X, Y, dir));
		}
		myobject.close();

		ifstream mytank("resources/savedMytank.txt");
		while (!mytank.eof()) {
			mytank >> X >> Y >> dir;
			
		}
		if (X != -1) {
			e->storeObjectInArray(1, new MyTankObject(e, "resources/tank_up.jpg", "resources/tank_right.jpg", "resources/tank_down.jpg", "resources/tank_left.jpg", e->getTile(), X, Y, dir));
		}
		mytank.close();

		ifstream mybullet("resources/savedBullet.txt");
		int sx, sy;
		while (!mybullet.eof()) {
			mybullet >> X >> Y >> sx >> sy;
			
		}
		if (X != -1) {
			e->storeObjectInArray(2, new BulletObject(e, X, Y, sx, sy, e->getTile()));
		}
		mybullet.close();
		e->setAllObjectsVisible(false);
	}

	char data[12][16];
	ifstream myfile(level);
	
	char temp;
	if (!myfile.is_open())
	{
		cout << "no file" << endl;
	}
	int i = 0, j = 0;
	while(myfile.get(temp))
	{
		//cout << temp << endl;
		if (temp == '\n') {
			j = 0;
			i++;
		}
		else {
			data[i][j] = temp;
			j++;
			//cout << data[i][j] << endl;
		}
	}
	myfile.close();


	// Specify how many tiles wide and high
	t = e->getTile();
	t->setMapSize(16, 12);
	// Set up the tiles
	for (int y = 0; y < 12; y++)
		for (int x = 0; x < 16; x++)
			t->setMapValue(x, y, data[y][x] - 'a');

	/*for (int y = 0; y < 12; y++)
	{
		for (int x = 0; x < 16; x++)
			std::cout << t->getMapValue(x, y);
		std::cout << std::endl;
	}*/

	// Specify the screen x,y of top left corner
	t->setTopLeftPositionOnScreen(0, 0);
	t->drawAllTiles(e, e->getBackgroundSurface());

	// Ensure objects become visible now - we hid them initially
	(*e).setAllObjectsVisible(true);
	
	
}

void RunState::mouseControl(GameEngine* e, int iButton, int iX, int iY)
{
}

void RunState::keyControl(GameEngine* e, int iKeyCode)
{
	if (iKeyCode == 'p' || iKeyCode == 'P') {
		if (e->isPaused()) {
			e->unpause();
		}
		else {
			e->pause();
		}
		
	}
	if (e->isPaused() == false) {
		if (iKeyCode == 'k' || iKeyCode == 'K') {
			ofstream outfile("resources/saved.txt");
			outfile << *this;
			outfile.close();

			DisplayableObject* o = e->getDisplayableObject(0);
			if (o == nullptr) {
				ofstream outfile1("resources/savedEnemytank.txt");
				outfile1 << -1 << endl;
				outfile1 << -1 << endl;
				outfile1 << -1 << endl;
				outfile1.close();
			}
			o = e->getDisplayableObject(1);
			if (o == nullptr) {
				ofstream outfile1("resources/savedMytank.txt");
				outfile1 << -1 << endl;
				outfile1 << -1 << endl;
				outfile1 << -1 << endl;
				outfile1.close();
			}
			o = e->getDisplayableObject(2);
			if (o == nullptr) {
				ofstream outfile1("resources/savedBullet.txt");
				outfile1 << -1 << endl;
				outfile1 << -1 << endl;
				outfile1 << -1 << endl;
				outfile1 << -1 << endl;
				outfile1.close();
			}

			ifsaved = true;
			t1 = clock();
		}
	}
}

void RunState::drawString(GameEngine* e)
{
	clock_t t = clock();
	char buf1[128];
	sprintf(buf1, "GOOD LUCK!");
	
	if (e->isPaused() == false) {
		if ((t/ CLOCKS_PER_SEC)%2==0) {
			e->drawForegroundString(830, 20, buf1, 0xffffff, NULL);
		}

		if (ifsaved) {
			e->drawForegroundString(830, 550, "saved", 0xffffff, NULL);
		}

		if ((t - t1) / CLOCKS_PER_SEC == 3) {
			ifsaved = false;
		}
	}
	
	if (e->isPaused()) {
		e->drawForegroundString(200, 260, "Paused. Press 'P' to continue", 0xffffff, NULL);
	}
	
}
