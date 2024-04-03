#include<iostream>
using namespace std;

bool LinearSearch(int[], int, int);
bool BinarySearch(int[], int, int, int);
void QuickSort(int[], int, int);

int main() {
	for (int j = 0; j < 100; j++) {
		int n;
		//cout << "Nhap so phan tu: ";
		n = 989974;
		int* a = new int[n];
		srand(time(NULL));
		for (int i = 0; i < n; i++)
			a[i] = rand();
		int x;
		x = rand();
		clock_t time_LS;
		time_LS = clock();
		LinearSearch(a, n, x);
		time_LS = clock() - time_LS;
		cout << "LinearSearch xu ly mat " << fixed << (double)time_LS / CLOCKS_PER_SEC << " giay";

		QuickSort(a, 0, n - 1);
		time_LS = clock();
		BinarySearch(a, 0, n - 1, x);
		time_LS = clock() - time_LS;
		cout << "    BinarySearch xu ly mat " << fixed << (double)time_LS / CLOCKS_PER_SEC << " giay";
		cout << endl;
	}
	return 0;
}

bool LinearSearch(int a[], int n, int x) {
	int lc = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == x)
			return true;
	}
	return false;
}
bool BinarySearch(int a[], int l, int r, int x) {
	while (l <= r) {
		int m = (l + r) / 2;
		if (a[m] == x)
			return true;
		else if (a[m] > x)
			r = m - 1;
		else
			l = m + 1;
	}
	return false;
}
void QuickSort(int a[], int l, int r) {
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
				i++;
				j--;
			}
		}
		if (l < j)
			QuickSort(a, l, j);
		if (i < r)
			QuickSort(a, i, r);
	}
}