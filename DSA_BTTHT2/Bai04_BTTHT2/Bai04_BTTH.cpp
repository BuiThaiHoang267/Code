#include<iostream>
using namespace std;

int dem = 0;
int demDQ = 0;

void Nhap(int[], int);
bool BinarySearch(int[], int, int,int);
bool BinarySearchDQ(int[], int, int,int);

int main() {
	int n;
	cout << "Nhap n: ";
	cin >> n;
	cout << "Mang da co n phan tu va duoc sap xep tu giam dan tu n ve 1";
	int x;
	cout << "\nNhap phan tu can tim x = ";
	cin >> x;
	int* a = new int[n];
	Nhap(a, n);
	BinarySearch(a, 0, n - 1, x);
	cout << "\nSo lan so sanh cua thuat toan chua de quy: " << dem;
	BinarySearchDQ(a, 0, n - 1, x);
	cout << "\nSo lan so sanh cua thuat toan dung de quy: " << demDQ;
	return 0;
}

void Nhap(int a[], int n) {
	for (int i = 0; i < n; i++)
		a[i] = n - i;
}
bool BinarySearch(int a[], int l, int r, int x) {
	while (l <= r) {
		dem++;
		int m = (l + r) / 2;
		dem++;
		if (a[m] == x)
			return true;
		else if (a[m] > x) {
			l = m + 1;
		}
		else
			r = m - 1;
	}
	dem++;
	return false;
}
bool BinarySearchDQ(int a[], int l, int r, int x) {
	if (l <= r) {
		demDQ++;
		int m = (l + r) / 2;
		demDQ++;
		if (a[m]== x)
			return true;
		else if (a[m] > x) {
			return BinarySearchDQ(a, m + 1, r, x);
		}
		else {
			return BinarySearchDQ(a, l, m - 1, x);
		}
		demDQ++;
	}
	demDQ++;
	return false;
}