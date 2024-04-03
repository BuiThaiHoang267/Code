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
};
class CDuongTron {
private:
	CDiem I;
	float R;
public:
	friend istream& operator>>(istream& in, CDuongTron& a) {
		cout << "Nhap toa do tam I" << endl;
		in >> a.I;
		cout << "Nhap ban kinh R = ";
		in >> a.R;
		return in;
	}
	friend ostream& operator<<(ostream& out, CDuongTron& a) {
		out << "\nToa do tam I";
		out << a.I;
		out << "\nBan kinh R = " << a.R;
		return out;
	}
	float ChuVi();
	float DienTich();
};
int main() {
	CDuongTron O;
	cin >> O;
	cout << O;
	cout << "\nChu vi C = " << O.ChuVi();
	cout << "\nDien Tich C = " << O.DienTich();
	return 0;
}

float CDuongTron::ChuVi() {
	return 2 * R * 3.14159;
}
float CDuongTron::DienTich() {
	return R * R * 3.14159;
}