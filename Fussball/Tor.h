#pragma once
#include "Position.h"
class Tor
{
public:
	Tor(int width, int minX, int maxX, int minY, int maxY);
	
	~Tor();

	Position getPos();
	void setPos(int minX, int maxX, int minY, int maxY);
	void setPos(Position p);



private:

	Position m_pos;
	int m_width;
	
};

