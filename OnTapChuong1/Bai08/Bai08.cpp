#include<iostream>
#include<cmath>
using namespace std;

struct Diem {
	float x;
	float y;
};
typedef struct Diem DIEM;
struct TamGiac {
	DIEM A;
	DIEM B;
	DIEM C;
};
typedef struct TamGiac TAMGIAC;

void Nhap(TAMGIAC&);
void Nhap(DIEM&);
void Xuat(TAMGIAC);
void Xuat(DIEM);
float KhoangCach(DIEM, DIEM);
float Sabc(TAMGIAC);
float Cabc(TAMGIAC);
DIEM TrongTam(TAMGIAC);

int main() {
	TAMGIAC ABC;
	Nhap(ABC);
	cout << "Chu vi cua tam gian = " << Cabc(ABC) << endl;
	cout << "Dien tich cua tam giac = " << Sabc(ABC) << endl;
	cout << "Trong tam tam giac ABC la: ";
	Xuat(TrongTam(ABC));
	return 0;
}
void Nhap(TAMGIAC& abc) {
	Nhap(abc.A);
	Nhap(abc.B);
	Nhap(abc.C);
}
void Nhap(DIEM& a) {
	cout << "Nhap x: ";
	cin >> a.x;
	cout << "Nhap y: ";
	cin >> a.y;
}
void Xuat(TAMGIAC abc) {
	Xuat(abc.A);
	Xuat(abc.B);
	Xuat(abc.C);
}
void Xuat(DIEM a) {
	cout << "(" << a.x << "," << a.y << ")";
	cout << endl;
}
float KhoangCach(DIEM a, DIEM b) {
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}
float Cabc(TAMGIAC a) {
	return KhoangCach(a.A, a.B) + KhoangCach(a.A, a.C) + KhoangCach(a.B, a.C);
}
float Sabc(TAMGIAC a) {
	float C =(float) Cabc(a)/2;
	return sqrt(C * (C - KhoangCach(a.A, a.B)) * (C - KhoangCach(a.A, a.C)) * (C - KhoangCach(a.B, a.C)));
}
DIEM TrongTam(TAMGIAC a) {
	DIEM temp;
	temp.x = (float)(a.A.x + a.B.x + a.C.x) / 3;
	temp.y = (float)(a.A.y + a.B.y + a.C.y) / 3;
	return temp;
}