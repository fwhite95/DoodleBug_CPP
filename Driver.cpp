#include <iostream>
#include "DoodleBug_H.h"
#include "Ant_H.h"
#include <ctime>
#include <random>
#include <time.h>
#include <vector>
#include <Windows.h>

using namespace std;

//Functions definitions
void display(char arr[20][20]);

int main()
{
	//Varialbe declarations
	int startStop = 1;
	int randX, randY;
	int count = 0, turnCounter = 1;
	srand((unsigned int)time(0));
	char gridArr[20][20];
	int arrMaxSize = 400, arrCurrentSizeA = 100, arrCurrentSizeD = 5;
	bool exit = false;

	vector<Ant> antVec(100);
	vector<DoodleBug> doodleBugVec(5);

	//populates grid 
	for (int i = 0; i < 20; i++) {

		for (int j = 0; j < 20; j++) {
			gridArr[i][j] = '~';
		}
	}

	//Populate ants
	while (count < 100) {
		randX = rand() % 20;
		randY = rand() % 20;
		gridArr[randX][randY] = antVec[count].shapeA;
		antVec[count].setX(randX);
		antVec[count].setY(randY);
		count++;
	}
	
	count = 0;
	//populate doodlebugs
	while (count < 5) {
		
		randX = rand() % 20;
		randY = rand() % 20;

		if (gridArr[randX][randY] = '~') {
			gridArr[randX][randY] = doodleBugVec[count].shapeD;
			doodleBugVec[count].setX(randX);
			doodleBugVec[count].setY(randY);
			count++;
		}//loop to check if space occupied
		else {
			randX = rand() % 20;
			randY = rand() % 20;
		}
		
	}//while loop for number of doodleBugs

	//Running loop
	while (exit == false) 
	{

		if (GetAsyncKeyState(VK_ESCAPE))
		{
			exit = true;
		}

			for (size_t i = 0; i < antVec.size(); i++) {
				antVec[i].move(gridArr, antVec); //move ants
			}
			for (size_t j = 0; j < doodleBugVec.size(); j++) {
				doodleBugVec[j].move(gridArr, doodleBugVec);//move doodlebugs
			}
			for (size_t j = 0; j < doodleBugVec.size(); j++) {
				doodleBugVec[j].starve(gridArr, doodleBugVec, j);// starve doodlebugs
			}
			for (size_t i = 0; i < antVec.size(); i++) {
				antVec[i].breed(gridArr, antVec);//breed ants
			}
			for (size_t j = 0; j < doodleBugVec.size(); j++) {
				doodleBugVec[j].breed(gridArr, doodleBugVec);// breed doodlebugs
			}

			display(gridArr);
			//cout << "Enter 1 to continue: ";
			//cin >> startStop;
			cout << endl;
			Sleep(500);
		}

	return 0;
}


//function definitions
void display(char arr[20][20]) {
	for (int i = 0; i < 20; i++) {

		for (int j = 0; j < 20; j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}
}

