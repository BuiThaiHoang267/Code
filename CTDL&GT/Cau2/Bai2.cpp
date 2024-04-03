#include<iostream>
using namespace std;

void InterchangeSort(int a[], int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[i])
				swap(a[i], a[j]);
}

void CauA(int a[], int n) {
	InterchangeSort(a, n);
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] >= 0) {
			k = i;
			break;
		}
	}
	for (int i = 0; i+k <= (k + n) / 2; i++)
		swap(a[i+k], a[n - i -1]);
}

void CauB(int a[], int n) {
	InterchangeSort(a, n);
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] >= 0) {
			k = i;
			break;
		}
	}
	for (int i = 0; i<= (k-1) / 2; i++)
		swap(a[i], a[k - i -1]);
}

void CauC(int a[], int n) {
	InterchangeSort(a, n);
	int k = 0;
	for (int i = 0; i < n / 2; i++)
		swap(a[i], a[n - i - 1]);
	for (int i = 0; i < n; i++) {
		if (a[i] < 0) {
			k = i;
			break;
		}
	}
	for (int i = 0; i < k - 1; i++)
		for (int j = i + 1; j < k; j++)
			if (a[j] < a[i])
				swap(a[i], a[j]);
}

void CauD(int a[], int n) {
	InterchangeSort(a, n);
	int k = 0;
	for (int i = 0; i < n / 2; i++)
		swap(a[i], a[n - i - 1]);
	for (int i = 0; i < n; i++) {
		if (a[i] < 0) {
			k = i;
			break;
		}
	}
	for (int i = k; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[i])
				swap(a[i], a[j]);
}

void output(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}

void CauE(int a[], int n) {
	for (int i = 0; i < n-1; i++) {
		if (a[i] < 0)
			for (int j = i; j < n; j++)
				if (a[j] < 0)
					if (a[j] < a[i])
						swap(a[i], a[j]);
	}
	for (int i = 0; i < n - 1; i++) {
		if (a[i] >= 0)
			for (int j = i; j < n; j++)
				if (a[j] >= 0)
					if (a[j] > a[i])
						swap(a[i], a[j]);
	}
}

int main() {
	int a[50];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	//CauA(a, n);
	//CauB(a, n);
	//CauC(a, n);
	//CauD(a, n);
	CauE(a, n);
	output(a, n);
	return 0;
}