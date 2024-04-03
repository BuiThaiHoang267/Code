#include<iostream>
using namespace std;

void selectionSort(int a[], int n) { // tim phan tu nho nhat roi swap vi tri i vs j
	int min_index = 0;
	for (int i = 0; i < n-1; i++) {
		min_index = i;
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[min_index])
				min_index = j;
		}
		swap(a[i], a[min_index]);
	}
}

void output(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

int main()
{
	int a[] = { 1,5,6,7,2,3,4,9,8,0 };
	int n = sizeof(a) / sizeof(int);
	selectionSort(a, n);
	output(a, n);
	return 0;
}