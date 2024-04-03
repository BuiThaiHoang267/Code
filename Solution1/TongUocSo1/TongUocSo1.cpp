#include<iostream>
using namespace std;

long long sumDivisors(long long n);


int main() {
	long long n;
	cout << "Nhap n: ";
	cin >> n;
	cout << sumDivisors(n);
	return 0;
}
long long sumDivisors(long long n) {
	long long s = 0;
	for (long long i = 1; i <= n; i++) {
		if (n % i == 0) {
			s = s + i;
		}
	}
	return s;
}