#include <iostream>
#include "Organism_H.h"
using namespace std;

Organism::Organism()
{

}

Organism::Organism(int X, int Y)
{
	locationX = X;
	locationY = Y;
}

void Organism::move()
{

}

int Organism::getX()
{
	return locationX;
}

int Organism::getY()
{
	return locationY;
}

void Organism::setX(int X)
{
	locationX = X;
}
void Organism::setY(int Y)
{
	locationY = Y;
}


