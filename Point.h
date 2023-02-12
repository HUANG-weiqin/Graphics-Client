#pragma once
#include <string>
#include <sstream>
using namespace std;
class Point
{
private:
	int x = 0;
	int y = 0;
public:
	Point(int xx, int yy) {
		x = xx;
		y = yy;
	};
	int getX() { return x; };
	int getY() { return y; };
	int setX(int newx) { x = newx; };
	int setY(int newy) { y = newy; };
	string toString() 
	{
		stringstream ss;
		ss << x <<" "<< y;
		return ss.str();
	};

};