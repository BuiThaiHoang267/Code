#include<iostream>
using namespace std;

bool ktNguyenTo(long long);
void LietKe(long long);

int main() {
	long long n;
	cout << "Nhap n: ";
	cin >> n;
	LietKe(n);
	return 0;
}

bool ktNguyenTo(long long n)
{
	if (n <= 1)
		return false;
	if (n == 2)
		return true;
	if (n == 3)
		return true;
	if (n % 2 == 0)
		return false;
	if (n % 3 == 0)
		return false;
	for (long long i = 5; i * i <= n; i += 6)
		if ((n % i == 0) || (n % (i + 2) == 0))
			return false;
	return true;
}

void LietKe(long long n) {
	cout << "Cac so nguyen to trong doan: ";
	for (int i = 2; i< n; i++) {
		if (ktNguyenTo(i) == true) {
			cout << i << " ";
		}
	}
}