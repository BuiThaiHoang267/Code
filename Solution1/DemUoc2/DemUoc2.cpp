#include<iostream>
using namespace std;

int Dem(long long);


int main() {
	long long n;
	cout << "Nhap n: ";
	cin >> n;
	cout << "So uoc cua " << n << " la: ";
	cout << Dem(n);
	return 0;
}

int Dem(long long n) {
	int T = 1;
	long long p = 2;
	while (n > 1) {
		int count = 0;
		while (n % p == 0) {
			count++;
			n /= p;
		}
		T += T * (count + 1);
		p++;
	}
	return T;
}