#include <iostream>
//#include <ctime>
#include <random>
#include "Ant_H.h"
#include "time.h"
#include <vector>
using namespace std;

Ant::Ant()
{
	
}

void Ant::move(char arr[20][20], vector<Ant> &antVec)
{
	//For every step the ants try to move randomly left, right, up or down
	//If the cell is occupied, or the ant is off the grind, the ant stays
	
	int randMove = 0;
	randMove = 1 + rand() % 4;
	turnCountA++;

		if (randMove == 1) //down
		{
			if (arr[getX()][getY() + 1] == '~' && (getY()+1) < 20) {
				setY(getY() + 1);
				arr[getX()][getY()] = shapeA;
				arr[getX()][getY() - 1] = '~';
				
			}
		}
		else if (randMove == 2)//up
		{
			if (arr[getX()][getY() - 1] == '~' && (getY() - 1) > 0) {
				setY(getY() - 1);
				arr[getX()][getY()] = shapeA;
				arr[getX()][getY() + 1] = '~';
				
			}
		}
		else if (randMove == 3)//left
		{
			if (arr[getX() + 1][getY()] == '~' && (getX() + 1) < 20) {
				setX(getX() + 1);
				arr[getX()][getY()] = shapeA;
				arr[getX() - 1][getY()] = '~';
				
			}
		}
		else if (randMove == 4)//right
		{
			if (arr[getX() - 1][getY()] == '~' && (getX() - 1) > 0) {
				setX(getX() - 1);
				arr[getX()][getY()] = shapeA;
				arr[getX() + 1][getY()] = '~';
				
			}
		}

}

void Ant::breed(char arr[20][20], vector<Ant> &antVec)
{
	//If ant survives three steps, at the end of the step a new ant is created
	//in an empty cell. If no empty cell, no new ant
	//Resets counter, can't breed for three more turns

	if (turnCountA > 3) {

		if (arr[getX()][getY() + 1] == '~' && (getY() + 1) < 20)
		{
			arr[getX()][getY() + 1] = shapeA;
			Ant ant;
			ant.setX(getX());
			ant.setY(getY() + 1);
			antVec.push_back(ant);
			turnCountA = 0;
			arrSizeA++;
		}
		else if (arr[getX()][getY() - 1] == '~' && (getY() - 1) > 0)
		{
			arr[getX()][getY() - 1] = shapeA;
			Ant ant;
			ant.setX(getX());
			ant.setY(getY() - 1);
			antVec.push_back(ant);
			turnCountA = 0;
			arrSizeA++;
		}
		else if (arr[getX() + 1][getY()] == '~' && (getX() + 1) < 20)
		{
			arr[getX() + 1][getY()] = shapeA;
			Ant ant;
			ant.setX(getX() + 1);
			ant.setY(getY());
			antVec.push_back(ant);
			turnCountA = 0;
			arrSizeA++;

		}
		else if (arr[getX() - 1][getY()] == '~' && (getX() - 1) > 0)
		{
			arr[getX() - 1][getY()] = shapeA;
			Ant ant;
			ant.setX(getX() - 1);
			ant.setY(getY());
			antVec.push_back(ant);
			turnCountA = 0;
			arrSizeA++;
		}

		turnCountA = 0;
	}//turn count if statement

}

void Ant::setTurnAnt(int &turn) {
	turnCountA = turn;
}

int Ant::getTurnAnt() {
	return turnCountA;
}

int Ant::getArraySizeA()
{
	return arrSizeA;
}

void Ant::setArraySizeA(int &size)
{
	arrSizeA = size;
}