#include "Position.h"

//Constructor fuer Ball und Spieler
Position::Position(int x, int y) : m_minX(x), m_maxX(x), m_minY(y), m_maxY(y)
{
}

//Constructor fuer Tor
Position::Position(int minX, int maxX, int minY, int maxY) : m_minX(minX), m_maxX(maxX), m_minY(minY), m_maxY(maxY)
{
}

int Position::getMinX() {
	return m_minX;
}
int Position::getMinY() {
	return m_minY;
}

int Position::getMaxX() {
	return m_maxX;
}
int Position::getMaxY() {
	return m_maxY;
}

void Position::setX(int x) {
	m_minX = x;
}
void Position::setY(int y) {
	m_minY = y;
}

bool Position::operator==(Position pos) {
	return m_minX >= pos.getMinX() && m_minY >= pos.getMinY() && m_maxX <= pos.getMaxX() && m_maxY <= pos.getMaxY();
}

Position::~Position()
{
}
