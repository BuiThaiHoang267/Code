#include<iostream>
using namespace std;

int partion(int a[], int l, int r) { // tim ra vi tri chinh xac cua mot phan tu a[i].
	int p = a[r];
	int i = l - 1;
	for (int j = l; j < r; j++) {
		if (a[j] < p) {
			i++;
			swap(a[j], a[i]);
		}
	}
	swap(a[i + 1], a[r]);
	return i + 1;
}

void QuickSort(int a[], int l, int r) {
	if (l < r) {
		int pi = partion(a, l, r);
		QuickSort(a, l, pi - 1);
		QuickSort(a, pi + 1, r);
	}
}

void output(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}
int main() {
	int a[10] = { 1,0,3,8,5,6,4,9,2,7 };
	QuickSort(a, 0, 9);
	output(a, 10);
	return 0;
}