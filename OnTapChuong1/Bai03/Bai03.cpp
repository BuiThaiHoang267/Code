#include<iostream>
using namespace std;

struct phanso {
	int tu;
	int mau;
};
typedef struct phanso PHANSO;

void Nhap(PHANSO&);
int SoSanh(PHANSO, PHANSO);
void Xuat(PHANSO);

int main() {
	PHANSO A, B;
	Nhap(A);
	Nhap(B);
	if (SoSanh(A, B) >= 1)
		Xuat(A);
	else
		Xuat(B);
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
int SoSanh(PHANSO x, PHANSO y) {
	float X = (float)x.tu / x.mau;
	float Y = (float)y.tu / y.mau;
	if (X > Y)
		return 1;
	else
		return -1;
	return 0;
}
void Xuat(PHANSO x) {
	cout << "tu = " << x.tu;
	cout << "\nmau = " << x.mau;
}