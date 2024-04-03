#include<iostream>
using namespace std;

bool LinearSerch(int a[], int n, int x) {
	for(int i=0;i<n;i++)
		if (a[i] == x) {
			return true;
		}
	return false;
}
bool BinarySearch(int a[], int n, int x) {
	int l = 0;
	int r = n-1;
	while (l <= r) {
		int m = (l + r) / 2;
		if (m == x)
			return true;
		else if (a[m] < x)
			l = m + 1;
		else
			r = m - 1;
	}
	return false;
}
void InterchangeSort(int a[], int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j])
				swap(a[i], a[j]);
}

int a[10000];
int main() {
	srand(time(NULL));
	for (int i = 0; i < 10000; i++) {
		a[i] = rand();
	}
	clock_t st1, ed1;
	double duration1;
	clock_t st2, ed2;
	double duration2;
	int x;
	cin >> x;
	st1 = clock();
	LinearSerch(a, 10000, x);
	ed1 = clock();
	duration1=(double)(ed1 - st1) / CLOCKS_PER_SEC;
	InterchangeSort(a, 10000);
	st2 = clock();
	BinarySearch(a, 10000, x);
	ed2 = clock();
	duration2 = (double)(ed2 - st2) / CLOCKS_PER_SEC;

	cout << "thoi gian tim kiem cua LinearSearch: " << duration1 << endl;
	cout << "thoi gian tim kiem cua BinarySearch: " << duration2;
	return 0;
}