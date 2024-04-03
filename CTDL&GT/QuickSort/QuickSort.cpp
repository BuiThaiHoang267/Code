#include<iostream>
using namespace std;

int partion(int a[], int l, int h) {
	int p = a[h];
	int i = l - 1;//bien giam sat qua trinh thuc hien sap xep
	for (int j = l; j < h; j++) {
		if (a[j] < p) {
			i++;
			swap(a[i], a[j]);
		}
	}
	
	//tim dc vi tri chinh xac danh cho p
	swap(a[i + 1], a[h]);
	cout << i + 1 << " ";
	cout << endl;
	for (int i = 0; i < 10; i++) {
		cout << a[i] << " ";
	}
		cout << endl;

	return i + 1;
}

void quickSort(int a[], int l, int h) {
	if (l < h) {
		int pi = partion(a, l, h);
		quickSort(a, l, pi - 1);
		quickSort(a, pi + 1, h);
	}
}

void output(int a[], int n) {
	cout << endl;
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
	
}

int main()
{
	int a[10] = { 3,6,4,8,9,1,2,0,7,5 };
	int n = sizeof(a) / sizeof(int);
	output(a, n);
	quickSort(a, 0, n - 1);
	output(a, n);
	return 0;
}