#include<iostream>
using namespace std;

long long sumDivisors(long long);


int main() {
	long long n;
	cout << "Nhap n: ";
	cin >> n;
	cout << sumDivisors(n);
	return 0;
}
long long sumDivisors(long long n) {
	long long T = 1;
	long long p = 2;
	while (n>1) {
		long long power = 1;
		while (n % p == 0) {
			power *= p;
			n /= p;
		}
		T = T * (power * p - 1) / (p - 1);
		p++;
	}
	return T;
}