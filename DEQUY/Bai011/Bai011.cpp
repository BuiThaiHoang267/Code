#include<iostream>
using namespace std;
int KtToanLe(int);
int main() {
	int n;
	cout << "Nhap n: ";
	cin >> n;
	if (KtToanLe(n) == 1)
		cout << "Ton tai toan le";
	else
		cout << "Khong ton tai toan le";
	return 0;
	return 0;
}
int KtToanLe(int n) {
	n = abs(n);
	if (n <= 9) {
		if (n % 2 != 0)
			return 1;
		return 0;
	}
	int dv = n % 10;
	if (KtToanLe(n / 10) && dv % 2 )
		return 1;
	return 0;
}