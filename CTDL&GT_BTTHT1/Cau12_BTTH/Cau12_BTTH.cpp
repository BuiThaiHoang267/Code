#include<iostream>
using namespace std;

void SelectionSort(int a[], int n);
void InsertionSort(int a[], int n);
void InterchangeSort(int a[], int n);
void BubbleSort(int a[], int n);
void HeapSort(int a[], int n);
void Heap(int a[], int n,int i);
void QuickSort(int a[], int l,int r);
int  partition(int a[], int l, int r);
void MergeSort(int a[], int l, int r);
void merge(int a[], int l, int m, int r);

void Nhap(int a[], int n) {
	srand(6);
	for (int i = 0; i < n; i++) {
		a[i] = rand() % (50000 + 1);
	}
}
void Xuat(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}

int main() {
	int n;
	cout << "Nhap n: ";
	cin >> n;
	int* a = new int[100000];
	Nhap(a, n);
	//InterchangeSort(a,n);
	//SelectionSort(a, n);
	//InsertionSort(a, n);
	//BubbleSort(a, n);
	//HeapSort(a, n);
	//QuickSort(a, 0, n - 1);
	//MergeSort(a, 0, n - 1);
	Xuat(a, n);
	return 0;
}
void SelectionSort(int a[], int n) {
	int min_dex;
	for (int i = 0; i < n - 1; i++) {
		min_dex = i;
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[min_dex])
				min_dex = j;
		}
		swap(a[i], a[min_dex]);
	}
}
void InsertionSort(int a[], int n) {
	int x, pos;
	for (int i = 0; i < n; i++) {
		x = a[i];
		pos = i - 1;
		while (pos >= 0 && a[pos] > x) {
			a[pos + 1] = a[pos];
			pos--;
		}
		a[pos + 1] = x;
	}
}
void InterchangeSort(int a[], int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j])
				swap(a[i], a[j]);
}
void BubbleSort(int a[], int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j >= i + 1; j--)
			if (a[j - 1] > a[j])
				swap(a[j - 1], a[j]);
}
void HeapSort(int a[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--) {
		Heap(a, n, i);
	}
	for (int i = n - 1; i >= 0; i--) {
		swap(a[i], a[0]);
		Heap(a, i, 0);
	}
}
void Heap(int a[], int n,int i) {
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int largest = i;
	if (l < n && a[l]>a[largest])
		largest = l;
	if (r<n && a[r]>a[largest])
		largest = r;
	if (largest != i) {
		swap(a[i], a[largest]);
		Heap(a, n, largest);
	}
}
void QuickSort(int a[], int l, int r) {
	if (l < r) {
		int pi = partition(a, l, r);
		QuickSort(a, l, pi - 1);
		QuickSort(a, pi + 1, r);
	}
}
int  partition(int a[], int l, int r) {
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
void MergeSort(int a[], int l, int r) {
	if (l < r) {
		int m = (l + r) / 2;
		MergeSort(a, l, m);
		MergeSort(a, m + 1, r);
		merge(a, l, m, r);
	}
}
void merge(int a[], int l, int m, int r) {
	int i, j, k = l;
	int n1 = m - l + 1;
	int n2 = r - m;
	int* L = new int[n1];
	int* R = new int[n2];
	for (i = 0; i < n1; i++)
		L[i] = a[l + i];
	for (j = 0; j < n2; j++)
		R[j] = a[m + 1 + j];
	i = 0; j = 0;
	while (i < n1 && j < n2)
		a[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
	while (i < n1)
		a[k++] = L[i++];
	while (j < n2)
		a[k++] = R[j++];
}