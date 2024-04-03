#include<iostream>
using namespace std;

int Luythua(float,int);

int main()
{
	float y;
	cout << "Nhap y: ";
	cin >> y;
	int k;
	cout << "Nhap k: ";
	cin >> k;
	int kq = Luythua(y,k);
	cout << "ket qua : " << kq;
	return 0;
}

int Luythua(float x,int n)
{
	if (n == 0)
		return 1;
	float T = Luythua(x,n - 1);
	return (T * n);
}