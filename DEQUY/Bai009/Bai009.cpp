#include<iostream>
using namespace std;

int ChuSoLonNhat(int);

int main() {
	int n;
	cout << "Nhap n: ";
	cin >> n;
	int kq = ChuSoLonNhat(n);
	cout << "Chu so lon nhat trong n: " << kq;
	return 0;
}

int ChuSoLonNhat(int n) {
	n = abs(n);
	if (n == 0)
		return 0;
	int lc = ChuSoLonNhat(n / 10);
	int dv = n % 10;
	if (dv > lc)
		lc = dv;
	return lc;
}