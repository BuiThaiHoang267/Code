#include<iostream>
#include<vector>
using namespace std;

vector<long long> Factorization(long long);
void Xuat(vector<long long>);

int main() {
	long long n;
	cout << "Nhap n: ";
	cin >> n;
	Xuat(Factorization(n));
	return 0;
}

vector<long long> Factorization(long long n) {
	vector<long long> prime_factor;
	long long p = 2;

	while (p*p<=n)
	{
		while (n % p == 0)
		{
			prime_factor.push_back(p);
			n /= p;
		}
		p++;
	}
	if (n > 1)
		prime_factor.push_back(n);
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