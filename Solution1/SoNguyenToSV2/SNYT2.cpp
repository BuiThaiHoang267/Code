#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

vector<long long> Eratosthenes(long long );
void Xuat(vector<long long>);
int Xuat(vector<long long>,string);

int main() {
	long long n;
	string filename;
	filename = "songuyento01.out";
	cout << "Nhap n: ";
	cin >> n;
	clock_t start, end, total;
	start = clock();
	vector<long long> kq = Eratosthenes(n);
	Xuat(kq, filename);
	end = clock();
	total = (double)(end - start) / CLOCKS_PER_SEC;
	cout << total << "s";
	return 0;
}
int Xuat(vector<long long> a, string filename)
{
	ofstream fo(filename);
	if (fo.fail() == true)
		return 0;
	for (int i = 0; i < a.size(); i++) {
		fo << a[i] << "  ";
	}
	return 0;
}


vector<long long> Eratosthenes(long long n) {
	vector<long long> prime;
	vector<bool> isprime(n + 1, true); // tat ca cac so deu dc danh la true
	isprime[0] = false;
	isprime[1] = false;
	for (long long p = 2; p * p <= n; p++) {
		if (isprime[p] == true)
			for (int i = p * p; i <= n; i += p)
				isprime[i] = false;
	}
	for (long long p = 2; p <= n; p++) {
		if (isprime[p] == true)
			prime.push_back(p);
	}

	return prime;
}
void Xuat(vector<long long> a) {
	int dem = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] >= 81957721 ) {
			cout << a[i] << " ";
			break;
		}
	}
}