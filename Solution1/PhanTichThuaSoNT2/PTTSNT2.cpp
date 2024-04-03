#include<iostream>
#include<vector>
using namespace std;

vector<long long> Eratosthenes(long long);
void Xuat(vector<long long>);

int main() {
	long long n;
	cout << "Nhap n: ";
	cin >> n;
	Xuat(Eratosthenes(n));
	return 0;
}

vector<long long> Eratosthenes(long long n) {
	vector<long long> minprime(n + 1, true);
	for (long long p = 0; p <= n; p++) {
		minprime[p] = p;
	}
	for (long long p = 2; p * p <= n; p++) {
		if (minprime[p] == p)
			for (long long i = p * p; i <= n; i += p)
				if (minprime[i] == i)
					minprime[i] = p;
	}

	vector<long long> prime_factor;
	while (n > 1) {
		prime_factor.push_back(minprime[n]);
		n /= minprime[n];
	}
	for (int i = 0; i < prime_factor.size(); i++)
	{
		cout << prime_factor[i] << "  ";
	}
	cout << endl;
	return prime_factor;
}
void Xuat(vector<long long> a) {
	int SotruocDo = a[0];
	int dem = 1;
	for (int i = 1; i < a.size(); i++) {
		if (i >= 1) {
			if (SotruocDo != a[i]) {
				cout << SotruocDo << "^" << dem << " ";
				SotruocDo = a[i];
				dem = 1;
			}
			if (i == a.size() - 1) {
				cout << a[i] << "^" << dem << " ";
			}
		}
		if (SotruocDo == a[i]) {
			dem++;
		}
	}
}