#ifndef SPIELER_H_
#define SPIELER_H_
#include "Position.h"

class Spieler
{
public:
	Spieler(int x, int y);
	~Spieler();
    Position getPos();
	void setPos(int x, int y);
	void setPos(Position p);



private:
	
	Position m_pos;


};

#endif /* SPIELER_H_ */
