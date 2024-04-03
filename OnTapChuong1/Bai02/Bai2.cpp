#include<iostream>
#include<cmath>
using namespace std;

struct Point {
	float x;
	float y;
	float z;
};
typedef struct Point POINT;

void Nhap(POINT&);
float TinhKhoangCach(POINT,POINT);

int main() {
	POINT A, B;
	Nhap(A);
	Nhap(B);
	cout << "Khoang cach giua 2 diem la: ";
	cout << TinhKhoangCach(A, B);
	return 0;
}

void Nhap(POINT& a) {
	cout << "Nhap x: ";
	cin >> a.x;
	cout << "Nhap y: ";
	cin >> a.y;
	cout << "Nhap z: ";
	cin >> a.z;
}
float TinhKhoangCach(POINT A, POINT B) {
	return sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2) + pow(A.z - B.z, 2));
}