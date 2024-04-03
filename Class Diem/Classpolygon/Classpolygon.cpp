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
	float Nhanx(Diem e) {
		float t;
		t = x * e.y;
		return t;
	}
	float Nhany(Diem e) {
		float t;
		t = y * e.x;
		return t;
	}
};

void Diem::Nhap() {
	cin >> x;
	cin >> y;
}
void Diem::Xuat() {
	cout << "(" << x << "," << y << ")" << endl;
}

class Polygon {
private:
	int n;
	Diem* a;
public:
	Polygon(int m) {
		n = m;
		a = new Diem[n+1];
	}
	void NhapDiem();
	void XuatDiem();
	float Area() {
		float sumx = 0;
		float sumy = 0;
		a[n] = a[0];
		for (int i = 0; i < n; i++) {
			sumx = sumx + a[i].Nhanx(a[i + 1]);
			sumy = sumy + a[i].Nhany(a[i + 1]);
		}
		return abs((sumx - sumy) / 2);
	}
};
void Polygon::NhapDiem() {
	for (int i = 0; i < n; i++)
		a[i].Nhap();
}
void Polygon::XuatDiem() {
	for (int i = 0; i < n; i++) {
		a[i].Xuat();
	}
}


int main() {
	int n;
	cin >> n;
	Polygon A=Polygon(n);
	A.NhapDiem();
	cout << A.Area();
	return 0;
}