#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

void InterchangeSort(int a[], int n);
void SelectionSort(int a[], int n);
void InsertionSort(int a[], int n);
void BubbleSort(int a[], int n);
void heapify(int a[], int n, int i);
void HeapSort(int a[], int n);
int partition(int a[], int l, int r);
void QuickSort(int a[], int l, int r);
void merge(int a[], int l, int r, int m);
void MergeSort(int a[], int l, int r);

int main() 
{
	int a[10] = { 1,8,4,7,5,6,2,9,10,3 };
	//InterchangeSort(a,10);
	//SelectionSort(a, 10);
	InsertionSort(a, 10);
	//BubbleSort(a, 10);
	//HeapSort(a, 10);
	//QuickSort(a, 0, 9);
	//MergeSort(a, 0, 9);
	for (int i = 0; i < 10; i++)
		cout << a[i] << " ";
	return 0;
}

void InterchangeSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j])
				swap(a[i], a[j]);
}
void SelectionSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int vt = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[vt] > a[j])
				vt = j;
		}
		swap(a[vt], a[i]);
	}
}
void InsertionSort(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int key = a[i];
		int vt = i - 1;
		while (vt >= 0 && a[vt] > key)
		{
			a[vt + 1] = a[vt];
			vt--;
		}
		a[vt+1] = key;
	}
}
void BubbleSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = n-1; j>i; j--)
			if (a[j] < a[j - 1])
				swap(a[j], a[j - 1]);
}
void heapify(int a[], int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && a[largest] < a[l])
		largest = l;
	if (r < n && a[largest] < a[r])
		largest = r;

	if (largest != i)
	{
		swap(a[i], a[largest]);
		heapify(a, n, largest);
	}
}
void HeapSort(int a[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(a, n, i);

	for (int i = n - 1; i > 0; i--)
	{
		swap(a[0], a[i]);
		heapify(a, i, 0);
	}
}
int partition(int a[], int l, int r)
{
	int p = a[r];
	int j = l - 1;
	for (int i = l; i < r; i++)
	{
		if (a[i] < p)
		{
			j++;
			swap(a[i], a[j]);
		}
	}
	swap(a[r], a[j + 1]);
	return j + 1;
}
void QuickSort(int a[], int l, int r)
{
	if (l < r)
	{
		int pivod = partition(a, l, r);
		QuickSort(a, l, pivod - 1);
		QuickSort(a, pivod + 1, r);
	}
}
void merge(int a[], int l, int r, int m)
{
	int* temp = new int[r - l + 2];
	int k = 0;
	int i = l;
	int j = m + 1;
	while (!(i > m && j > r))
	{
		if ((a[i] < a[j] && i <= m && j <= r) || j > r)
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	for (int i = 0; i < k; i++)
		a[l + i] = temp[i];
	delete[] temp;
}
void MergeSort(int a[], int l, int r)
{
	if (l < r) 
	{
		int m = (l + r) / 2;
		MergeSort(a, l, m);
		MergeSort(a, m + 1, r);
		merge(a, l, r, m);
	}
}



