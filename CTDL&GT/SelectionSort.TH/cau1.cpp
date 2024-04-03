#include<iostream>
using namespace std;


// SelectionSort
void selectionSort(int a[], int n) { // tim phan tu nho nhat roi swap vi tri i vs j
	int min_index = 0;
	for (int i = 0; i < n - 1; i++) {
		min_index = i;
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[min_index])
				min_index = j;
		}
		swap(a[i], a[min_index]);
	}
}

//InterchangeSort
void InterchangeSort(int a[], int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = i+1; j < n; j++)
			if (a[j] < a[i])
				swap(a[i], a[j]);
}

//Insertion Sort
void InsertionSort(int  a[], int n) {
	int pos, x;
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
void Xuat(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}
int main() {
	int a[10] = { 1,0,4,7,3,6,5,9,8,2 };
	int n = 10;
	InsertionSort(a, n);
	Xuat(a, n);
	return 0;
}