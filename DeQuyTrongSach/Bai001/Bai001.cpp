#include<iostream>
using namespace std;

int TongBinhPhuong(int);

int main() {
	int n;
	cout << "Nhap n: ";
	cin >> n;
	cout << "ket qua: " << TongBinhPhuong(n);
	return 0;
}

int TongBinhPhuong(int n) {
	if (n == 1)
		return 1;
	return(TongBinhPhuong(n - 1) + n * n);
}