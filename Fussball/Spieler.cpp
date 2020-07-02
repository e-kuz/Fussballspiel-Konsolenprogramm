#include "Spieler.h"


Spieler::Spieler(int x, int y) : m_pos(x, y)
{	
	this->setPos(m_pos);
}

Position Spieler::getPos() {
	return m_pos;
}

void Spieler::setPos(int x, int y) {
	m_pos.setX(x);
	m_pos.setY(y);
}

void Spieler::setPos(Position pos) {
	m_pos.setX(pos.getMinX());
	m_pos.setY(pos.getMinY());
}

Spieler::~Spieler()
{
}
