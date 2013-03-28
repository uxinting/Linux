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
		friend float distance(Point &a, Point &b);
	private:
		int x, y;
};

float distance(Point &a, Point &b) {
//	float x = float (a.x - b.x);
//	float y = float (a.y - b.y);
//	return (float) sqrt(x*x + y*y);
	cout << "in distance " << endl;
	return 0.0;
}

int main() {
	Point myp1(2, 2), myp2(3, 3);
	distance(myp1, myp2);
	return 0;
}
