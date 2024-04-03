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
	int dem = 0;
	for (int i = 1; i <= n; i++) {
		if (n % i == 0) {
			dem++;
		}
	}
	return dem;
}