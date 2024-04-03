#include<iostream>
using namespace std;

long long ucln(long long, long long);
long long bcnn(long long, long long);

int main() {
	long long a, b;
	cout << "Nhap a:";
	cin >> a;
	cout << "Nhap b:";
	cin >> b;
	long long kq = ucln(a, b);
	cout << "Uoc chung lon nhat cua a va b la: " << kq << endl;
	cout << "Boi chung nho nhat cua a va b la: " << bcnn(a, b) << endl;
	return 0;
}

long long ucln(long long a, long long b) {
	a = abs(a);
	b = abs(b);
	while (b > 0)
	{
		a = a % b;
		swap(a, b);
	}
	return a + b;
}
long long bcnn(long long a, long long b) 
{
	return (a / ucln(a, b)) * b;
}