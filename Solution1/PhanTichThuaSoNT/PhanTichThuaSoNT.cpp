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

	while (n > 1)
	{
		while (n % p == 0)
		{
			prime_factor.push_back(p);
			n /= p;
		}
		p++;
	}

	return prime_factor;
}
void Xuat(vector<long long> a) {
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	}
}