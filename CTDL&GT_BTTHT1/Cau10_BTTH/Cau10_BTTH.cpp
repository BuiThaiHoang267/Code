#include<iostream>
using namespace std;

struct DaThuc {
	int dau;
	float heso;
	int bac;
};

void Nhap(DaThuc a[],int n);
void Nhap(DaThuc&);
void Xuat(DaThuc a[], int n);
void Xuat(DaThuc a);
void InterchangeSortBac(DaThuc a[], int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i].bac > a[j].bac)
				swap(a[i], a[j]);
}

int main() {
	int n;
	cout << "Nhap so luong so hang cua DaThuc: ";
	cin >> n;
	DaThuc* a = new DaThuc[n];
	Nhap(a, n);
	InterchangeSortBac(a, n);
	Xuat(a, n);
	return 0;
}

void Nhap(DaThuc a[], int n) {
	for (int i = 0; i < n; i++)
		Nhap(a[i]);
}

void Nhap(DaThuc& a) {
	do {
		cout << "\nNhap dau: ";
		cin >> a.dau;
	} while (a.dau != 0 && a.dau != 1);
	cout << "Nhap he so: ";
	cin >> a.heso;
	do {
		cout << "Nhap bac: ";
		cin >> a.bac;
	} while (a.bac < 0 && a.bac>100);
}

void Xuat(DaThuc a[], int n) {
	for (int i = 0; i < n; i++)
		Xuat(a[i]);
}
void Xuat(DaThuc a) {
	cout << "Dau: " << a.dau << endl;
	cout << "He so: " << a.heso << endl;
	cout << "Bac: " << a.bac << endl;
}