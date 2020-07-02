#include "Spielfeld.h"
#include <iostream>



Spielfeld::Spielfeld(int width, int height, Tor gate, Spieler player, Ball ball) : m_width(width), m_height(height), m_gate(gate), m_player(player), m_ball(ball)
{
	
}



void Spielfeld::drawAll() {
	for (int i = 0; i < m_height; i++) {
		for (int j = 0; j < m_width; j++) {
			//draw gate
			if (i >= m_gate.getPos().getMinY() && i <= m_gate.getPos().getMaxY() 
				&& j >= m_gate.getPos().getMinX() && j <= m_gate.getPos().getMaxX()) {
				std::cout << "# ";
			}

			//draw player
			 else if (i == m_player.getPos().getMinY() && j == m_player.getPos().getMinX()) {
				std::cout << "@ ";
			}

			//draw ball
			else if (i == m_ball.getPos().getMinY() && j == m_ball.getPos().getMinX()) {
				std::cout << "o ";
			}


			else {
				std::cout << "_ ";
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Spielfeld::setPlayer(Spieler player) {

	m_player.setPos(player.getPos());
}

void Spielfeld::setBall(Ball ball) {

	m_ball.setPos(ball.getPos());
}




Spielfeld::~Spielfeld()
{
}
