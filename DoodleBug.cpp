#include <iostream>
#include <vector>
#include "DoodleBug_H.h"
#include <algorithm>
using namespace std;

void DoodleBug::move(char arr[20][20], vector<DoodleBug> &doodleBugVec)
{
	//Randomly try to move up, down, left or right
	//if cell is occupied, then stay in current cell
	int randNum = 1 + rand() % 4;
	turnCountD++;

	if (randNum == 1) {
		if ((arr[getX()][getY() + 1] == '~' || arr[getX()][getY() + 1] == 'X') && (getY() + 1) < 20) {
			if (arr[getX()][getY() + 1] == 'X') {
				consumed++;
			}
			setY(getY() + 1);
			arr[getX()][getY()] = shapeD;
			arr[getX()][getY() - 1] = '~';

		}
	}
	else if (randNum == 2) {
		if ((arr[getX()][getY() - 1] == '~' || arr[getX()][getY() - 1] == 'X') && (getY() - 1) > 0) {
			if (arr[getX()][getY() - 1] == 'X') {
			consumed++;
		}
		setY(getY() - 1);
		arr[getX()][getY()] = shapeD;
		arr[getX()][getY() + 1] = '~';

	}
	}
	else if (randNum == 3) {
	 if ((arr[getX() + 1][getY()] == '~' || arr[getX() + 1][getY()] == 'X') && (getX() + 1) < 20) {
		if (arr[getX() + 1][getY()] == 'X') {
			consumed++;
		}
		setX(getX() + 1);
		arr[getX()][getY()] = shapeD;
		arr[getX() - 1][getY()] = '~';

	}
	}
	else if (randNum == 4) {
		if ((arr[getX() - 1][getY()] == '~' || arr[getX() - 1][getY()] == 'X') && (getX() - 1) > 0) {
			if (arr[getX() - 1][getY()] == 'X') {
			consumed++;
		}
		setX(getX() - 1);
		arr[getX()][getY()] = shapeD;
		arr[getX() + 1][getY()] = '~';

	}
	}
}


void DoodleBug::breed(char arr[20][20], vector<DoodleBug> &doodleBugVec)
{
	//Survive for eight steps 
	//at end of step  spawn new doodlebug in open cell
	//no open cell, no breed
	
	if (turnCountD > 8) {

			if ((arr[getX()][getY() + 1] == '~' || arr[getX()][getY() + 1] == 'X') && (getY() + 1) < 20)
			{
				arr[getX()][getY()+1] = shapeD;
				DoodleBug doodle;
				doodle.setX(getX());
				doodle.setY(getY() + 1);
				doodleBugVec.push_back(doodle);
				turnCountD = 0;
				arrSizeD++;
			}
			else if ((arr[getX()][getY() - 1] == '~' || arr[getX()][getY() - 1] == 'X') && (getY() - 1) > 0)
			{
				arr[getX()][getY()-1] = shapeD;	
				DoodleBug doodle;
				doodle.setX(getX());
				doodle.setY(getY() - 1);
				doodleBugVec.push_back(doodle);
				turnCountD = 0;
				arrSizeD++;
			}
			else if ((arr[getX() + 1][getY()] == '~' || arr[getX() + 1][getY()] == 'X') && (getX() + 1) < 20)
			{
				arr[getX() + 1][getY()] = shapeD;
				DoodleBug doodle;
				doodle.setX(getX() + 1);
				doodle.setY(getY());
				doodleBugVec.push_back(doodle);
				turnCountD = 0;
				arrSizeD++;
				
			}
			else if ((arr[getX() - 1][getY()] == '~' || arr[getX() - 1][getY()] == 'X') && (getX() - 1) > 0)
			{
				arr[getX() - 1][getY()] = shapeD;
				DoodleBug doodle;
				doodle.setX(getX() - 1);
				doodle.setY(getY());
				doodleBugVec.push_back(doodle);
				turnCountD = 0;
				arrSizeD++;
			}
			
			turnCountD = 0;
		}//turn count if statement
}

void DoodleBug::starve(char arr[20][20], vector<DoodleBug> &doodleBugVec, int j)
{
	//If a doodlebug doesnt hit an ant in three turns
	//at end of third step the doodlebug dies
	//I.E. remove from grid

	if ((consumed < 1) && (turnCountD > 3)) {
		arr[getX()][getY()] = '~';
		swap(doodleBugVec[j], doodleBugVec[doodleBugVec.size() - 1]);
		doodleBugVec.pop_back();
		consumed = 0;
	}

}

int DoodleBug::getTurnDoodle() 
{
	return turnCountD;
}

void DoodleBug::setTurnDoodle(int &turn)
{
	turnCountD = turn;
}

int DoodleBug::getArraySizeD()
{
	return arrSizeD;
}

void DoodleBug::setArraySizeD(int &size)
{
	arrSizeD = size;
}