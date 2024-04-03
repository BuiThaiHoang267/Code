#include<iostream>
#include<cmath>
using namespace std;

class CDiem {
private:
	float x;
	float y;
public:
	friend istream& operator>>(istream& in, CDiem& a) {
		cout << "Nhap x: ";
		cin >> a.x;
		cout << "Nhap y: ";
		cin >> a.y;
		return in;
	}
	friend ostream& operator<<(ostream& out, CDiem& a) {
		cout << "(" << a.x << "," << a.y << ")" << endl;
		return out;
	}
	float KhoangCach2Diem(CDiem);
	float getX();
	float getY();
	void setX(float);
	void setY(float);

};
class CTamGiac {
private:
	CDiem A;
	CDiem B;
	CDiem C;
public:
	friend istream& operator>>(istream& in, CTamGiac& a) {
		cout << "Nhap diem A: ";
		in >> a.A;
		cout << "Nhap diem B: ";
		in >> a.B;
		cout << "Nhap diem C: ";
		in >> a.C;
		return in;
	}
	friend ostream& operator<<(ostream& out, CTamGiac& a) {
		out << "\ntoa do A" << a.A;
		
		out << "\ntoa do B" << a.B;
		
		out << "\ntoa do C" << a.C;
		
		return out;
	}
	float ChuVi();
	float DienTich();
	CDiem TrongTam();
};
int main() {
	CTamGiac O;
	CDiem G;
	cout << "Nhap cac toa do cua tam giac! " << endl;
	cin >> O;
	cout << "Chu vi cua tam giac O:   C = " << O.ChuVi() << endl;
	cout << "Dien tich cua tam giac O:   S = " << O.DienTich() << endl;
	cout << "Trong tam cua tam giac la:    G";
	G=O.TrongTam();
	cout << G;
	return 0;
}

void CDiem::setX(float a) {
	x = a;
}
void CDiem::setY(float a) {
	y = a;
}
float CDiem::getX() {
	return x;
}
float CDiem::getY() {
	return y;
}
float CDiem::KhoangCach2Diem(CDiem a) {
	return sqrt(pow(x - a.x, 2) + pow(y - a.y, 2));
}

float CTamGiac::ChuVi() {
	return (A.KhoangCach2Diem(B) + B.KhoangCach2Diem(C) + C.KhoangCach2Diem(A));
}
float CTamGiac::DienTich() {
	float a = A.KhoangCach2Diem(B);
	float b = B.KhoangCach2Diem(C);
	float c = C.KhoangCach2Diem(A);
	float p = (float)(a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}
CDiem CTamGiac::TrongTam() {
	CDiem temp;
	temp.setX((A.getX() + B.getX() + C.getX())/3);
	temp.setY((A.getY() + B.getY() + C.getY())/3);
	return temp;
}