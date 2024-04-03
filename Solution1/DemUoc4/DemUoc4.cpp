#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int countDivisors(long long);
int main() {
	int n;
	cout << "Nhap n: ";
	cin >> n;
	int kq = countDivisors(n);
	cout << "So uoc so cua n la: " << kq;
	return 0;
}

int countDivisors(long long n) {
	vector<long long> minprime(n + 1);
	for (long long p = 0; p <= n; p++)
		minprime[p] = p;
	for (long long p = 2; p * p <= n; p++)
		if (minprime[p] == p)
			for (long long i = p * p; i <= n; i += p)
				if (minprime[i] == i)
					minprime[i] = p;
	int T = 1;
	while (n > 1) {
		int d = minprime[n];
		int count = 0;
		while (n % d == 0) {
			count++;
			n /= d;
		}
		T *= (count + 1);
	}
	return T;
}