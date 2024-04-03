#include<iostream>
using namespace std;

int SoSanhS = 0, GanS = 0;
int SoSanhH = 0, GanH = 0;
int SoSanhQ = 0, GanQ = 0;
int SoSanhM = 0, GanM = 0;


void Nhap(int[], int&);
void Xuat(int[], int);
void SelectionSort(int a[], int n);
// HeapSort
void HeapSort(int a[], int n);
void heapify(int a[], int n, int i) {
	int l = 2 * i + 1; GanH++;
	int r = 2 * i + 2; GanH++;
	int largest = i; GanH++;
	SoSanhH += 2;
	if (l < n && a[l]>a[largest]) {
		largest = l; GanH++;
	}
	SoSanhH += 2;
	if (r<n && a[r]>a[largest]) {
		largest = r; GanH++;
	}
	SoSanhH++;
	if (largest != i) {
		swap(a[i], a[largest]);
		GanH += 3;
		heapify(a, n, largest);
	}
}
//
// Quick Sort
void QuickSort(int a[], int l, int r);
int partion(int a[], int l, int r) {
	int p = a[r]; GanQ++;
	int i = l - 1; GanQ++;
	GanQ++; SoSanhQ++;
	for (int j = l; j < r; j++) {
		GanQ++; SoSanhQ++;
		SoSanhQ++;
		if (p > a[j]) {
			i++;
			GanQ++;
			swap(a[i], a[j]);
			GanQ += 3;
		}
	}
	swap(a[r], a[i + 1]); GanQ += 3;
	return i + 1;
}
//
//Merge sort
void MergeSort(int a[], int l, int r);
void merge(int a[], int l, int m, int r) {
	int i, j, k = l; GanM++;
	int n1 = m - l + 1; GanM++;
	int n2 = r - m; GanM++;
	int* L = new int[n1];
	int* R = new int[n2];
	GanM++; SoSanhM++;
	for (i = 0; i < n1; i++) {
		GanM++; SoSanhM++;
		L[i] = a[l + i]; GanM++;
	}
	GanM++; SoSanhM++;
	for (j = 0; j < n2; j++) {
		GanM++; SoSanhM++;
		R[j] = a[m + 1 + j]; GanM++;
	}
	i = 0; j = 0; GanM += 2;
	SoSanhM += 2;
	while (i < n1 && j < n2) {
		SoSanhM += 2;
		SoSanhM++;
		a[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
		GanM += 3;
	}
	SoSanhM++;
	while (i < n1) {
		SoSanhM++;
		a[k++] = L[i++];
		GanM += 3;
	}
	SoSanhM++;
	while (j < n2) {
		SoSanhM++;
		a[k++] = R[j++];
		GanM += 3;
	}
}
//


int main() {
	int n;
	cout << "Nhap n: ";
	cin >> n;
	int* a = new int[n];

	Nhap(a, n);
	SelectionSort(a, n);
	Nhap(a, n);
	HeapSort(a, n);
	Nhap(a, n);
	QuickSort(a, 0, n - 1);
	Nhap(a, n);
	MergeSort(a, 0, n - 1);
	cout << "So phep so sanh cua SelectionSort: " << SoSanhS << endl;
	cout << "So phep gan cua SelectionSort: " << GanS << endl;
	cout << "So phep so sanh cua HeapSort: " << SoSanhH << endl;
	cout << "So phep gan cua HeapSort: " << GanH << endl;
	cout << "So phep so sanh cua QuickSort: " << SoSanhQ << endl;
	cout << "So phep gan cua QuickSort: " << GanQ << endl;
	cout << "So phep so sanh cua MergeSort: " << SoSanhM << endl;
	cout << "So phep gan cua MergeSort: " << GanM << endl;
	
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
	SoSanhS = n; GanS = n;
	for (int i = 0; i < n - 1; i++) {
		min_dex = i;
		SoSanhS++; GanS++;
		for (int j = i + 1; j < n; j++)
		{
			SoSanhS++; GanS++;
			SoSanhS++;
			if (a[min_dex] > a[j])
			{
				GanS++;
				min_dex = j;
			}
		}
		swap(a[i], a[min_dex]);
		GanS = GanS + 3;
	}
}
void HeapSort(int a[], int n) {
	//Xay dung max heap
	GanH++; SoSanhH++;
	for (int i = n / 2 - 1; i >= 0; i--) {
		GanH++; SoSanhH++;
		heapify(a, n, i);
	}
	GanH++; SoSanhH++;
	for (int i = n - 1; i >= 0; i--) {
		GanH++; SoSanhH++;
		swap(a[i], a[0]);
		GanH += 3;
		heapify(a, i, 0);
	}
}
void QuickSort(int a[], int l, int r) {
	SoSanhQ++;
	if (l < r) {
		int pi = partion(a, l, r); GanQ++;
		QuickSort(a, l, pi - 1);
		QuickSort(a, pi + 1, r);
	}
}
void MergeSort(int a[], int l, int r) {
	SoSanhM++;
	if (l < r) {
		int m = (l + r) / 2; GanM++;
		MergeSort(a, l, m);
		MergeSort(a, m + 1, r);
		merge(a, l, m, r);
	}
}