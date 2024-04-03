#include<iostream>
using namespace std;

int DemChuSo(int);

int main() {
	int n;
	cout << "nhap n: ";
	cin >> n;
	int kq = DemChuSo(n);
	cout << "ket qua: " << kq;
	return 0;
}

int DemChuSo(int n) {
	n = abs(n);
	if (n <= 9)
		return 1;
	int dem = DemChuSo(n / 10);
	return dem + 1;
}