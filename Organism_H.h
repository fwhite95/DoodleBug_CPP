//File name: Organism_H
//#ifndef Organism_H
//#define Organsim_H
#pragma once

class Organism {

public:
	Organism();
	Organism(int X, int Y);
	virtual void move();
	int getX();
	int getY();
	void setX(int X);
	void setY(int Y);

private:
	int locationX = NULL;
	int locationY = NULL;
};

//#endif // !Organism_H
