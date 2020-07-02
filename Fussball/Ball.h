#ifndef BALL_H_
#define BALL_H_
#include "Position.h"

class Ball
{
public:
	Ball(int x, int y);
	~Ball();
	Position getPos();
	void setPos(int x, int y);
	void setPos(Position p);



private:

	Position m_pos;
};

#endif /*BALL_H_*/

