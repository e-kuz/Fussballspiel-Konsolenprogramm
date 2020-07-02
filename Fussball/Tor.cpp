#include "Tor.h"


Tor::Tor(int width, int minX, int maxX, int minY, int maxY) : m_width(width), m_pos(minX, maxX, minY, maxY)
{
}

Position Tor::getPos() {
	return m_pos;
}



Tor::~Tor()
{
}
