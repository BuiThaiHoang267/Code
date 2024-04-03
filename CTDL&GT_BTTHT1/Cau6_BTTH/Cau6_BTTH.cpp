#include<iostream>
#include<time.h>
using namespace std;

int patitionLeft(int a[], int l, int r) {
	int p = a[l];
	int i = r+1;
	for (int j = r; j > l; j--) {
		if (p < a[j]) {
			i--;
			swap(a[i], a[j]);
		}
	}
	swap(a[l], a[i - 1]);
	return i - 1;
}
void QuickSortLeft(int a[], int l, int r) {
	if (l < r) {
		int pi = patitionLeft(a, l, r);
		QuickSortLeft(a, l, pi - 1);
		QuickSortLeft(a, pi + 1, r);
	}
}
void QuickSortMid(int a[], int l, int r) {
	if (l < r) {
		int i = l, j = r;
		int m = a[(l + r) / 2];
		while (i < j) {
			while (a[i] < m)
				i++;
			while (a[j] > m)
				j--;
			if (i <= j) {
				swap(a[i], a[j]);
				j--;
				i++;
			}
		}
		if (l < j)
			QuickSortMid(a, l, j);
		if (i < r)
			QuickSortMid(a, i, r);
	}
}
int partitionRight(int a[], int l, int r) {
	int p = a[r];
	int i = l - 1;
	for (int j = l; j < r; j++) {
		if (p > a[j]) {
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[r], a[i + 1]);
	return i + 1;
}
void QuickSortRight(int a[], int l, int r)
{
	if (l < r) {
		int pi = partitionRight(a, l, r);
		QuickSortRight(a, l, pi - 1);
		QuickSortRight(a, pi + 1, r);
	}
}

void Xuat(int a[], int n) {
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}
void Nhap(int a[], int& n) {
	srand(5);
	for (int i = 0; i < n; i++) {
		a[i] = rand() % (50000 + 1);
	}
}

int main() {
	int n;
	cin >> n;
	int* a = new int[500000];

	clock_t startR, endR;
	double durationR;
	clock_t startL, endL;
	double durationL;
	clock_t startM, endM;
	double durationM;

	Nhap(a, n);
	startR = clock();
	QuickSortRight(a, 0, n);
	endR = clock();
	durationR = (double)(endR - startR) / CLOCKS_PER_SEC;

	Nhap(a, n);
	startM = clock();
	QuickSortMid(a, 0, n);
	endM = clock();
	durationM = (double)(endM - startM) / CLOCKS_PER_SEC;

	Nhap(a, n);
	startL = clock();
	QuickSortLeft(a, 0, n);
	endL = clock();
	durationL = (double)(endL - startL) / CLOCKS_PER_SEC;
	delete[] a;
    
	cout << "Thoi gian xu ly chon pivot la phan tu dau tien: " << durationL << endl;
	cout << "Thoi gian xu ly chon pivot la phan tu o giua: " << durationM << endl;
	cout << "Thoi gian xu ly chon pivot la phan tu cuoi cung: " << durationR;
	return 0;
}