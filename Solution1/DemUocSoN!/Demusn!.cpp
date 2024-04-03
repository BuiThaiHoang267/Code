#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long countDivisors(long long n);
unsigned long long Sum(long long);

int main()
{
	long long n;
	cout << "Nhap n: ";
	cin >> n;
	cout << endl;
	cout <<"So uoc cua "<<n<<"! la: " << Sum(n);
	return 0;
}
unsigned long long Sum(long long n)
{
	vector<long long> minprime(n + 1);
	for (long long p = 0; p <= n; p++)
		minprime[p] = p;
	for (long long p = 2; p * p <= n; p++)
		if (minprime[p] == p)
			for (long long i = p * p; i <= n; i += p)
				if (minprime[i] == i)
					minprime[i] = p;

	vector<long long> factoriprime;
	for (int i = 2; i <= n; i++) {
		int n = i;
		while (n > 1)
		{
			factoriprime.push_back(minprime[n]);
			n /= minprime[n];
		}
	}
	sort(factoriprime.begin(), factoriprime.end());

	unsigned long long T = 1;
	for (int i = 0; i < factoriprime.size(); i++) {
		int count = 0;
		for (int j = i; j < factoriprime.size(); j++) {
			if (factoriprime[i] == factoriprime[j]) {
				count++;
			}
			else {
				break;
			}
		}
		T = T * (pow(factoriprime[i], count + 1) - 1) / (factoriprime[i] - 1);
		i = i + count - 1;
	}
	return T;

}

long long countDivisors(long long n) {
	vector<long long> minprime(n + 1);
	for (long long p = 0; p <= n; p++)
		minprime[p] = p;
	for (long long p = 2; p * p <= n; p++)
		if (minprime[p] == p)
			for (long long i = p * p; i <= n; i += p)
				if (minprime[i] == i)
					minprime[i] = p;

	vector<long long> factoriprime;
	for (int i = 2; i <= n; i++) {
		int n = i;
		while (n > 1)
		{
			factoriprime.push_back(minprime[n]);
			n /= minprime[n];
		}
	}
	sort(factoriprime.begin(), factoriprime.end());

	long long T = 1;
	for (int i = 0; i < factoriprime.size(); i++) {
		int count = 0;
		for (int j = i; j < factoriprime.size(); j++) {
			if (factoriprime[i] == factoriprime[j]) {
				count++;
			}
			else {
				break;
			}
		}
		T = T * (count + 1);
		i = i + count - 1;
	}
	return T;
}