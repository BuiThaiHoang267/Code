#include<iostream>
using namespace std;

int TongAn(int);

int main() {
	int n;
	cout << "nhap n: ";
	cin >> n;
	int kq = TongAn(n);
	cout << "ket qua: " << kq;
	return 0;
}

int TongAn(int n) {
	if (n == 1)
		return 2;
	return(TongAn(n - 1) + 2 * n + 1);
}