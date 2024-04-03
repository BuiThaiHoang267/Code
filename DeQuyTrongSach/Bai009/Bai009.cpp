#include<iostream>
using namespace std;
long double LuyThua(double, int);
int main()
{
	double x;
	cout << "nhap x: ";
	cin >> x;
	int n;
	cout << "Nhap n: ";
	cin >> n;
	cout << "Ket qua: " << LuyThua(x, n);
	return 0;
}
long double LuyThua(double x, int n) {
	if (n == 0)
		return 1;
	return(LuyThua(x,n - 1) * x);
}