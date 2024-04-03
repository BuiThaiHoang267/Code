#include<iostream>
using namespace std;

void Nhap(int*, int);
void Xuat(int*, int);
void SelectionSort(int*, int);
void InsertionSort(int*, int);
void InterchangeSort(int*, int);

int main() {
	int n;
	cout << "Nhap n:";
	cin >> n;
	int* a = new int[n];
	Nhap(a, n);
	//SelectionSort(a, n);
	//InsertionSort(a, n);
	InterchangeSort(a, n);
	Xuat(a, n);
	delete[] a;
	return 0;
}

void Nhap(int* a, int n) {
	for (int i = 0; i < n; i++)
		cin >> a[i];
}
void Xuat(int* a, int n) {
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}
void SelectionSort(int* a, int n) {
	int min_dex;
	for (int i = 0; i < n - 1; i++) {
		min_dex = i;
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[min_dex])
				min_dex = j;
		swap(a[i], a[min_dex]);
	}
}
void InsertionSort(int* a, int n) {
	int pos = 0, x;
	for (int i = 1; i < n; i++) {
		x = a[i];
		pos = i - 1;
		while (pos >= 0 && a[pos] > x) {
			a[pos + 1] = a[pos];
			pos--;
		}
		a[pos + 1] = x;
	}
}
void InterchangeSort(int* a, int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[i])
				swap(a[i], a[j]);
}
