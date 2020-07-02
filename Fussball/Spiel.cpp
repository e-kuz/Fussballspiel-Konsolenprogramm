#include "Spiel.h"
#include "Spielfeld.h"
#include "Spieler.h"
#include "Ball.h"
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <algorithm> 



Spiel::Spiel()
{
}

void main() {

	int steps = 0 ;
	int shots = 0;


	srand(time(NULL));
	int fieldwidth = rand() % 10 +5;
	int fieldheight = rand() % 5 + 5;
	
	//Torbreite
	int gatewidth = rand() % std::min(fieldwidth,fieldheight) + 1;
	//welcherRand des Speilfelds
	int border = rand() % 4;
	int gate_minX, gate_maxX, gate_minY, gate_maxY = 0;
	switch (border) {
	case 0:
		//oben
		gate_minY = gate_maxY = 0;
		gate_minX = rand() % (fieldwidth - gatewidth);
		gate_maxX = gate_minX + gatewidth - 1;
		break;
	case 1:
		//links
		gate_minX = gate_maxX = 0;
		gate_minY = rand() % (fieldheight - gatewidth);
		gate_maxY = gate_minY + gatewidth - 1;
		break;
	case 2:
		//unten
		gate_minY = gate_maxY = fieldheight-1;
		gate_minX = rand() % (fieldwidth - gatewidth);
		gate_maxX = gate_minX + gatewidth - 1;
		break;
	case 3:
		//rechts
		gate_minX = gate_maxX = fieldwidth-1;
		gate_minY = rand() % (fieldheight - gatewidth);
		gate_maxY = gate_minY + gatewidth - 1;
		break;
	default:
		gate_minX, gate_maxX, gate_minY, gate_maxY = 0;
		break;
	}

	Tor gate(gatewidth, gate_minX, gate_maxX, gate_minY, gate_maxY);


	Spieler player(rand() % fieldwidth, rand() % fieldheight);

	Ball ball(rand() % fieldwidth, rand() % fieldheight);

	Spielfeld field(fieldwidth, fieldheight,gate,player,ball);

	std::cout << "Breite: " << fieldwidth << " , Hoehe: " << fieldheight <<  std::endl ;
	std::cout << "Spieler: " << player.getPos().getMinX() << " , " << player.getPos().getMinY() << std::endl;
	std::cout << "Ball: " << ball.getPos().getMinX() << " , " << ball.getPos().getMinY() << std::endl;
	std::cout << "Torbreite: " << gatewidth << "Rand: " << border << "Position: " << gate_minX << " " << gate_maxX <<
	" " << gate_minY << " " << gate_maxY << std::endl << std::endl;

	field.drawAll();

	//Spieler laueft zur Ball-x-Koordinate
	while (player.getPos().getMinX() != ball.getPos().getMinX()) {
		if (ball.getPos().getMinX() > player.getPos().getMinX()) {
			player.setPos(player.getPos().getMinX() + 1, player.getPos().getMinY());
			steps++;
			std::cout <<"Bewege mich nach rechts" << std::endl;
		}
		else {
			player.setPos(player.getPos().getMinX() - 1, player.getPos().getMinY());
			steps++;
			std::cout << "Bewege mich nach links" << std::endl;

		}
		field.setPlayer(player);
		field.drawAll();
	}

	//Spieler laueft zur Ball-y-Koordinate
	while (player.getPos().getMinY() != ball.getPos().getMinY()) {
		if (ball.getPos().getMinY() > player.getPos().getMinY()) {
			player.setPos(player.getPos().getMinX() , player.getPos().getMinY() + 1);
			steps++;
			std::cout << "Bewege mich nach unten" << std::endl;
		}
		else {
			player.setPos(player.getPos().getMinX() , player.getPos().getMinY() - 1);
			steps++;
			std::cout << "Bewege mich nach oben" << std::endl;

		}
		field.setPlayer(player);
		field.drawAll();
	}

	//Spieler ist am Ball, er schiesst ihn zur Tor x-Koordinate
	while (!(ball.getPos().getMinX() >= gate.getPos().getMinX() && ball.getPos().getMinX() <= gate.getPos().getMaxX())) {
		if (ball.getPos().getMinX() < gate.getPos().getMinX()) {
			ball.setPos(ball.getPos().getMinX() + 1, ball.getPos().getMinY());
			field.setBall(ball);
			field.drawAll();
			player.setPos(player.getPos().getMinX() + 1, player.getPos().getMinY());
			field.setPlayer(player);
			field.drawAll();
			steps++;
			shots++;
			std::cout << "Kicke nach rechts" << std::endl;
		}
		else {
			ball.setPos(ball.getPos().getMinX() - 1, ball.getPos().getMinY());
			field.setBall(ball);
			field.drawAll();
			player.setPos(player.getPos().getMinX() - 1, player.getPos().getMinY());
			field.setPlayer(player);
			field.drawAll();
			steps++;
			shots++;
			std::cout << "Kicke nach links" << std::endl;

		}
	}

	//Spieler ist am Ball, er schiesst ihn zur Tor y-Koordinate
	while (!(ball.getPos().getMinY() >= gate.getPos().getMinY() && ball.getPos().getMinY() <= gate.getPos().getMaxY())) {
		if (ball.getPos().getMinY() < gate.getPos().getMinY()) {
			ball.setPos(ball.getPos().getMinX() , ball.getPos().getMinY() + 1);
			field.setBall(ball);
			field.drawAll();
			player.setPos(player.getPos().getMinX() , player.getPos().getMinY() + 1);
			field.setPlayer(player);
			field.drawAll();
			steps++;
			shots++;
			std::cout << "Kicke nach unten" << std::endl;
		}
		else {
			ball.setPos(ball.getPos().getMinX(), ball.getPos().getMinY() - 1);
			field.setBall(ball);
			field.drawAll();
			player.setPos(player.getPos().getMinX() , player.getPos().getMinY() - 1);
			field.setPlayer(player);
			field.drawAll();
			steps++;
			shots++;
			std::cout << "Kicke nach oben" << std::endl;

		}
	}

	std::cout << steps - 1 << " Schritte, " << shots << " Schuesse" << std::endl;





}


	


Spiel::~Spiel()
{
}
