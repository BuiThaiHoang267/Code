#include<iostream>
using namespace std;

long long ucln(long long, long long);

int main() {
	long long a, b;
	cout << "Nhap a:";
	cin >> a;
	cout << "Nhap b:";
	cin >> b;
	long long kq = ucln(a, b);
	cout << "Uoc chung lon nhat cua a va b la: " << kq << endl;
	return 0;
}

long long ucln(long long a, long long b) {
	a = abs(a);
	b = abs(b);
	while ( b > 0)
	{
		a = a % b;
		swap(a, b);
	}
	return a + b;
}