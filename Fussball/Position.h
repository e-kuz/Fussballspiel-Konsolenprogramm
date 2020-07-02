#ifndef POSITION_H_
#define POSITION_H_
class Position
{
public:
	Position(int x, int y);
	Position(int minX, int maxX, int minY, int maxY);
	~Position();
	int getMinX();
	int getMaxX();
	int getMinY();
	int getMaxY();
	void setX(int x);
	void setY(int y);
	bool operator==(Position pos);



private:
	int m_minX;
	int m_maxX;
	int m_minY;
	int m_maxY;
};

#endif /* POSITION_H_ */
