#include<iostream>
#include<vector>
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
	vector<long long> minprime(n + 1);
	for (long long p = 0; p <= n; p++)
		minprime[p] = p;
	for (long long p = 2; p * p <= n; p++)
		if (minprime[p] == p)
			for (long long i = p * p; i <= n; i += p)
				if (minprime[i] == i)
					minprime[i] = p;

	long long T = 1;
	while (n > 1) {
		int d = minprime[n];
		long long power = 1;
		while (n % d == 0) {
			power *= d;
			n /= d;
		}
		T = T * (power * d - 1) / (d - 1);
	}
	return T;
}