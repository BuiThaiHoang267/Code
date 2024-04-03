#include<iostream>
using namespace std;

struct phanso {
	int tu;
	int mau;
};
typedef struct phanso PHANSO;

void Nhap(PHANSO&);
int KiemTra(PHANSO);

int main() {
	PHANSO A;
	Nhap(A);
	int kq = KiemTra(A);
	switch (kq) {
	case -1: cout << "Phan so nho hon 0";
		break;
	case 0: cout << "Phan so bang 0";
		break;
	case 1: cout << "Phan so lon hon 0";
		break;
	}
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
int KiemTra(PHANSO x) {
	if (x.tu == 0)
		return 0;
	else if ((x.tu > 0 && x.mau > 0) || (x.tu < 0 && x.mau < 0))
		return 1;
	else
		return -1;
}