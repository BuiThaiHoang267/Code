#include<iostream>
#include<cmath>
using namespace std;

class Diem {
private:
	float x;
	float y;
public:
	friend istream& operator >> (istream& in, Diem& a) {
		in >> a.x;
		in >> a.y;
		return in;
	}
	friend ostream& operator << (ostream& out, Diem a) {
		out << "(" << a.x << "," << a.y << ")";
		return out;
	}
	void TinhTien(float, float);
};
void Diem::TinhTien(float k, float d) {
	x = (float)x + d * cos(k / 180 * 3.14159);
	y = (float)y + d * sin(k / 180 * 3.14159);
}
class TamGiac {
public:
	Diem a, b, c;
	friend istream& operator >> (istream& in, TamGiac& A) {
		in >> A.a;
		in >> A.b;
		in >> A.c;
		return in;
	}
	friend ostream& operator << (ostream& out, TamGiac A) {
		out << A.a << endl;
		out << A.b << endl;
		out << A.c;
		return out;
	}
	void TinhTienTG(float k,float d) {
		a.TinhTien(k, d);
		b.TinhTien(k, d);
		c.TinhTien(k, d);
	}

};

int main() {
	TamGiac A;
	cin >> A;
	float k, d;
	cin >> k >> d;
	A.TinhTienTG(k, d);
	cout << A;
	return 0;
}