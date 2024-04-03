#include<iostream>
using namespace std;

long long ucln(long long, long long);

int main() {
	long long a,b;
	cout << "Nhap a:";
	cin >> a;
	cout << "Nhap b:";
	cin >> b;
	long long kq= ucln(a, b);
	cout << "Uoc chung lon nhat la: " << kq;
	return 0;
}

long long ucln(long long a, long long b) {
	a = abs(a);
	b = abs(b);
	while (a != 0 && b != 0)
	{
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	return a + b;
}