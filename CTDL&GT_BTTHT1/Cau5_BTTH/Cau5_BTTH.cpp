#include<iostream>
#include<string>
#include<stack>
#include<time.h>
using namespace std;

int patitionLeft(int a[], int l, int r) {
	int p = a[l];
	int i = r + 1;
	for (int j = r; j > l; j--) {
		if (p < a[j]) {
			i--;
			swap(a[i], a[j]);
		}
	}
	swap(a[l], a[i - 1]);
	return i - 1;
}

void QuickSortLeft(int a[], int l, int r) {
	stack<int> Sl;
	stack<int> Sr;
	Sl.push(l);
	Sr.push(r);
	while (!Sl.empty()) {
		l = Sl.top(), Sl.pop();
		r = Sr.top(); Sr.pop();
		if (l < r) {
			int pi = patitionLeft(a, l, r);
			Sl.push(l); Sr.push(pi - 1);
			Sl.push(pi+1); Sr.push(r);
		}
	}
}

void QuickSortMid(int a[], int l, int r) {
	stack<int> Sl;
	stack<int> Sr;
	Sl.push(l);
	Sr.push(r);
	while (!Sl.empty()) {
		l = Sl.top(), Sl.pop();
		r = Sr.top(); Sr.pop();
		int p = a[(l + r) / 2];
		int i = l, j = r;
		while (i < j) {
			while (a[i] < p)
				i++;
			while (a[j] > p)
				j--;
			if (i <= j) {
				swap(a[i], a[j]);
				j--;
				i++;
			}
		}
		if (l < j) {
			Sl.push(l);
			Sr.push(j);
		}
		if (i < r) {
			Sl.push(i);
			Sr.push(r);
		}
	}
}
int partitionRight(int a[], int l, int r) {
	int p = a[r];
	int i = l - 1;
	for (int j = l; j < r; j++) {
		if (a[j] < p) {
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[i + 1], a[r]);
	return i + 1;
}
void QuickSortRight(int a[], int l, int r) {
	stack<int> sl;
	stack<int> sr;
	sl.push(l);
	sr.push(r);
	while (!sl.empty()) {
		l = sl.top(), sl.pop();
		r = sr.top(); sr.pop();
		if (l < r) {
			int pi = partitionRight(a, l, r);
			sl.push(l); sr.push(pi - 1);
			sl.push(pi+1); sr.push(r);
		}
	}
}

void Xuat(int a[], int n) {
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}
void Nhap(int a[], int& n) {
	srand(5);
	for (int i = 0; i < n; i++) {
		a[i] = rand() % (50000 + 1);
	}
}

int main()
{
	int n;
	cin >> n;
	int* a = new int[100000];
	int* b = new int[100000];
	int* c = new int[100000];

	clock_t startR, endR;
	double durationR;
	clock_t startL, endL;
	double durationL;
	clock_t startM, endM;
	double durationM;

	Nhap(a, n);
	startR = clock();
	QuickSortRight(a, 0, n);
	endR = clock();
	durationR = (double)(endR - startR) / CLOCKS_PER_SEC;
	delete[] a;

	Nhap(b, n);
	startM = clock();
	QuickSortMid(b, 0, n);
	endM = clock();
	durationM = (double)(endM - startM) / CLOCKS_PER_SEC;
	delete[] b;

	Nhap(c, n);
	startL = clock();
	QuickSortLeft(c, 0, n);
	endL = clock();
	durationL = (double)(endL - startL) / CLOCKS_PER_SEC;
	delete[] c;

	cout << "Thoi gian xu ly chon pivot la phan tu dau tien: " << durationL << endl;
	cout << "Thoi gian xu ly chon pivot la phan tu o giua: " << durationM << endl;
	cout << "Thoi gian xu ly chon pivot la phan tu cuoi cung: " << durationR;
	return 0;
}

