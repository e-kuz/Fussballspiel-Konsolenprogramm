#include "Ball.h"


Ball::Ball(int x, int y) : m_pos(x, y)
{
	this->setPos(m_pos);
}

Position Ball::getPos() {
	return m_pos;
}

void Ball::setPos(int x, int y) {
	m_pos.setX(x);
	m_pos.setY(y);
}

void Ball::setPos(Position pos) {
	m_pos.setX(pos.getMinX());
	m_pos.setY(pos.getMinY());
}


Ball::~Ball()
{
}
