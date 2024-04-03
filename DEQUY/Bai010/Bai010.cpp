#include<iostream>
using namespace std;
int TonTaiLe(int);
int main() {
	int n;
	cout << "Nhap n: ";
	cin >> n;
	if (TonTaiLe(n) == 1)
		cout << "Ton tai le";
	else
		cout << "Khong ton tai le";
	return 0;
}

int TonTaiLe(int n) {
	n = abs(n);
	if (n <= 9) {
		if (n % 2 != 0)
			return 1;
		return 0;
	}
	int dv = n % 10;
	if (dv % 2 != 0)
		return 1;
	return TonTaiLe(n / 10);
}