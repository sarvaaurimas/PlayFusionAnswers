#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;


class Point2D
{
public:
	int x;
	int y;
	Point2D(int xCoord, int yCoord)
	{
		x = xCoord;
		y = yCoord;
	}
	float distance(Point2D point) //Calculates the distance between two points using Pythagoras theorem
	{
		return pow(pow((point.x - x), 2) + pow((point.y - y), 2), 0.5);
	}
	bool operator < (const Point2D &pt2) const
	{
		return (pow((pow(x, 2) + pow(y, 2)), 0.5) < pow(pow((pt2.x), 2) + pow((pt2.y), 2), 0.5)); 
		//overload < operator to define Point2D object sorting by their distance from the origin
	}
};

void distanceSort(vector <Point2D> &n)
//given a vector of 2D points sorts it by distance from the center
{
	sort(n.begin(), n.end());
}

int twiceSignedArea(Point2D a, Point2D b, Point2D c)
//returns the twice signed area given three Point2D objects
{
	return (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x);
}

bool isAntiClockwise(Point2D a, Point2D b, Point2D c)
//returns true if three points form anticlockwise turn
{
	if (twiceSignedArea(a, b, c) > 0)
	{
		return true;
	}
	return false;
}

bool isCollinear(Point2D a, Point2D b, Point2D c)
//returns true if three points are collinear
{
	if (twiceSignedArea(a, b, c) == 0)
	{
		return true;
	}
	return false;
}

int orientation(Point2D a1, Point2D b1, Point2D a2)
//Returns 0 if the three points are collinear, 1 if a1b1a2 form a clockwise turn and 2 if anticlockwise
{
	int area = twiceSignedArea(a1, b1, a2);
	if (area == 0) { return 0; }
	if (area < 0) { return 1; }
	return 2;

}

bool onLine(Point2D a1, Point2D b1, Point2D a2)
//given three collinear points returns true if a2 lies in the segment a1b1
{
	if (a2.x <= max(a1.x, b1.x) && a2.x >= min(a1.x, b1.x) && //Checks that a2 x and y coordinates lie between a1 and b1 x and y coordinates respectively
		a2.y <= max(a1.y, b1.y) && a2.y >= min(a1.y, b1.y))
	{
		return true;
	}
	return false;
}
bool doIntersect(Point2D a1, Point2D b1, Point2D a2, Point2D b2)
//returns true if two line segments formed by a1b1 and a2b2 intersect
{
	//get orientations of each needed three point combinations
	int orient1 = orientation(a1, b1, a2);
	int orient2 = orientation(a1, b1, b2);
	int orient3 = orientation(a2, b2, a1);
	int orient4 = orientation(a2, b2, b1);

	//general case
	if (orient1 != orient2 && orient3 != orient4)
	{
		return true;
	}

	//specific case when the line segments are collinear and overlapping
	if (orient1 == 0 && onLine(a1, b1, a2)) { return true; }
	if (orient2 == 0 && onLine(a1, b1, b2)) { return true; }
	if (orient3 == 0 && onLine(a2, b2, a1)) { return true; }
	if (orient4 == 0 && onLine(a2, b2, b1)) { return true; }

	return false;
}

bool isInside(vector <Point2D> &polygon, Point2D p)
//Function returns true if the point p is inside the polygon that is specified in a vector of Point2D objects
{
	//polygon must have at least 2 points
	if (polygon.size() < 3) { return false; }

	/*
	Create a point q for a big line segment from p parallel to the x axis - not too big as then it might overflow the function computing twice signed area.
	As the biggest int is between 10^9-10^10 we can perform calculations on polygons with point coordinates ranging up to 10^3 and when approaching 10^4 it starts to overflowing
	*/
	Point2D q(pow(10, 6), p.y);

	int count = 0;
	for (int i = 0; i < polygon.size(); i++)
	{
		if (doIntersect(polygon.at(i), polygon.at((i + 1) % polygon.size()), p, q)) //check each polygon line if it intersects with our infinite line
		{
			if (orientation(polygon.at(i), polygon.at((i + 1) % polygon.size()), p) == 0) // if the lines intersect and are collinear return true if the point p is on that polygon line
			{
				return onLine(polygon.at(i), polygon.at((i + 1) % polygon.size()), p);
			}
			count++;
		}
	}
	return count % 2; //return true if count is odd as then point p is in the polygon

}

int main()
{

}