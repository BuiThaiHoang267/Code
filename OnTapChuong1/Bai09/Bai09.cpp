#include<iostream>
#include<cmath>
using namespace std;

struct Diem {
	float x;
	float y;
};
typedef struct Diem DIEM;
struct DuongTron {
	float R;
	Diem I;
};
typedef struct DuongTron DUONGTRON;

void Nhap(DUONGTRON&);
void Nhap(DIEM&);
void Xuat(DUONGTRON);
void Xuat(DIEM);
float ChuVi(DUONGTRON);
float DienTich(DUONGTRON);

int main() {
	DuongTron K;
	Nhap(K);
	Xuat(K);
	cout << "\nChu vi duong tron C = " << ChuVi(K);
	cout << "\nDien tich duong tron C = " << DienTich(K);
	return 0;
}
void Nhap(DUONGTRON& i) {
	cout << "Nhap toa do I" << endl;
	Nhap(i.I);
	cout << "Nhap ban kinh R = ";
	cin >> i.R;
}
void Nhap(DIEM& a) {
	cout << "Nhap x: ";
	cin >> a.x;
	cout << "Nhap y: ";
	cin >> a.y;
}
void Xuat(DIEM a) {
	cout << "(" << a.x << "," << a.y << ")";
	cout << endl;
}
void Xuat(DUONGTRON i) {
	cout << "Duong tron tam I";
	Xuat(i.I);
	cout << "\nBan kinh R = " << i.R;
}
float ChuVi(DUONGTRON i) {
	return 3.14159 * i.R * 2;
}
float DienTich(DUONGTRON i) {
	return i.R * i.R * 3.14159;
}
