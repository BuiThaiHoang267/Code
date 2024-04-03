#include<iostream>
using namespace std;

void Nhap(int a[], int n);
void Xuat(int a[], int n);
void heap(int a[], int n, int i) {
	int L = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l<n && a[l]>a[L])
		L = l;
	if (r<n && a[r]>a[L])
		L = r;
	if (L != i) {
		swap(a[i], a[L]);
		heap(a, n, L);
	}
}
void HeapSort(int a[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--)
		heap(a, n, i);
	for (int i = n - 1; i >= 1; i--) {
		swap(a[0], a[i]);
		heap(a, i, 0);
	}
}

int main() {
	int n;
	cin >> n;
	int* a = new int[n];
	Nhap(a, n);
	HeapSort(a, n);
	Xuat(a, n);
	delete[] a;
	return 0;
}

void Nhap(int a[], int n) {
	srand(5);
	for (int i = 0; i < n; i++)
		a[i] = rand() %( 100 + 1);
}
void Xuat(int a[], int n) {
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}