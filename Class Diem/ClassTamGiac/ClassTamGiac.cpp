#include<iostream>
#include<cmath>
using namespace std;

class Diem {
private:
	float x;
	float y;
public:
	void Nhap();
	void Xuat();
	void TinhTien(float k, float d) {
		x = x + cos(k / 180 * 3.14) * d;
		y = y + sin(k / 180 * 3.14) * d;
	}
};

void Diem::Nhap() {
	cin >> x;
	cin >> y;
}
void Diem::Xuat() {
	cout << "(" << x << "," << y << ")" << endl;
}

class TamGiac {
private:
	Diem a, b, c;
public:
	void NhapDiem();
	void XuatDiem();
	void TinhTienDiem(float k,float d) {
		a.TinhTien(k, d);
		b.TinhTien(k, d);
		c.TinhTien(k, d);
	}
};
void TamGiac::NhapDiem() {
	a.Nhap();
	b.Nhap();
	c.Nhap();
}
void TamGiac::XuatDiem() {
	a.Xuat();
	b.Xuat();
	c.Xuat();
}

int main() {
	TamGiac A;
	A.NhapDiem();
	int k, d;
	cin >> k >> d;
	A.TinhTienDiem(k,d);
	A.XuatDiem();
	return 0;
}