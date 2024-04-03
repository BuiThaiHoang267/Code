#include<iostream>
using namespace std;
float Tinh(int);
int main() {
	int n;
	cout << "Nhap n: ";
	cin >> n;
	cout << "ket qua: " << Tinh(n);
	return 0;
}
float Tinh(int n) {
	if (n == 0)
		return 1;
	float s = Tinh(n - 1);
	return (s * (1 + (float)1 / (n * n)));
}