#include<iostream>
using namespace std;

int TongChan(int);

int main() {
	int n;
	cout << "nhap n: ";
	cin >> n;
	cout << TongChan(n);
	return 0;
}

int TongChan(int n) {
	n = abs(n);
	if (n == 0)
		return 0;
	int s = TongChan(n/10);
	int dv = n % 10;
	if (dv % 2 == 0)
		s = s + dv;
	return s;
}