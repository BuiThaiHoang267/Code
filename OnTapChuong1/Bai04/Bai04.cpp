#include<iostream>
using namespace std;

struct phanso {
	int tu;
	int mau;
};
typedef struct phanso PHANSO;

void Nhap(PHANSO&);
PHANSO Tong(PHANSO, PHANSO);
PHANSO Hieu(PHANSO, PHANSO);
PHANSO Thuong(PHANSO, PHANSO);
PHANSO Tich(PHANSO, PHANSO);
void Xuat(PHANSO);


int main() {
	PHANSO A, B;
	Nhap(A);
	Nhap(B);
	cout << "\nTong 2 phan so\n";
	Xuat(Tong(A, B));
	cout << "\nHieu 2 phan so\n";
	Xuat(Hieu(A, B));
	cout << "\nThuong 2 phan so\n";
	Xuat(Thuong(A, B));
	cout << "\nTich 2 phan so\n";
	Xuat(Tich(A, B));
	return 0;
}

void Nhap(PHANSO& x) {
	cout << "Nhap tu: ";
	cin >> x.tu;
	cout << "Nhap mau: ";
	cin >> x.mau;
	if (x.mau == 0) {
		do {
			cout << "Mau khac 0 vui long nhap lai!";
			cin >> x.mau;
		} while (x.mau == 0);
	}
}
PHANSO Tong(PHANSO a, PHANSO b) {
	PHANSO temp;
	temp.tu = a.tu * b.mau + a.mau * b.tu;
	temp.mau = a.mau * b.mau;
	return temp;
}
PHANSO Hieu(PHANSO a, PHANSO b) {
	PHANSO temp;
	temp.tu = a.tu * b.mau - a.mau * b.tu;
	temp.mau = a.mau * b.mau;
	return temp;
}
PHANSO Thuong(PHANSO a, PHANSO b) {
	PHANSO temp;
	temp.tu = a.tu * b.mau;
	temp.mau = a.mau * b.tu;
	return temp;
}
PHANSO Tich(PHANSO a, PHANSO b) {
	PHANSO temp;
	temp.tu = a.tu * b.tu;
	temp.mau = a.mau * b.mau;
	return temp;
}
void Xuat(PHANSO x) {
	cout << "tu = " << x.tu;
	cout << "\nmau = " << x.mau;
}