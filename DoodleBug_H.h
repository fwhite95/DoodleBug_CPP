//File name: DoodleBug_H
#include "Organism_H.h"
#include <vector>
#ifndef DoodleBug_H
#define DoodleBug_H

class DoodleBug : public Organism {
private:
	int turnCountD = 0;
	int consumed = 0;
	int arrSizeD = 4;

public: 
	virtual void move(char arr[20][20], std::vector<DoodleBug> &doodleBugVec);
	void breed(char arr[20][20], std::vector<DoodleBug> &doodleBugVec);
	void starve(char arr[20][20], std::vector<DoodleBug> &doodleBugVec, int j);
	char shapeD = 'O';

	void setTurnDoodle(int &turn);
	int getTurnDoodle();

	int getArraySizeD();
	void setArraySizeD(int &size);
};

#endif // !DoodleBug_H
