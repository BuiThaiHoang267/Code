#include<iostream>
using namespace std;

int GiaiThua(int);

int main() {
	int n;
	cout << "Nhap n: ";
	cin >> n;
	cout << "Ket qua: " << GiaiThua(n);
	return 0;
}

int GiaiThua(int n) {
	if (n == 0)
		return 1;
	int s = GiaiThua(n - 1);
	return (s * n);
}