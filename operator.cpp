#include <iostream>
#include <cmath>
using namespace std;

class point
{
	public:
		point(int xx = 0, int yy = 0) { x = xx, y =yy; }

		point operator + (point p);

		point operator - (point p);

		point operator ++ (int);

		point& operator ++ ();

		friend double distance(point &p1, point &p2);
		friend ostream& operator << (ostream& out, point &p);

		void display();
	private:
		int x, y;
};

double distance(point &p1, point &p2) {
	double x = (double) (p1.x - p2.x);
	double y = (double) (p1.y - p2.y);
	return (double) sqrt(x*x + y*y);
}

ostream& operator << (ostream& out, point &p) {
	out << "x := " << p.x << " y := " << p.y;
	return out;
}

point point::operator + (point p) {
	return point(x + p.x, y + p.y);
}

point point::operator - (point p) {
	return point(x - p.x, y - p.y);
}

point& point::operator ++ () {
	x++;
	y++;
	return *this;
}

point point::operator ++ (int) {
	point p = *this;
	++(*this);
	return p;
}

void point::display() {
	cout << "x: " << x << " y: " << y << endl;
}

int main() {
	point p1(1, 2), p2(2, 3), p3;

	cout << "p1 = "; p1.display();

	cout << "p2 = "; p2.display();

	p3 = p1 - p2;
	cout << "p3 = p1 - p2 = "; p3.display();

	p3 = p1 + p2;
	cout << "p3 = p1 + p2 = "; p3.display();

	cout << "p3 = "; p3.display();

	cout << "p3++ = "; (p3++).display();

	cout << "++p3 = "; (++p3).display();

	cout << p3 << endl;
//	cout << "p1 distance p2 is : " << distance(p1, p2) << endl;
	return 0;
}
/*
class complex
{
	public:
		complex(double r = 0.0, double i = 0.0) { real = r; imag = i; }

		complex operator + (complex c);

		complex operator - (complex c);

		void display();
		
	private:
		double real, imag;
};

complex complex::operator + (complex c) {
	return complex(real + c.real, imag + c.imag);
}

complex complex::operator - (complex c) {
	return complex(real - c.real, imag - c.imag);
}

void complex::display() {
	cout << "(" << real << "," << imag << ")" << endl;
}

int main() {
	complex c1(5, 4), c2(2, 10), c3;
	cout << "c1 = "; c1.display();
	cout << "c2 = "; c2.display();

	c3 = c1 - c2;
	cout << "c3 = c1 - c2 = "; c3.display();

	c3 = c1 + c2;
	cout << "c3 = c1 + c2 = "; c3.display();

	c3.display();
	return 0;
}*/
