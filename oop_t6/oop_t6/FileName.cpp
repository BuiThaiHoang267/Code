#include<iostream>
using namespace std;

class Point {
public:
	float x;
	float y;
	void Nhap();
	Point ChiThi1() {
		Point c;
		c.x = x * 2;
		c.y = y * 2;
		return c;
	}
	Point ChiThi2() {
		Point c;
		c.x = 0;
		c.y = 0;
		return c;
	}
	Point ChiThi3(int k, float d) {
		Point c;
		if (k == 0) {
			c.x = d + x;
			c.y = y;
		}
		else {
			c.x = x;
			c.y = d + y;
		}
		return c;
	}
	void Xuat();
};

void Point::Nhap() {
	cin >> x;
	cin >> y;
}
void Point::Xuat() {
	cout << "(" << x << "," << y << ")";
}

int main() {
	Point a;
	int n, t, k;
	float d;
	a.Nhap();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t;
		if (t == 1)
			a = a.ChiThi1();
		else if (t == 2)
			a = a.ChiThi2();
		else if (t == 3)
		{
			cin >> k >> d;
			a = a.ChiThi3(k, d);
		}
	}
	a.Xuat();
	return 0;
}