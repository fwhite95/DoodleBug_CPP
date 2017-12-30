//File name: Ant_H
#include "Organism_H.h"
#include <vector>
#ifndef Ant_H
#define Ant_H

class Ant : public Organism {
public:
	Ant();
	virtual void move(char arr[20][20], std::vector<Ant> &antVec);
	void breed(char arr[20][20], std::vector<Ant> &antVec);
	char shapeA = 'X';
	
	void setTurnAnt(int &turn);
	int getTurnAnt();

	int getArraySizeA();
	void setArraySizeA(int &size);

private:
	int turnCountA = 0;
	int arrSizeA = 99;
};

#endif // !Ant_H

