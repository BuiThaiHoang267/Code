#include<iostream>
#include<cmath>
using namespace std;

class Diem {
private:
	float x;
	float y;
public:
	friend istream& operator >> (istream& in, Diem& a);
	friend ostream& operator << (ostream& out, Diem a);
	float getx() {
		return x;
	}
	float gety() {
		return y;
	}
	void TinhTien(float k, float d);
};

istream& operator >> (istream& in, Diem& a) {
	in >> a.x;
	in >> a.y;
	return in;
}
ostream& operator << (ostream& out, Diem a) {
	out << "(" << a.x << "," << a.y << ")";
	return out;
}

void Diem::TinhTien(float k, float d) {
	x = (float)x + d * cos(k / 180 * 3.14159);
	y = (float)y + d * sin(k / 180 * 3.14159);
}

int main() {
	Diem a;
	cin >> a;
	float k, d;
	cin >> k >> d;
	cout << a.getx();
	cout << a.gety();
	a.TinhTien(k, d);
	cout << a;
	return 0;
}