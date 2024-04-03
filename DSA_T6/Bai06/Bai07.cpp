#include<iostream>
using namespace std;

struct Point {
	float x;
	float y;
};

void Nhap(Point&);
void Xuat(Point);
float KCMin(Point [], int, Point);
float KhoangCach(Point, Point);

int main() {
	Point p;
	int n;
	cout << "Nhap n: ";
	cin >> n;
	Point* q = new Point[n];
	cout << "Nhap p" << endl;
	Nhap(p);
	for (int i = 0; i < n; i++) {
		cout << "Nhap q[" << i << "]" << endl;
		Nhap(q[i]);
	}
	float kcmin = KCMin(q, n, p);
	for (int i = 0; i < n; i++) {
		if (KhoangCach(q[i], p) == kcmin)
			Xuat(q[i]);
	}
	delete[] q;
	return 0;
}

void Nhap(Point& a) {
	cout << "Nhap x: ";
	cin >> a.x;
	cout << "Nhap y: ";
	cin >> a.y;
}
void Xuat(Point a) {
	cout << "(" << a.x << "," << a.y << ")";
	cout << endl;
}
float KCMin(Point q[],int n ,Point p) {
	float kc=KhoangCach(q[0],p);
	for (int i = 1; i < n; i++)
	{
		if (kc > KhoangCach(q[i], p))
			kc = KhoangCach(q[i], p);
	}
	return kc;
}
float KhoangCach(Point q, Point p) {
	return sqrt(pow(q.x - p.x, 2) + pow(q.y - p.y, 2));
}