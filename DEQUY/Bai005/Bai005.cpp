#include<iostream>
using namespace std;

int TongChuSo(int);

int main() {
	int n;
	cout << "Nhap n: ";
	cin >> n;
	int kq = TongChuSo(n);
	cout << "Ket qua: " << kq;
	return 0;
}

int TongChuSo(int n) {
	if (n == 0)
		return 0;
	return (TongChuSo(n / 10) + n % 10);
}