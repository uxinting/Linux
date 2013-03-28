#include <iostream>
#include <cmath>
using namespace std;

class Point {
	public:
		Point(int xx = 0, int yy = 0);
		Point (Point &p);

		int GetX() { return x; }
		int GetY() { return y; }
		void SetX(int xx) { x = xx; }
//		friend float distance(Point &a, Point &b);
		Point operator + (Point p);
	private:
		int x, y;
};

Point Point::operator + (Point p) {
	return Point(x + p.x, y + p.y);
}
/*
float distance(Point &a, Point &b) {
//	float x = float (a.x - b.x);
//	float y = float (a.y - b.y);
//	return (float) sqrt(x*x + y*y);
	cout << "in distance " << endl;
	return 0.0;
}*/

Point::Point(int xx, int yy) {
	x = xx;
	y = yy;
	cout << "point counstructor" << endl;
}

Point::Point(Point &p) {
	x = p.x;
	y = p.y;
	cout << "Point copy constructor" << endl;
}

class Line {
	public:
		Line (Point xp1, Point xp2);
		Line (Line &);
		double GetLen() {
			return len; }
	private:
		Point p1, p2;
		double len;
};

Line::Line(Point xp1, Point xp2)
	:p1(xp1), p2(xp2) {
		cout << "Line constructor" << endl;
		double x = double (xp1.GetX() - xp2.GetX());
		double y = double (xp1.GetY() - xp2.GetY());
		len = sqrt(x*x + y*y);
	}

Line::Line(Line &L)
:p1(L.p1), p2(L.p2){
	len = L.len;
	cout << "Line copy constructor" << endl;
}

void Add(Point &p, Point *ap) {
	*ap = p;
}

Point* GetP() {
	Point *p = new Point(9, 3);
	return p;
}

int main() {
	Point myp1(1, 1), myp2(4, 5), myp3;
	myp3 = myp1 + myp2;
	cout << "add one" << myp3.GetX() << endl;
//	distance(myp1, myp2);
//	cout << "this distance is : " << distance(myp1, myp2) << endl;
//	Line line(myp1, myp2);
/*	Point &myp11 = myp1;
	cout << "myp1="<< myp1.GetX() << endl;
	Point ap[2];
	cout << "points array" << endl;
	Add(myp1, ap);
	ap[0].SetX(2);
	cout << "myp1=" << myp1.GetX() << endl;
	cout << "ap[0]=" << ap[0].GetX() << endl;
	myp11.SetX(3);
	cout << "myp1=" << myp1.GetX() << endl;
	cout << "myp11=" << myp11.GetX() << endl;
	cout << endl << GetP()->GetX() << endl;
	cout << "this distance is : " << distance(myp1, myp2) << endl;
	Line line2(line);
	cout << "The Length of the line is : ";
	cout << line.GetLen() << endl;
	cout << "The length of the line2 is : ";
	cout << line2.GetLen() << endl;
	*/
}
