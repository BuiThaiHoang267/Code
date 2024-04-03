#include<iostream>
using namespace std;

int SoSanhS=0, GanS=0;
int SoSanhH=0, GanH=0;
int SoSanhQ=0, GanQ=0;
int SoSanhM=0, GanM=0;


void Nhap(int[], int&);
void Xuat(int[], int);
void SelectionSort(int a[], int n);
// HeapSort
void HeapSort(int a[], int n);
void heapify(int a[], int n, int i) {
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int largest = i;
	if (l < n && a[l]>a[largest])
		largest = l;
	if (r<n && a[r]>a[largest])
		largest = r;
	if (largest != i) {
		swap(a[i], a[largest]);
		heapify(a, n, largest);
	}
}
//
// Quick Sort
void QuickSort(int a[], int l, int r);
int partion(int a[], int l, int r) {
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
//
//Merge sort
void MergeSort(int a[], int l, int r);
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
//


int main() {
	int n;
	cout << "Nhap n: ";
	cin >> n;
	clock_t startS, endS;
	double durationS;
	clock_t startH, endH;
	double durationH;
	clock_t startQ, endQ;
	double durationQ;
	clock_t startM, endM;
	double durationM;
	int* a = new int[n];
	
	Nhap(a, n);
	startS = clock();
	SelectionSort(a, n);
	endS = clock();
	durationS = (double)(endS - startS) / CLOCKS_PER_SEC;

	Nhap(a, n);
	startH = clock();
	HeapSort(a, n);
	endH = clock();
	durationH = (double)(endH - startH) / CLOCKS_PER_SEC;

	Nhap(a, n);
	startQ = clock();
	QuickSort(a, 0, n - 1);
	endQ = clock();
	durationQ = (double)(endQ - startQ) / CLOCKS_PER_SEC;

	Nhap(a, n);
	startM = clock();
	MergeSort(a, 0, n - 1);
	endM = clock();
	durationM = (double)(endM - startM) / CLOCKS_PER_SEC;

	cout << "Thoi gian xu ly cua SelectionSort: " << durationS << endl;
	cout << "Thoi gian xu ly cua HeapSort: " << durationH << endl;
	cout << "Thoi gian xu ly cua QuickSort: " << durationQ << endl;
	cout << "Thoi gian xu ly cua MergeSort: " << durationM << endl;
	delete[] a;
	return 0;
}

void Nhap(int a[], int& n) {
	srand(20);
	for (int i = 0; i < n; i++) {
		a[i] = rand() % (50000 + 1);
	}
}
void Xuat(int a[], int n) {
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}
void SelectionSort(int a[], int n) {
	int min_dex;
	for (int i = 0; i < n - 1; i++) {
		min_dex = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[min_dex] > a[j])
				min_dex = j;
		}
		swap(a[i], a[min_dex]);
	}
}
void HeapSort(int a[], int n) {
	//Xay dung max heap
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(a, n, i);
	}
	for (int i = n - 1; i >= 0; i--) {
		swap(a[i], a[0]);
		heapify(a, i, 0);
	}
}
void QuickSort(int a[], int l, int r) {
	if (l < r) {
		int pi = partion(a, l, r);
		QuickSort(a, l, pi - 1);
		QuickSort(a, pi + 1, r);
	}
}
void MergeSort(int a[], int l, int r) {
	if (l < r) {
		int m = (l + r) / 2;
		MergeSort(a, l, m);
		MergeSort(a, m + 1, r);
		merge(a, l, m, r);
	}
}