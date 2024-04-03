#include<iostream>
using namespace std;

void Xuat(int[], int);
void InterchangeSort(int[], int);
void UninterchangeSort(int[], int);
void CauA(int[], int);
void CauB(int[], int);
void CauC(int[], int);
void CauD(int[], int);
void CauE(int[], int);

int main() {
	int a[10] = { 1,5,3,-2,-3,4,-5,-1,2,-4 };
	//CauA(a, 10);
	//CauB(a, 10);
	//CauC(a, 10);
	//CauD(a, 10);
	CauE(a, 10);
	Xuat(a, 10);
	return 0;
}

void Xuat(int a[], int n) {
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}
void InterchangeSort(int a[], int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[i])
				swap(a[i], a[j]);
}
void UninterchangeSort(int a[], int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[j] > a[i])
				swap(a[i], a[j]);
}

void CauA(int a[], int n) {
	InterchangeSort(a, n);
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] < 0)
		{
			k++;
		}
		else
			break;
	}
	for (int i = k; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] < a[j])
				swap(a[i], a[j]);
}

void CauB(int a[], int n) {
	InterchangeSort(a, n);
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] < 0)
		{
			k++;
		}
		else
			break;
	}
	for (int i = 0; i < k-1; i++)
		for (int j = i + 1; j < k; j++)
			if (a[i] < a[j])
				swap(a[i], a[j]);
}

void CauC(int a[], int n) {
	UninterchangeSort(a, n);
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] >= 0)
		{
			k++;
		}
		else
			break;
	}
	for (int i = 0; i < k-1; i++)
		for (int j = i + 1; j < k; j++)
			if (a[i] > a[j])
				swap(a[i], a[j]);
}

void CauD(int a[], int n) {
	UninterchangeSort(a, n);
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] >= 0)
		{
			k++;
		}
		else
			break;
	}
	for (int i = k; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j])
				swap(a[i], a[j]);
}

void CauE(int a[], int n) {
	for (int i = 0; i < n - 1; i++)
		if (a[i] < 0)
			for (int j = i + 1; j < n; j++)
				if (a[j] < 0)
					if (a[i] > a[j])
						swap(a[i], a[j]);
	for (int i = 0; i < n - 1; i++)
		if (a[i] >= 0)
			for (int j = i + 1; j < n; j++)
				if (a[j] >= 0)
					if (a[i] < a[j])
						swap(a[i], a[j]);
}