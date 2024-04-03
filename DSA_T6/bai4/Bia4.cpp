#include<iostream>
using namespace std;

void XuatMangCon(int a[], int n, int k)
{
	cout << "Cac mang con co " << k << " phan tu la:" << endl;
	for (int i = 0; i < n - k+1; i++) {
		for (int j = i; j <= i + k - 1; j++)
			cout << a[j] << " ";
		cout << endl;
	}
	cout << endl;
}

int main() {
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 2; i <= n; i++) {
		XuatMangCon(a,n,i);
	}
	return 0;
}