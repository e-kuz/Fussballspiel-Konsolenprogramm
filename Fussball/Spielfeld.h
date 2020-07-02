#ifndef SPIELFELD_H_
#define SPIELFELD_H_
#include "Tor.h"
#include "Spieler.h"
#include "Position.h"
#include "Ball.h"
class Spielfeld
{
public:
	Spielfeld(int width, int height, Tor gate, Spieler player, Ball ball);
	~Spielfeld();
	const int getWidth();
	const int getHeight();
	void setGate(int border, Tor gate);
	void setPlayer( Spieler player);
	void setBall(Ball ball);
	void drawAll();



private:
	int m_width;
	int m_height;
	Tor m_gate;
	Spieler m_player;
	Ball m_ball;
	void drawField();
	void drawPlayer();


};

#endif /* SPIELFELD_H_ */
